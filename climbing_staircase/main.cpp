#include <iostream>
#include <map>
#include <queue>
#include <sstream>
#include <vector>

class Solution
{
public:
    int climbStairs(int n)
    {
        std::queue<int> q_f;
        q_f.push(0);
        q_f.push(1);
        for (int i = 2; i < n + 2; i++)
        {
            q_f.push(q_f.front());
            q_f.pop();
            q_f.back() += q_f.front();
        }
        return q_f.back();
    }
};

int main()
{
    int test = 4;
    Solution solution;
    std::cout << solution.climbStairs(test) << std::endl;
}