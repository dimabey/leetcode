#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

// Check if it is a permutation of palindrome

class Solution
{
public:
    size_t maxNeighbourDistance(std::vector<int> row)
    {
        size_t max_dist = 0;
        for (size_t first = 0, second = 0; first < row.size(); first++)
        {
            if (row[first])
            {
                if (row[second])
                    max_dist = std::max(max_dist, (first - second) / 2);
                else
                    max_dist = std::max(max_dist, first - second);
                second = first;
            }
            else if (first == row.size() - 1)
            {
                max_dist = std::max(max_dist, first - second);
                second = first;
            }
        }
        return max_dist;
    }
};

int main()
{
    std::vector<int> test{0, 1};
    Solution solution;
    std::cout << solution.maxNeighbourDistance(test) << std::endl;
}