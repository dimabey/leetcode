#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

// Replace all spaces in string with "%20"

class Solution
{
public:
    void URLify(std::string& s, int len)
    {
        for (auto head = s.rbegin() + s.size() - len, tail = s.rbegin();
             head != s.rend(); head++)
        {
            if (*head == ' ')
                insertURL(tail, "%20");
            else
            {
                std::swap(*head, *tail);
                tail++;
            }
        }
    }

    // it1 and it2 go in reverse
    // it1 and it2 point to last element
    // inc it1 till it finds letter
    // check if there's letter in it2
    // no -> swap and inc
    // yes -> inc and insert url
    // exit on it1 == begin

    void insertURL(std::string::reverse_iterator& it, std::string url)
    {
        for (auto url_it = url.rbegin(); url_it != url.rend(); url_it++)
        {
            *it = *url_it;
            it++;
        }
    }
};

int main()
{
    std::string test1{"Mr John Smith    "};
    Solution solution;
    solution.URLify(test1, 13);
    std::cout << test1 << std::endl;
}