cmake_minimum_required(VERSION 3.0.0)
project(sudoku_solver VERSION 0.1.0)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS -pthread)

add_executable(sudoku_solver 
    main.cpp 
    solver.hpp 
    generator.hpp)



