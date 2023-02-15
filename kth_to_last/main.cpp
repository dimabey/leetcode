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
    ListNode* kthEl(ListNode* root, int k)
    {
        auto* tail = root;
        auto* kth = root;
        for (size_t i = 0; i < k.; i++)
        {
            tail = tail->next;
        }

        while (tail)
        {
            kth = kth->next;
            tail = tail->next;
        }
        return kth;
    }
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
    // last element
    ListNode node_16(6);
    ListNode node_15(5, &node_16);
    ListNode node_14(4, &node_15);
    ListNode node_13(3, &node_14);
    ListNode node_12(2, &node_13);
    ListNode node_11(1, &node_12);

    Solution solution;

    std::cout << listToStr(&node_11) << " | "
              << solution.kthEl(&node_11, 3)->val << std::endl;
}