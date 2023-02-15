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
    void qsort_lomuto(std::vector<int>::iterator begin,
                      std::vector<int>::iterator end)
    {
        if (std::distance(begin, end) > 1)
        {
            auto pivot = partition_lomuto(begin, end);
            qsort_lomuto(begin, pivot);
            qsort_lomuto(pivot + 1, end);
        }
    }

    std::vector<int>::iterator
    partition_lomuto(std::vector<int>::iterator begin,
                     std::vector<int>::iterator end)
    {
        auto pivot = std::prev(end, 1);
        auto low = begin;
        auto high = begin;
        for (; high != pivot; high++)
        {
            if (*high < *pivot)
            {
                std::swap(*high, *low);
                low++;
            }
        }
        std::swap(*low, *pivot);
        return low;
    }

    void qsort_hoare(std::vector<int>::iterator begin,
                     std::vector<int>::iterator end)
    {
        if (std::distance(begin, end) > 1)
        {
            auto pivot = partition_lomuto(begin, end);
            qsort_hoare(begin, pivot);
            qsort_hoare(pivot + 1, end);
        }
    }

    std::vector<int>::iterator partition_hoare(std::vector<int>::iterator begin,
                                               std::vector<int>::iterator end)
    {
        auto pivot = begin + std::distance(begin, end) / 2;
        auto low = begin;
        auto high = std::prev(end, 1);
        while (low <= high)
        {
            if (*low < *pivot)
            {
                low++;
                continue;
            }
            if (*high > *pivot)
            {
                high++;
                continue;
            }
            std::swap(*low, *high);
        }
        return low;
    }
};

void printVec(std::vector<int>& vec)
{
    for (auto el : vec)
    {
        std::cout << el << ", " << std::endl;
    }
}

int main()
{
    std::vector<int> test{4, 2, 6, 9};
    Solution solution;
    solution.qsort_lomuto(test.begin(), test.end());
    printVec(test);
}