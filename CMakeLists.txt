cmake_minimum_required (VERSION 2.8.11)

project (MyExp)

set (CMAKE_CXX_STANDARD 11)

add_library (MyExp SHARED myexp.cpp)
