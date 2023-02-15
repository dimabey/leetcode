#ifndef GENERATOR_H
#define GENERATOR_H

#include <array>
#include <chrono>
#include <random>

class Generator
{

public:
    typedef std::array<std::array<int, 9>, 9> Sudoku;

    Generator() = default;
    ~Generator() = default;
    static Sudoku generateNewSudoku()
    {
        auto new_sudoku = base_sudoku;
        shuffleNumbers(new_sudoku);
        shuffleCols(new_sudoku);
        shuffleRows(new_sudoku);
        shuffleColBlock(new_sudoku);
        shuffleRowBlock(new_sudoku);
        return new_sudoku;
    }

private:
    static void shuffleNumbers(Sudoku board)
    {
        std::srand(std::chrono::system_clock::now().time_since_epoch().count());
        for (size_t i = 1; i <= 9; i++)
            swapNumbers(board, i, std::rand() % 10 + 1);
    }

    static void swapNumbers(Sudoku board, size_t num_1, size_t num_2)
    {
        for (auto row : board)
            for (auto col : row)
                if (col == num_1)
                    num_1 = num_2;
                else if (col == num_2)
                    num_2 = num_1;
    }

    static void shuffleRows(Sudoku board)
    {
        std::srand(std::chrono::system_clock::now().time_since_epoch().count());
        for (int i = 0, block = 0; i < 9; i++, block = i / 3)
            swapRows(board, i, block * 3 + (std::rand() % 3));
    }
    static void swapRows(Sudoku board, size_t row_1, size_t row_2)
    {
        std::swap(board.at(row_1), board.at(row_2));
    }

    static void shuffleCols(Sudoku board)
    {
        std::srand(std::chrono::system_clock::now().time_since_epoch().count());
        for (int i = 0, block = 0; i < 9; i++, block = i / 3)
            swapCols(board, i, block * 3 + (std::rand() % 3));
    }
    static void swapCols(Sudoku board, size_t col_1, size_t col_2)
    {
        for (auto row : board)
        {
            auto tmp = row.at(col_2);
            row.at(col_2) = col_1;
            row.at(col_1) = tmp;
        }
    }

    static void shuffleRowBlock(Sudoku board)
    {
        std::srand(std::chrono::system_clock::now().time_since_epoch().count());
        for (size_t i = 0; i < 3; i++)
            swapRowBlock(board, i, std::rand() % 3);
    }
    static void swapRowBlock(Sudoku board, size_t block_1, size_t block_2)
    {
        for (size_t row_1 = block_1 * 3, row_2 = block_2 * 3;
             row_1 < block_1 + 3; row_1++, row_2++)
            swapRows(board, row_1, row_2);
    }

    static void shuffleColBlock(Sudoku board)
    {
        std::srand(std::chrono::system_clock::now().time_since_epoch().count());
        for (size_t i = 0; i < 3; i++)
            swapColBlock(board, i, std::rand() % 3);
    }
    static void swapColBlock(Sudoku board, size_t block_1, size_t block_2)
    {
        for (size_t col_1 = block_1 * 3, col_2 = block_2 * 3;
             col_1 < block_1 + 3; col_1++, col_2++)
            swapCols(board, col_1, col_2);
    }

    static const std::array<std::array<int, 9>, 9> base_sudoku;
};

const std::array<std::array<int, 9>, 9> Generator::base_sudoku{
    {{3, 0, 6, 5, 0, 8, 4, 0, 0},
     {5, 2, 0, 0, 0, 0, 0, 0, 0},
     {0, 8, 7, 0, 0, 0, 0, 3, 1},
     {0, 0, 3, 0, 1, 0, 0, 8, 0},
     {9, 0, 0, 8, 6, 3, 0, 0, 5},
     {0, 5, 0, 0, 9, 0, 6, 0, 0},
     {1, 3, 0, 0, 0, 0, 2, 5, 0},
     {0, 0, 0, 0, 0, 0, 0, 7, 4},
     {0, 0, 5, 2, 0, 6, 3, 0, 0}}};

#endif