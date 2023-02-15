#include <iostream>
#include <map>
#include <sstream>
#include <vector>

struct ListNode
{
    char val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(char x) : val(x), next(nullptr) {}
    ListNode(char x, ListNode* next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode* isPalindrome(ListNode* root) {}
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
    ListNode node_16('a');
    ListNode node_15('t', &node_16);
    ListNode node_14('u', &node_15);
    ListNode node_13('u', &node_14);
    ListNode node_12('t', &node_13);
    ListNode node_11('a', &node_12);

    Solution solution;
    std::cout << solution.isPalindrome(&node_11) << std::endl;
}