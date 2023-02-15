#include <iostream>
#include <map>
#include <queue>
#include <sstream>
#include <string>
#include <vector>

class Solution
{
public:
    void countXY(std::string::iterator begin, std::string::iterator end,
                 std::pair<int, int>& xy)
    {
        for (auto it = begin; it != end; it++)
        {
            if (*it == 'x')
                xy.first++;
            else if (*it == 'y')
                xy.second++;
        }
    }

    bool isValidPart(std::pair<int, int>& xy)
    {
        return (xy.first > 0 && xy.second > 0) ||
               (xy.first == 0 && xy.second == 0);
    }

    void rebalance(std::string::iterator it, std::pair<int, int>& xy_left,
                   std::pair<int, int>& xy_right)
    {
        if (*it == 'x')
        {
            xy_left.first++;
            xy_right.first--;
        }
        else if (*it == 'y')
        {
            xy_left.second++;
            xy_right.second--;
        }
    }

    int solution(std::string& S)
    {
        std::pair<int, int> xy_left;
        countXY(S.begin(), S.begin() + 1, xy_left);
        std::pair<int, int> xy_right;
        countXY(S.begin() + 1, S.end(), xy_right);

        int valid_splits = 0;
        for (auto separator = S.begin() + 1; separator != S.end(); separator++)
        {
            if (isValidPart(xy_left) || isValidPart(xy_right))
                valid_splits++;

            rebalance(separator, xy_left, xy_right);
        }
        return valid_splits;
    }
};

int main()
{
    std::string test{"ayxbx"};
    Solution solution;
    std::cout << solution.solution(test) << std::endl;
}