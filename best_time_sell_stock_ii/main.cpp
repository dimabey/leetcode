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
    int maxProfit(vector<int>& prices, int fee)
    {
        int valley = INT32_MAX;
        int profit = 0;
        for (auto price : prices)
        {
            if (price < valley)
                valley = price;
            else if (price - min_price - fee > 0)
            {
                profit = price - min_price - fee;
            }
        }
        return profit;
    }
};

int main()
{
    vector<int> test{1, 3, 2, 8, 4, 9};
    Solution solution;
    cout << solution.maxProfit(test, 2) << endl;
}