#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

// Check if strings differ by 1 letter
// pale ple  true
// pale pale true
// pale pales true
// apale pale true
// pale pael false
// "" "p" true

class Solution
{
public:
    bool oneAway(std::string& s1, std::string& s2)
    {
        if (s1.empty() || s2.empty())
            return std::abs(static_cast<int>(s1.size() - s2.size())) <= 1;

        if (std::abs(static_cast<int>(s1.size() - s2.size())) > 1)
            return false;

        int diff = 0;
        for (auto it1 = s1.begin(), it2 = s2.begin();
             it1 != s1.end() || it2 != s2.end() || diff > 1;)
        {
            if (*it1 != *it2)
            {
                diff++;
                if (s1.size() < s2.size())
                    it2++;
                else if (s1.size() > s2.size())
                    it1++;
                else
                {
                    it1++;
                    it2++;
                }
                continue;
            }
            it1++;
            it2++;
        }
        return diff <= 1;
    }
};

int main()
{
    std::string test1{""};
    std::string test2{""};
    Solution solution;
    std::cout << solution.oneAway(test1, test2) << std::endl;
}