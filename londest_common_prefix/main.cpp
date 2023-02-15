#include <iostream>
#include <map>
#include <queue>
#include <sstream>
#include <string>
#include <vector>

class Solution
{
public:
    std::string longestCommonPrefix(std::vector<std::string>& strs)
    {
        std::string res;
        for (size_t i = 0;; i++)
        {
            for (size_t j = 0; j < strs.size(); j++)
                if (i >= strs[j].size() || strs[j][i] != strs[0][i])
                    goto end;
            res.push_back(strs[0][i]);
        }
    end:
        return res;
    }
};

int main()
{
    std::vector<std::string> test{""};
    Solution solution;
    std::cout << solution.longestCommonPrefix(test) << std::endl;
}