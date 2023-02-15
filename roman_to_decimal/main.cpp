#include <algorithm>
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
    std::unordered_map<char, int> dictionary{{'I', 1},   {'V', 5},   {'X', 10},
                                             {'L', 50},  {'C', 100}, {'D', 500},
                                             {'M', 1000}};

    int romanToInt(std::string s)
    {
        int res = 0;
        for (auto it = s.rbegin(); it != s.rend(); it++)
        {
            if ((*it == 'I' && (*(it - 1) == 'V' || *(it - 1) == 'X')) ||
                (*it == 'X' && (*(it - 1) == 'L' || *(it - 1) == 'C')) ||
                (*it == 'C' && (*(it - 1) == 'D' || *(it - 1) == 'M')))
                res -= dictionary[*it];
            else
                res += dictionary[*it];
        }
        return res;
    }
};

int main()
{
    std::string test{"MCMXCIV"};
    Solution solution;
    std::cout << test << " : " << solution.romanToInt(test) << std::endl;
}