#include <iostream>
#include <map>
#include <queue>
#include <sstream>
#include <string>
#include <vector>

class Solution
{
public:
    int solution(std::vector<int>& A)
    {
        if (A.size() < 2)
        {
            return 0;
        }

        int max_len = 0;
        int max_idx = 0;
        for (size_t crnt_idx = 1, last_idx = 0, crnt_len = 0;
             crnt_idx < A.size(); crnt_idx++)
        {
            if (A[crnt_idx] <= A[crnt_idx - 1])
            {
                crnt_len = 0;
                last_idx = crnt_idx;
            }
            else
            {
                crnt_len++;
                if (max_len < crnt_len)
                {
                    max_len = crnt_len;
                    max_idx = last_idx;
                }
            }
        }
        return max_idx;
    }
};

int main()
{
    std::vector<int> test{2, 1, 2, 3, 1, 2, 3, 4};
    Solution solution;
    std::cout << solution.solution(test) << std::endl;
}