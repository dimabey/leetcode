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
    bool checkSubstring(std::string& rot, std::string& ss)
    {
        if (ss.size() > rot.size() || rot.empty() || ss.empty())
            return false;
        auto doubled = rot + rot;
        return isSubstring(doubled, ss);
    }

private:
    bool isSubstring(std::string& s1, std::string& s2)
    {
        size_t target_hash = 0;
        for (auto c : s2)
        {
            target_hash += c - 'a';
        }

        size_t crnt_hash = 0;
        for (size_t i = s1.size() - 1; i > 0; i--)
        {
            crnt_hash += s1[i] - 'a';
            if (crnt_hash == target_hash &&
                compLtr(s1.substr(i, s2.size()), s2))
            {
                return true;
            }
            if (s1.size() - i >= s2.size())
            {
                crnt_hash -= s1[i + s2.size() - 1] - 'a';
            }
        }
        return false;
    }

    bool compLtr(std::string s1, std::string s2)
    {
        for (auto it1 = s1.begin(), it2 = s2.begin();
             it1 != s1.end() && it2 != s2.end(); it1++, it2++)
        {
            if (*it1 != *it2)
                return false;
        }
        return true;
    }
};

int main()
{
    std::string test1{"waterbottle"};
    std::string test2{"erbottlewat"};
    Solution solution;
    std::cout << solution.checkSubstring(test2, test1) << std::endl;
}