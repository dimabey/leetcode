#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <sstream>
#include <string>
#include <vector>

class Solution
{
public:
    void reverseString(std::vector<char>& s)
    {
        auto f_it = s.begin();
        auto r_it = s.rbegin();
        while (std::distance(f_it, r_it.base()) > 0)
        {
            auto temp = *f_it;
            *f_it = *r_it;
            *r_it = temp;
            f_it++;
            r_it++;
        }
    }
};

int main()
{
    std::vector<char> test{'h', 'e', 'l', 'l', 'o'};
    Solution solution;
    solution.reverseString(test);
}