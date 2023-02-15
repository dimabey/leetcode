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
    ListNode* partition(ListNode* root, int pivot)
    {
        ListNode btemp;
        ListNode stemp;
        auto* stail = &stemp;
        auto* shead = &stemp;
        auto* btail = &btemp;
        auto* bhead = &btemp;
        auto* runner = root;

        while (runner)
        {
            if (runner->val >= pivot)
            {
                btail->next = runner;
                btail = btail->next;
            }
            else
            {
                stail->next = runner;
                stail = stail->next;
            }
            runner = runner->next;
        }
        btail->next = nullptr;
        stail->next = bhead->next;
        return shead->next;
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
    ListNode node_16(1);
    ListNode node_15(2, &node_16);
    ListNode node_14(10, &node_15);
    ListNode node_13(8, &node_14);
    ListNode node_12(5, &node_13);
    ListNode node_11(3, &node_12);

    Solution solution;
    solution.partition(&node_16, 5);
    std::cout << listToStr(&node_11) << std::endl;
}