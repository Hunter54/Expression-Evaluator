cmake_minimum_required(VERSION 3.10)
project(Evaluator)

set(CMAKE_CXX_STANDARD 14)

add_executable(Evaluator main.cpp Parse_evaluate.h Expression.cpp)