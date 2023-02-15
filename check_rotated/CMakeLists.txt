cmake_minimum_required(VERSION 3.0.0)
project(test VERSION 0.1.0)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror -Wall -Wextra")

add_executable(main main.cpp)
