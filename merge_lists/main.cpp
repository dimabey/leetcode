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
    ListNode* mergeKLists(std::vector<ListNode*>& lists) {}
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
    ListNode node_14(2);
    ListNode node_13(2, &node_14);
    ListNode node_12(2, &node_13);
    ListNode node_11(1, &node_12);

    ListNode node_23(3);
    ListNode node_22(1, &node_23);
    ListNode node_21(1, &node_22);

    ListNode node_33(3);
    ListNode node_32(1, &node_33);
    ListNode node_31(1, &node_32);

    Solution solution;

    std::cout << listToStr(solution.mergeTwoLists(
                     std::vector{&node_11, &node_21, &node31}))
              << std::endl;
}