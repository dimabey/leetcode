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
    void msort(std::vector<int>::iterator begin, std::vector<int>::iterator end)
    {
        for()
    }
};

void printVec(std::vector<int>& vec)
{
    for (auto el : vec)
    {
        std::cout << el << ", " << std::endl;
    }
}

int main()
{
    std::vector<int> test{4, 2, 6, 9};
    Solution solution;
    solution.msort(test.begin(), test.end());
    printVec(test);
}