#include <iostream>
#include <map>
#include <queue>
#include <sstream>
#include <vector>

class Solution
{
public:
    int guessNumber(int n)
    {
        int res = 0;
        int check;
        int low = 1;
        int high = n;
        while (true)
        {
            res = low / 2 + high / 2;
            check = guess(res);
            if (check > 0)
            {
                low = res + 1;
            }

            if (check < 0)
            {
                high = res - 1;
            }

            if (check == 0)
                return res;
        }
    }

    int guess(int num)
    {
        if (num < pick)
            return 1;
        if (num > pick)
            return -1;
        return 0;
    }

    int pick = 2;
};

int main()
{
    int n = 6;
    Solution solution;
    std::cout << solution.guessNumber(n) << std::endl;
}