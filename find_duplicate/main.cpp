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
    int findDuplicate(std::vector<int>& nums)
    {
        std::vector<int> frequency(nums.size() - 1, 0);
        for (auto num : nums)
            frequency[num - 1]++;

        for (size_t i = 0; i < frequency.size(); i++)
            if (frequency[i] > 1)
                return i + 1;
    }
};

int main()
{
    std::vector<int> test{3, 1, 3, 4, 2};
    Solution solution;
    std::cout << solution.findDuplicate(test) << std::endl;
}