#include <algorithm>
#include <cstdlib>
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
    bool containsNearbyDuplicate(std::vector<int>& nums, int k)
    {
        std::unordered_map<int, int> frontier;
        for (int i = 0; i < nums.size(); i++)
        {
            if (frontier.count(nums[i]) != 0 &&
                std::abs(frontier[nums[i]] - i) <= k)
                return true;
            frontier[nums[i]] = i;
        }
        return false;
    }
};

int main()
{
    std::vector<int> test{1, 0, 1, 1};
    Solution solution;
    std::cout << solution.containsNearbyDuplicate(test, 1) << std::endl;
}