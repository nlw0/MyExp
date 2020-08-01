cmake_minimum_required (VERSION 2.8.11)

project (MyExp)

add_library (MyExp SHARED myexp.cpp)

# set_property(TARGET MyExp PROPERTY POSITION_INDEPENDENT_CODE ON)
