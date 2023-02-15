#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

// Given 2 strings write a method to decide if one is permutation of other

class Solution
{
public:
    bool checkPermutation(std::string& s1, std::string& s2)
    {
        if (s1.size() != s2.size())
            return false;

        std::vector<int> freq(26, 0);
        for (auto it1 = s1.begin(), it2 = s2.begin(); it1 != s1.end();
             it1++, it2++)
        {
            freq[*it1 - 'a']++;
            freq[*it2 - 'a']--;
        }

        return std::all_of(freq.begin(), freq.end(),
                           [](int i) { return i == 0; });
    }

    // go through 2 strings in parallel
    // vals in string 1 increments
    // vals in string 2 decrement
    // check if all values in map is 0
};

int main()
{
    std::string test1{"baa"};
    std::string test2{"aba"};
    Solution solution;
    std::cout << solution.checkPermutation(test1, test2) << std::endl;
}