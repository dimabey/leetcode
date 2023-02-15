#include <array>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <unordered_set>
#include <vector>

class Solution
{
public:
    int removeDuplicates(std::vector<int>& nums)
    {
        int len = 1;
        for (size_t i = 1; i < nums.size(); i++)
        {
            if (nums[i] > nums[len - 1])
            {
                nums[len] = nums[i];
                len++;
            }
        }
        return len;
    }
};

int main()
{
    std::vector<int> test{0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    Solution solution;
    std::cout << solution.removeDuplicates(test) << std::endl;
}