#ifndef SOLVER_H
#define SOLVER_H
#include <array>

class Solver
{
public:
    Solver() = default;
    ~Solver() = default;

    typedef std::array<std::array<int, 9>, 9> Sudoku;
    static bool solve(Sudoku board, size_t row_num, size_t col_num)
    {
        auto pos = getNewPosValues(board, row_num, col_num);
        if (board[row_num][col_num] != 0)
        {
            if ((row_num == board.size() - 1) && (col_num == board.size() - 1))
                return true;
            return solve(board, pos.first, pos.second);
        }
        for (size_t value = 1; value < 10; value++)
        {
            if (isGoodValue(board, row_num, col_num, value))
            {
                board[row_num][col_num] = value;
                if ((row_num == board.size() - 1) &&
                    (col_num == board.size() - 1))
                    return true;
                if (solve(board, pos.first, pos.second))
                    return true;
            }
        }
        board[row_num][col_num] = 0;
        return false;
    }

private:
    static std::pair<size_t, size_t>
    getNewPosValues(Sudoku board, size_t row_num, size_t col_num)
    {
        if (col_num == board.size() - 1)
            return std::make_pair(row_num + 1, 0);
        return std::make_pair(row_num, col_num + 1);
    }

    static bool isGoodValue(const Sudoku& board, size_t row, size_t col,
                            size_t value)
    {
        return isGoodRow(board, row, value) && isGoodCol(board, col, value) &&
               isGoodBlock(board, row, col, value);
    }

    static bool isGoodRow(const Sudoku& board, size_t row, size_t value)
    {
        for (auto col : board[row])
            if (value == col)
                return false;
        return true;
    }

    static bool isGoodCol(const Sudoku& board, size_t col, size_t value)
    {
        for (auto row : board)
            if (row[col] == value)
                return false;
        return true;
    }

    static bool isGoodBlock(const Sudoku& board, size_t row, size_t col,
                            size_t value)
    {
        int start_row = row - row % 3;
        int start_col = col - col % 3;

        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                if (board[i + start_row][j + start_col] == value)
                    return false;
        return true;
    }
};

#endif