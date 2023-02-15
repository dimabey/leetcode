#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

// 2D Directed Graph Problem
// Aims:
//   * Implement a simple graph structure
//   * Implement some algorithms using the new structure
// Complete tasks 1-5. You can add extra functions, classes, exceptions as you
// wish. Uncomment the relevant blocks in `main` to run the code for each
// question.

struct Node
{
    // The unique identifier for this node
    std::string id;
    // The node's position in a global coordinate frame
    std::array<double, 2> position;
};
bool operator<(const Node& lhs, const Node& rhs) { return lhs.id < rhs.id; }

struct Edge
{
    // The unique identifier for this edge
    std::string id;
    // This is a directed edge from a source node to a target node
    std::string source_node;
    std::string target_node;
};

class DirectedGraph
{
public:
    // Access to the underlying graph
    const auto& graph() const { return graph_; }

    // 1. Implement node insertion.
    // Nodes should have unique ids and can not be inserted multiple times.
    void AddNode(const Node& node)
    {
        if (nodeExists(node))
            throw std::invalid_argument("Node with such ID already exists");

        graph_[node];
    }

    // 2. Implement edge insertion.
    // Edges should have unique ids and can not be insertedinserter multiple
    // times. The nodes that an edge references must already be present in
    // the graph. The graph may only contain one directed edge from a source
    // to a target.
    void AddEdge(const Edge& edge)
    {
        if (edgeExists(edge))
            throw std::invalid_argument("Edge with such ID already exists");

        auto iterator = std::find_if(
            graph_.begin(), graph_.end(), [&edge](const auto& map) {
                return map.first.id == edge.source_node;
            });
        iterator->second.push_back(edge);

        iterator = std::find_if(graph_.begin(), graph_.end(),
                                [&edge](const auto& map) {
                                    return map.first.id == edge.target_node;
                                });
        iterator->second.push_back(edge);
    }

private:
    bool nodeExists(const Node& node)
    {
        auto iterator = std::find_if(
            graph_.begin(), graph_.end(),
            [&node](const auto& map) { return map.first.id == node.id; });
        return iterator != graph_.end();
    }

    bool edgeExists(const Edge& edge)
    {
        auto search_function = [&edge](const auto& map) {
            auto tested_edges = map.second;
            for (const auto& tested_edge : tested_edges)
                if (tested_edge.id == edge.id)
                    return true;
            return false;
        };

        auto iterator =
            std::find_if(graph_.begin(), graph_.end(), search_function);
        return iterator != graph_.end();
    }

    // Nodes and their adjacent edges
    std::map<Node, std::vector<Edge>> graph_;
};

bool isValidNode(const DirectedGraph& graph, const Node& node)
{
    return graph.graph().find(node) != graph.graph().end();
}

// 3. Returno all the in-edges for some node. If the node is invalid then you
// should throw an exception.
std::vector<Edge> InEdges(const DirectedGraph& graph, const Node& node)
{
    if (!isValidNode(graph, node))
        throw std::invalid_argument("No such node exsists");

    auto edges = graph.graph().find(node);
    std::vector<Edge> res;
    for (const auto& edge : edges->second)
        if (edge.target_node == node.id)
            res.push_back(edge);
    return res;
};

// 4. Return all the out-edges for some node. If the node is invalid then
// you should throw an exception.
std::vector<Edge> OutEdges(const DirectedGraph& graph, const Node& node)
{
    if (!isValidNode(graph, node))
        throw std::invalid_argument("No such node exsists");

    auto edges = graph.graph().find(node);
    std::vector<Edge> res;
    for (const auto& edge : edges->second)
        if (edge.source_node == node.id)
            res.push_back(edge);
    return res;
};

// 5. Search for all nodes that are reachable from `start` node without
// travelling more than `radius` (euclidean distance) from the start node.
// Nodes outside this radius should not be expanded. You may decide how to
// return the results. If the start node is invalid then you should throw an
// exception. You should decide on what a valid radius is and validate the
// input appropriately.
struct RadiusSearch
{
    // NOTE also: It should be streamable to ostream.
    Node start_node;
    double limit_radius;
    std::set<Node> reachable_nodes;
};

std::ostream& operator<<(std::ostream& os, const RadiusSearch& search)
{
    os << "Nodes reachable from " << search.start_node.id << " under "
       << search.limit_radius << ":\n";
    for (const auto& node : search.reachable_nodes)
    {
        os << node.id << "\n";
    }

    return os;
}

bool isValidRadius(const double radius) { return (radius >= 0); }

bool isValidStartNode(const DirectedGraph& graph, const Node& node)
{
    return graph.graph().find(node) != graph.graph().end();
}

const Node& findNodeById(const DirectedGraph& graph, const std::string& id)
{
    auto iterator =
        std::find_if(graph.graph().begin(), graph.graph().end(),
                     [&id](auto& map) { return map.first.id == id; });
    return iterator->first;
}

double getDistance(const Node& node1, const Node& node2)
{
    return sqrt(pow(node2.position[0] - node1.position[0], 2) +
                pow(node2.position[1] - node1.position[1], 2));
}

RadiusSearch RadiusLimitedSearch(const DirectedGraph& graph, const Node& start,
                                 const double radius)
{
    if (!isValidRadius(radius))
        throw std::invalid_argument("Invalid search radius");
    if (!isValidStartNode(graph, start))
        throw std::invalid_argument("No such node exsists");

    RadiusSearch search({start, radius, {start}});
    std::set<Node> frontier({start});
    while (!frontier.empty())
    {
        auto current_frontier_node = *frontier.begin();
        auto out_edges = OutEdges(graph, current_frontier_node);
        for (const auto& out_edge : out_edges)
        {
            const auto& checked_node =
                findNodeById(graph, out_edge.target_node);

            auto distance_from_start = getDistance(start, checked_node);
            if (distance_from_start > radius)
                continue;

            if (search.reachable_nodes.find(checked_node) ==
                search.reachable_nodes.end())
            {
                search.reachable_nodes.insert(checked_node);
                frontier.insert(checked_node);
            }
        }
        frontier.erase(current_frontier_node);
    }

    return search;
};

int main()
{
    // Some made up places in a made up world
    const Node oxford{"oxford", {0, 0}};
    const Node culham{"culham", {-1, 0}};
    const Node london{"london", {-5, 5}};
    const Node southampton{"southampton", {-10, 0}};
    const Node manchester{"manchester", {20, -5}};
    const Node birmingham{"birmingham", {5, -5}};

    // Some made up routes between made up places
    const Edge m40_south{"m40_south", oxford.id, london.id};
    const Edge m40_north{"m40_north", london.id, oxford.id};
    const Edge a34{"a34", oxford.id, southampton.id};
    const Edge small_train{"small_train", oxford.id, culham.id};
    const Edge big_train_north{"big_train_north", oxford.id, manchester.id};
    const Edge big_train_south{"big_train_south", manchester.id, oxford.id};
    const Edge m6_south{"m6_south", manchester.id, birmingham.id};

    DirectedGraph graph;

    std::cout << "Answers:\n";

    // Problem 1.
    graph.AddNode(oxford);
    graph.AddNode(culham);
    graph.AddNode(london);
    graph.AddNode(southampton);
    graph.AddNode(manchester);

    // Problem 2.
    graph.AddEdge(m40_south);
    graph.AddEdge(m40_north);
    graph.AddEdge(a34);
    graph.AddEdge(small_train);
    graph.AddEdge(big_train_north);
    graph.AddEdge(big_train_south);

    // Problem 3.
    const auto inbound_to_oxford = InEdges(graph, oxford);
    std::cout << "There are " << inbound_to_oxford.size()
              << " routes into Oxford\n";

    // Problem 4.
    const auto outbound_from_oxford = OutEdges(graph, oxford);
    std::cout << "There are " << outbound_from_oxford.size()
              << " routes from Oxford\n";

    // Problem 5.
    const auto ten_from_oxford = RadiusLimitedSearch(graph, oxford, 10);
    std::cout << ten_from_oxford << "\n";

    return 0;
}
