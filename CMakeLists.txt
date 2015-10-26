cmake_minimum_required(VERSION 3.3)
project(Sudoku_solver)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp sudoku.cpp sudoku.h utilities.cpp solver.cpp)
add_executable(Sudoku_solver ${SOURCE_FILES})