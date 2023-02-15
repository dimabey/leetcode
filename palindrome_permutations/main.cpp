#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

// Check if it is a permutation of palindrome

class Solution
{
public:
    bool isPermutation(std::string& s)
    {
        std::vector<int> freq(26, 0);
        for (auto c : s)
        {
            char curr = std::tolower(c);
            if ('a' <= curr && curr <= 'z')
                freq[std::tolower(c) - 'a']++;
        }

        bool odd = std::accumulate(freq.begin(), freq.end(), 0) % 2 != 0;
        for (auto val : freq)
        {
            if (val % 2 == 0)
                continue;
            if (odd)
                odd = false;
            else
                return false;
        }
        return true;
    }
};

int main()
{
    std::string test{"ttatt2131"};
    Solution solution;
    std::cout << solution.isPermutation(test) << std::endl;
}