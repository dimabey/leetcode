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
    std::vector<int> intersect(std::vector<int>& nums1, std::vector<int>& nums2)
    {
        std::vector<int> res;
        std::unordered_map<int, int> checks;
        for (auto num : nums1)
            checks[num]++;

        for (auto num : nums2)
            if (checks[num] != 0)
            {
                res.push_back(num);
                checks[num]--;
            }

        std::set_intersection();
        return res;
    }
};

int main()
{
    std::vector<int> test1{1, 2, 2, 1};
    std::vector<int> test2{2, 2};
    Solution solution;
    solution.intersect(test1, test2);
}