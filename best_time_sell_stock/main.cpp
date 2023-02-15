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
    int maxProfit(vector<int>& prices)
    {
        int min_price = INT32_MAX;
        int max_profit = 0;
        for (auto price : prices)
        {
            if (price < min_price)
                min_price = price;
            else if (price - min_price > max_profit)
                max_profit = price - min_price;
        }
        return max_profit;
    }
};

int main()
{
    vector<int> test{7, 1, 5, 3, 6, 4};
    Solution solution;
    cout << solution.maxProfit(test) << endl;
}