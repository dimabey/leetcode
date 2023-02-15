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
    int findMin(std::vector<int>& nums)
    {
        int low = 0;
        int high = nums.size() - 1;
        int mid;

        while (high > low)
        {
            mid = (high + low) / 2;
            if (nums[mid] < nums[high])
                high = mid;
            else
                low = mid + 1;
        }
        return nums[low];
    }
};

int main()
{
    std::vector<int> test{3, 1, 2};
    Solution solution;
    std::cout << solution.findMin(test) << std::endl;
}