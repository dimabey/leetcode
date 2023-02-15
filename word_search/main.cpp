#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <sstream>
#include <string>
#include <vector>

class Solution
{
public:
    bool exist(std::vector<std::vector<char>>& board, std::string word)
    {
        for (size_t i = 0; i < board.size(); i++)
            for (size_t j = 0; j < board[0].size(); j++)
                if (chain(board, word, i, j, 0))
                    return true;
        return false;
    }

    bool chain(std::vector<std::vector<char>>& board, std::string& word, int i,
               int j, int depth)
    {

        if (word.size() == depth)
            return true;
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() ||
            board[i][j] != word[depth])
            return false;
        auto temp = board[i][j];
        board[i][j] = '\0';
        bool chained = chain(board, word, i - 1, j, depth + 1) ||
                       chain(board, word, i + 1, j, depth + 1) ||
                       chain(board, word, i, j - 1, depth + 1) ||
                       chain(board, word, i, j + 1, depth + 1);
        if (chained)
            return true;
        board[i][j] = temp;
        return false;
    };
};

int main()
{
    std::vector<std::vector<char>> board{
        {'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
    std::string test{"SEE"};
    Solution solution;
    std::cout << solution.exist(board, test) << std::endl;
}