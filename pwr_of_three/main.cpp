#include <iostream>
#include <map>
#include <queue>
#include <sstream>
#include <vector>

class Solution
{
public:
    bool isPowerOfThree(int n) { return 4052555153018976267 % n == 0 && n > 0; }
};

int main()
{
    int test = -1;
    Solution solution;
    std::cout << solution.isPowerOfThree(test) << std::endl;
}