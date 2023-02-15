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
    std::string compress(std::string& s)
    {
        if (s.empty())
            return {};

        std::string res{s[0], '0'};
        for (auto it1 = s.begin(); it1 != s.end() && res.size() < s.size();
             it1++)
        {
            if (*it1 != *(res.rbegin() + 1))
            {
                res.push_back(*it1);
                res.push_back('1');
            }
            else
                *res.rbegin() += 1;
        }
        return (res.size() < s.size()) ? res : s;
    }
};

int main()
{
    std::string test{"aaaabbbaa"};
    Solution solution;
    std::cout << solution.compress(test) << std::endl;
}