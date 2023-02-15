#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

class Solution
{
public:
    double myPow(double x, int n)
    {
        double res = 1;
        double acc = x;
        int pow = n;
        while (pow != 0)
        {
            if (pow % 2 != 0)
                res *= acc;
            pow /= 2;
            if (pow != 0)
                acc *= acc;
        }
        return (n > 0) ? res : 1 / res;
    };
};

int main()
{
    double test = 2.1;
    int pow = 2;
    Solution solution;
    std::cout << solution.myPow(test, pow) << " kek " << std::endl;
}