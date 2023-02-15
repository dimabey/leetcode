#include <algorithm>
#include <iostream>
#include <map>
#include <sstream>
#include <stack>
#include <vector>

class Solution
{
public:
    bool isValid(std::string s)
    {
        std::stack<char> st;
        for (auto c : s)
        {
            if (c == '(' || c == '[' || c == '{')
            {
                st.push(c);
                continue;
            }

            if (st.empty())
                return false;

            int shift = 1;
            if (c - 1 != '(')
                shift = 2;

            if (st.top() + shift == c)
                st.pop();
            else
                return false;
        }
        return st.empty();
    }
};

int main()
{
    std::string test("())");
    Solution solution;
    std::cout << solution.isValid(test) << std::endl;
}