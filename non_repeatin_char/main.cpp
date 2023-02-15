#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <unordered_map>
#include <vector>

class Solution
{
public:
    int firstUniqChar(std::string s)
    {
        std::vector<int> checks(26, 0);
        for (auto c : s)
            checks[c - 'a']++;

        for (size_t i = 0; i < s.size(); i++)
            if (checks[s[i] - 'a'] == 1)
                return i;
        return -1;
    }
};

int main()
{
    std::string test = "tuvwxyzabcdefghijklmnopqrs";
    Solution solution;
    std::cout << solution.firstUniqChar(test) << std::endl;
}