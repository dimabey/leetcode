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
    std::vector<int> intersect(std::string& s, std::string& ss)
    {
        if (s.empty() || ss.empty() || ss.size() > s.size())
            return {{}};

        int target_hash = 0;
        for (auto c : ss)
            target_hash += c;

        int crnt_hash = 0;
        std::vector<int> res;
        for (int i = 0; i < s.size(); i++)
        {
            crnt_hash += s[i];
            if (crnt_hash == target_hash &&
                sameString(s.substr(i - ss.size() + 1, ss.size()), ss))
                res.push_back(i - ss.size() + 1);
            if ((int)(i - ss.size() + 1) >= 0)
                crnt_hash -= s[i - ss.size() + 1];
        }
        return res;
    }

    bool sameString(std::string s1, std::string s2)
    {
        for (auto it1 = s1.begin(), it2 = s2.begin(); it1 != s1.end();
             it1++, it2++)
        {
            if (*it1 != *it2)
                return false;
        }
        return true;
    }
    // compute target has from orig string
    // compute hash for each substring
    // compare with target hash
    // append to res
};

int main()
{
    std::string test{"ABABBBBCBCBFDACAACBBABBABAC"};
    std::string target{"ABA"};
    Solution solution;
    solution.intersect(test, target);
}