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
    void deleteInside(ListNode* node)
    {
        node->val = node->next->val;
        node->next = node->next->next;
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
    solution.deleteInside(&node_13);
    std::cout << listToStr(&node_11) << std::endl;
}