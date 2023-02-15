cmake_minimum_required(VERSION 3.0.0)
project(workers VERSION 0.1.0)
set(CMAKE_CXX_STANDARD 17)

add_executable(workers main.cpp)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
target_link_libraries(workers Threads::Threads)






