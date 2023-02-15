cmake_minimum_required(VERSION 3.0.0)
project(sum_func VERSION 0.1.0)
set(CMAKE_CXX_STANDARD 17)

find_package(GTest)
enable_testing()

add_executable(sum_func main.cpp)

target_link_libraries(sum_func
    GTest::GTest 
    GTest::Main)


