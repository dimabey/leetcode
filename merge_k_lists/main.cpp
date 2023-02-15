#include <iostream>
#include <map>
#include <queue>
#include <sstream>
#include <vector>

struct ListNode
{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode* mergeKLists(std::vector<ListNode*>& lists)
    {
        auto init = ListNode();
        auto* tail = &init;
        auto* head = &init;

        auto compare = [](ListNode* a, ListNode* b) { return a->val > b->val; };
        std::priority_queue<ListNode*, std::vector<ListNode*>,
                            decltype(compare)>
            pq(lists.begin(), lists.end());

        while (!pq.empty())
        {
            tail->next = pq.top();
            tail = tail->next;
            pq.pop();
            if (tail->next)
                pq.push(tail->next);
        }

        return head->next;
    }
};

std::string listToStr(ListNode* root)
{
    std::stringstream oss;
    while (root != nullptr)
    {
        oss << root->val << ", ";
        root = root->next;
    }
    return oss.str();
}

int main()
{
    ListNode node_14(14);
    ListNode node_13(13, &node_14);
    ListNode node_12(12, &node_13);
    ListNode node_11(11, &node_12);

    ListNode node_23(23);
    ListNode node_22(22, &node_23);
    ListNode node_21(21, &node_22);

    ListNode node_33(33);
    ListNode node_32(32, &node_33);
    ListNode node_31(31, &node_32);

    std::vector<ListNode*> test{&node_11, &node_21, &node_31};

    Solution solution;
    std::cout << listToStr(solution.mergeKLists(test)) << std::endl;
}