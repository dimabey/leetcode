#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <unordered_set>
#include <vector>

class Solution
{
public:
    bool isHappy(int n)
    {
        int hare = n;
        int turtle = n;
        bool turtle_flag = false;
        while (hare != 1)
        {
            hare = getNext(hare);
            if (turtle_flag)
                turtle = getNext(turtle);
            turtle_flag = !turtle_flag;
            if (hare == turtle)
                return false;
        }
        return true;
    }

    int getNext(int n)
    {
        int next_num = 0;
        while (n != 0)
        {
            next_num += (n % 10) * (n % 10);
            n = (n - n % 10) / 10;
        }
        return next_num;
    }
};

int main()
{
    int test = 19;
    Solution solution;
    std::cout << solution.isHappy(test) << std::endl;
}