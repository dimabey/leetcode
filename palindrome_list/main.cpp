#include <array>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <unordered_set>
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
    bool isPalindrome(ListNode* head)
    {
        ListNode* tail = head;
        int cntr = 0;
        while (tail)
        {
            tail = tail->next;
            cntr++;
        }

        tail = nullptr;
        ListNode* temp = head;

        for (size_t i = 0; i < cntr / 2; i++)
        {
            temp = temp->next;
            head->next = tail;
            tail = head;
            head = temp;
        }

        if (cntr % 2 != 0)
            head = head->next;
        while (tail && head)
        {
            if (tail->val != head->val)
                return false;
            tail = tail->next;
            head = head->next;
        }
        return true;
    }
};

int main()
{
    ListNode node3(0);
    ListNode node2(1, &node3);
    ListNode node1(0, &node2);
    Solution solution;
    std::cout << solution.isPalindrome(&node1) << std::endl;
}