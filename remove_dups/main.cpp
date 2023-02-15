#include <iostream>
#include <map>
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
    ListNode* remDups(ListNode* root)
    {
        auto* head = root;
        auto* tail = root;
        while (tail)
        {
            auto* runner = tail;
            while (runner)
            {
                if (runner->next && runner->next->val == tail->val)
                {
                    runner->next = runner->next->next;
                }
                else
                    runner = runner->next;
            }
            tail = tail->next;
        }
        return head;
    }

    ListNode* remDupsPlus(ListNode* root) {}
};

std::string listToStr(ListNode* root)
{
    std::stringstream oss;
    while (root)
    {
        oss << root->val << ", ";
        root = root->next;
    }
    return oss.str();
}

int main()
{
    ListNode node_16(1);
    ListNode node_15(1, &node_16);
    ListNode node_14(1, &node_15);
    ListNode node_13(1, &node_14);
    ListNode node_12(1, &node_13);
    ListNode node_11(1, &node_12);

    Solution solution;

    std::cout << listToStr(&node_11) << " | "
              << listToStr(solution.remDups(&node_11)) << std::endl;
}