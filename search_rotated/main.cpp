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
    int search(std::vector<int>& nums, int target)
    {
        int low = 0;
        int high = nums.size() - 1;
        int mid;
        while (low <= high)
        {
            mid = (low + high) / 2;
            if (nums[mid] == target)
                return mid;
            if (nums[low] <= nums[mid])
            {
                if (target <= nums[mid] && target >= nums[low])
                    high = mid - 1;
                else
                    low = mid + 1;
            }

            else
            {
                if (target >= nums[mid] && target <= nums[high])
                    low = mid + 1;
                else
                    high = mid - 1;
            }
        }
        return -1;
    }
};

// int high = nums.size() - 1;
// int low = 0;
// int mid;

// while (high >= low)
// {
//     mid = (high + low) / 2;
//     if (nums[mid] == target)
//         return mid;
//     if (nums[low] <= nums[mid])
//     {
//         if (nums[low] <= target && target <= nums[mid])
//             high = mid - 1;
//         else
//             low = mid + 1;
//     }
//     else
//     {
//         if (nums[high] >= target && target >= nums[high])
//             low = mid + 1;
//         else
//             high = mid - 1;
//     }
// }
// return (nums[mid] == target) ? mid : -1;

void printVec(std::vector<int>& vec)
{
    for (auto el : vec)
    {
        std::cout << el << ", " << std::endl;
    }
}

int main()
{
    std::vector<int> test{5, 1, 3};
    int target = 3;
    Solution solution;
    std::cout << solution.search(test, target) << std::endl;
}