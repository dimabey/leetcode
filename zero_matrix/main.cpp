#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class Solution
{
public:
    std::vector<std::vector<int>> zeroMatrix(std::vector<std::vector<int>>& mat)
    {
        std::unordered_set<int> marked_col;
        std::unordered_set<int> marked_row;
        for (size_t i = 0; i < mat.size(); i++)
        {
            for (size_t j = 0; j < mat.back().size(); j++)
            {
                if (mat[i][j] == 0)
                {
                    marked_row.emplace(i);
                    marked_col.emplace(j);
                }
            }
        }

        for (size_t i = 0; i < mat.size(); i++)
        {
            for (size_t j = 0; j < mat.back().size(); j++)
            {
                if (marked_row.contains(i) || marked_col.contains(j))
                {
                    mat[i][j] = 0;
                }
            }
        }
        return mat;
    }
};

int main()
{
    std::vector<std::vector<int>> test{
        {1, 2, 3, 4}, {0, 6, 7, 8}, {9, 10, 11, 0}};
    Solution solution;
    solution.zeroMatrix(test);
}