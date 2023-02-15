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
    ListNode* reverseList(ListNode* head)
    {
        ListNode* tail = nullptr;
        ListNode* temp = head;

        while (head)
        {
            temp = temp->next;
            head->next = tail;
            tail = head;
            head = temp;
        }
        return tail;
    }
};

int main()
{
    ListNode node4(3);
    ListNode node3(2, &node4);
    ListNode node2(1, &node3);
    ListNode node1(0, &node2);
    Solution solution;
    std::cout << solution.reverseList(&node1) << std::endl;
}