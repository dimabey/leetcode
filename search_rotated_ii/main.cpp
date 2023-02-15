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
    bool search(vector<int>& nums, int target)
    {
        int low = 0;
        int high = nums.size();
        int mid;
        while (high > low)
        {
            
        }
    }
};

int main()
{
    std::vector<int> test{2, 5, 6, 0, 0, 1, 2};
    int target = 0;
    Solution solution;
    std::cout << solution.search(test, target) << std::endl;
}