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
    bool isUnique(std::string& s)
    {
        std::vector<bool> ltrs(26, false);
        for (auto c : s)
        {
            c = std::tolower(c);
            if (ltrs[c - 'a'])
                return false;
            ltrs[c - 'a'] = true;
        }
        return true;
    }

    bool isUniqueBit(std::string& s)
    {
        std::vector<bool> ltrs(26, false);
        for (auto c : s)
        {
            c = std::tolower(c);
            if (ltrs[c - 'a'])
                return false;
            ltrs[c - 'a'] = true;
        }
        return true;
    }

    // array of possible char so that arr[char] = false
    // go through string and check flags in arr
    // if found repeating
    // return false
};

int main()
{
    std::string test{"ABCDEFGHII"};
    Solution solution;
    std::cout << solution.isUniqueBit(test) << std::endl;
}