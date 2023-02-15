#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        vector<vector<int>> res;
        for (size_t a = 0; a < nums.size(); a++)
        {
            unordered_set<int> seen;

            for (size_t b = a; b < nums.size(); b++)
            {
                for (size_t c = b; c < nums.size(); c++)
                {
                    if(seen )
                }
            }
        }

        return res;
    }
};

int main()
{
    std::vector<int> test{1, 0, -1, 0, -2, 2};
    int target = 0;
    Solution solution;
    solution.threeSum(test, target);
}