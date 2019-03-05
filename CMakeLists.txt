cmake_minimum_required(VERSION 3.13)
project(algorithm)

set(CMAKE_CXX_STANDARD 14)

add_executable(algorithm main.cpp)
add_executable(lht recursion/lht.cpp)
add_executable(Fibonacci recursion/Fibonacci.cpp)
add_executable(eightqueens recursion/eightqueens.cpp)
