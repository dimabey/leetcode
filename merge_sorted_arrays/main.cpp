#include <iostream>
#include <map>
#include <sstream>
#include <vector>

class Solution
{
public:
    void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n)
    {
        for (auto rit_1_d = nums1.rbegin(),
                  rit_1 = nums1.rbegin() + nums2.size(), rit_2 = nums2.rbegin();
             rit_2 != nums2.rend() && rit_1_d != nums1.rend(); rit_1_d++)
        {
            if (rit_1 != nums1.rend() && *rit_1 >= *rit_2)
            {
                std::swap(*rit_1_d, *rit_1);
                rit_1++;
            }
            else
            {
                std::swap(*rit_1_d, *rit_2);
                rit_2++;
            }
        }
    }
};

int main()
{
    std::vector<int> test1{1, 2, 3, 0, 0, 0};
    std::vector<int> test2{2, 5, 6};
    Solution solution;
    solution.merge(test1, 3, test2, 3);
}