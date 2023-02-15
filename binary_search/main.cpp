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
    int binarySearch(std::vector<int>& nums, int target)
    {
        size_t high = nums.size() - 1;
        size_t low = 0;
        size_t mid = 0;
        while (high != low)
        {
            mid = (high + low) / 2;
            if (nums[mid] == target)
                return mid;
            if (nums[mid] > target)
                high = mid - 1;
            else
                low = mid + 1;
        }
        if (high == low && nums[high] == target)
            return high;
        return -1;
    }
};

int main()
{
    std::vector<int> test{0, 20, 30, 50, 60, 80, 110, 130, 140};
    Solution solution;
    std::cout << solution.binarySearch(test, 110) << std::endl;
}