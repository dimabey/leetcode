#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode* detectCycle(ListNode* head)
    {
        auto* tortoise = head;
        auto* hare = head;

        while (hare && hare->next)
        {
            hare = hare->next->next;
            tortoise = tortoise->next;

            if (hare == tortoise)
                break;
        }

        if (!hare || !hare->next)
            return nullptr;

        hare = head;
        while (hare != tortoise)
        {
            hare = hare->next;
            tortoise = tortoise->next;
        }

        return hare;
    }
};

int main()
{
    ListNode node4(4);
    ListNode node3(3);
    ListNode node2(2);
    ListNode node1(1);
    node4.next = &node2;
    node3.next = &node4;
    node2.next = &node3;
    // node2.next = nullptr;
    node1.next = &node2;

    Solution solution;
    std::cout << solution.detectCycle(&node1)->val << std::endl;
}