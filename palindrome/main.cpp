#include <array>
#include <cctype>
#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <unordered_set>
#include <vector>

class Solution
{
public:
    bool isPalindrome(std::string& s)
    {
        auto f_it = s.begin();
        auto b_it = s.rbegin();
        while (std::distance(f_it, b_it.base()) > 0)
        {
            if (!checkChar(*f_it))
                f_it++;
            else if (!checkChar(*b_it))
                b_it++;
            else
            {
                if (std::tolower(*f_it) != std::tolower(*b_it))
                    return false;
                f_it++;
                b_it++;
            }
        }
        return true;
    }

    static inline bool checkChar(char c)
    {
        return ('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z') ||
               ('0' <= c && c <= '9');
    }
};

int main()
{
    std::string test{"'''''''''''''''''''''''''''''''''''''''''''''''''''''"
                     "'''''''''''''''''"
                     "'''''''''''''''''''''''''''''''''''''''''''''''''''''"
                     "'''''''''''''''''"
                     "'''''''''''''''''''''''''''''''''''''''''''''''''''''"
                     "'''''''''''''''''"
                     "'''''''''''''''''''''''''''''''''''''''''''''''''''''"
                     "'''''''''''''''''"
                     "'''''''''''''''''''''''''''''''''''''''''''''''''''''"
                     "'''''''''''''''''"
                     "'''''''''''''''''''''''''''''''''''''''''''''''''''''"
                     "'''''''''''''''''"
                     "'''''''''''''''''''''''''''''''''''''''''''''''''''''"
                     "'''''''''''''"};
    Solution solution;
    std::cout << solution.isPalindrome(test) << std::endl;
}