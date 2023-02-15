#include <iostream>
#include <map>
#include <sstream>
#include <vector>

class Solution
{
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target)
    {
        std::vector<int> res(2, 0);
        std::map<int, int> mp;
        for (int i = 0; i < nums.size(); i++)
        {
            auto el = mp.find(target - nums[i]);
            if (el != mp.end())
            {
                res[0] = i;
                res[1] = el->second;
                break;
            }
            mp.insert({nums[i], i});
        }
        return res;
    }
};

std::string vecToStr(const std::vector<int>& vec)
{
    std::ostringstream oss;
    for (auto el : vec)
        oss << el << ", ";
    return oss.str();
}

int main()
{
    std::vector<int> test{3, 2, 4};
    int target = 6;
    Solution solution;
    std::cout << vecToStr(solution.twoSum(test, target)) << std::endl;
}