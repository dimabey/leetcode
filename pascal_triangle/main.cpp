#include <iostream>
#include <map>
#include <queue>
#include <sstream>
#include <string>
#include <vector>

class Solution
{
public:
    std::vector<int> getRow(int rowIndex)
    {
        std::vector<int> res(rowIndex + 1, 1);
        for (size_t i = 2; i < res.size(); i++)
            for (size_t j = i - 1; j > 0; j--)
                res[j] += res[j - 1];
        return res;
    }
};

int main()
{
    int test = 4;
    Solution solution;
    std::cout << solution.getRow(test)[2] << std::endl;
}