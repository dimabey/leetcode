#include <iostream>
#include <map>
#include <queue>
#include <sstream>
#include <string>
#include <vector>

class Solution
{
public:
    void colour(int K, std::vector<std::vector<int>>& A, int i, int j)
    {
        int first_row = (i - K >= 0) ? i - K : 0;
        int last_row = (i + K + 1 < A.size()) ? i + K + 1 : A.size();

        int first_col = (i - K >= 0) ? i - K : 0;
        int last_col = (j + K + 1 < A[0].size()) ? j + K + 1 : A[0].size();

        for (int k = first_row; k < last_row; k++)
        {
            for (int m = first_col; m < last_col; m++)
            {
                if (A[k][m] != 1 && std::abs(k - i) + std::abs(m - j) <= K)
                {
                    A[k][m]--;
                }
            }
        }
    }

    int solution(int K, std::vector<std::vector<int>>& A)
    {
        int house_cntr = 0;
        for (int i = 0; i < A.size(); i++)
        {
            for (int j = 0; j < A[0].size(); j++)
            {
                if (A[i][j] == 1)
                {
                    house_cntr++;
                    colour(K, A, i, j);
                }
            }
        }

        int plot_cntr = 0;
        for (int i = 0; i < A.size(); i++)
        {
            for (int j = 0; j < A[0].size(); j++)
            {
                if (A[i][j] != 1 && std::abs(A[i][j]) == house_cntr)
                {
                    plot_cntr++;
                }
            }
        }
        return plot_cntr;
    }
};

int main()
{
    // std::vector<std::vector<int>> test{
    //     {0, 0, 0, 0}, {0, 0, 1, 0}, {1, 0, 0, 1}};
    std::vector<std::vector<int>> test{{0, 0}, {0, 1}};
    Solution solution;
    std::cout << solution.solution(1, test) << std::endl;
}