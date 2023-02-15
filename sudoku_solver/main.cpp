
#include "generator.hpp"
#include "solver.hpp"
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <iostream>
#include <mutex>
#include <thread>

typedef std::array<std::array<int, 9>, 9> Sudoku;

struct SafeVector
{
    SafeVector() = default;

    std::atomic<size_t> counter{0};

    std::vector<Sudoku> storage;
    std::mutex mtx;
};

void solveSudokuInThread(SafeVector& sudokus)
{
    while (sudokus.counter != sudokus.storage.size())
    {
        sudokus.counter++;
        Solver::solve(sudokus.storage[sudokus.counter - 1], 0, 0);
    }
}

int main()
{
    const size_t num_of_sudokus = 100000;
    const size_t num_of_cores = 8;

    SafeVector unsolved_sudokus;

    for (size_t i = 0; i < num_of_sudokus; i++)
        unsolved_sudokus.storage.push_back(Generator::generateNewSudoku());

    auto start = std::chrono::high_resolution_clock::now();
    std::condition_variable completion;
    std::vector<std::thread> thread_pool;
    for (size_t i = 0; i < num_of_cores * 2; i++)
        thread_pool.emplace(
            thread_pool.end(),
            std::thread(solveSudokuInThread, std::ref(unsolved_sudokus)));

    for (size_t i = 0; i < thread_pool.size(); i++)
        thread_pool[i].join();

    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = duration_cast<std::chrono::milliseconds>(stop - start);
    std::cout << "Duration: " << duration.count() << std::endl;

    return 0;
}
