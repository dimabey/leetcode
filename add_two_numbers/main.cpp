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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        auto* head = new ListNode(-1);
        auto* tail = head;
        int remainder = 0;
        while (l1 || l2 || remainder != 0)
        {
            int val = getVal(l1, l2, remainder);
            tail->next = new ListNode(val % 10);
            remainder = (val - val % 10) / 10;
            if (l1)
                l1 = l1->next;
            if (l2)
                l2 = l2->next;
            tail = tail->next;
        }
        return head->next;
    }

    int getVal(ListNode* l1, ListNode* l2, int remainder)
    {
        return ((l1) ? l1->val : 0) + ((l2) ? l2->val : 0) + remainder;
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
    ListNode node_14(9);
    ListNode node_13(9, &node_14);
    ListNode node_12(9, &node_13);
    ListNode node_11(9, &node_12);

    ListNode node_23(9);
    ListNode node_22(9, &node_23);
    ListNode node_21(9, &node_22);

    Solution solution;
    std::cout << listToStr(solution.addTwoNumbers(&node_11, &node_21))
              << std::endl;
}