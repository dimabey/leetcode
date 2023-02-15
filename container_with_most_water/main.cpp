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
    int maxArea(std::vector<int>& height)
    {
        int front = 0;
        int back = height.size() - 1;
        int max_area = 0;
        while (back >= front)
        {
            int area = getArea(height, front, back);
            if (max_area < area)
                max_area = area;

            if (height[back] > height[front])
                front++;
            else
                back--;
        }
        return max_area;
    }

    inline int getArea(std::vector<int>& height, int front, int back)
    {
        return (back - front) *
               ((height[front] <= height[back]) ? height[front] : height[back]);
    }
};

int main()
{
    std::vector<int> test{1, 1};
    Solution solution;
    std::cout << solution.maxArea(test) << std::endl;
}