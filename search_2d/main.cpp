#include <iostream>
#include <map>
#include <queue>
#include <sstream>
#include <vector>

class Solution
{
public:
    bool searchMatrix(std::vector<std::vector<int>>& matrix, int target)
    {
        if (matrix.empty() || matrix[0].empty())
            return false;

        auto l_it = matrix.begin();
        auto h_it = matrix.end() - 1;
        auto mid = l_it + (h_it - l_it) / 2;
        while (mid != h_it &&
               !(*mid->begin() <= target && target <= *(mid->end() - 1)) &&
               l_it <= h_it)
        {
            if (*mid->begin() > target)
                h_it = mid - 1;
            else
                l_it = mid + 1;
            mid = l_it + (h_it - l_it) / 2;
        }

        auto i_l_it = mid->begin();
        auto i_h_it = mid->end() - 1;
        auto i_mid = i_l_it + (i_h_it - i_l_it) / 2;
        while (i_mid != i_h_it && *i_mid != target && i_l_it <= i_h_it)
        {
            if (*i_mid > target)
                i_h_it = i_mid - 1;
            else
                i_l_it = i_mid + 1;
            i_mid = i_l_it + (i_h_it - i_l_it) / 2;
        }
        return *i_mid == target;
    }
};

int main()
{
    std::vector<std::vector<int>> test{{1}, {3}};
    int target = 0;
    Solution solution;
    std::cout << solution.searchMatrix(test, target) << std::endl;
}