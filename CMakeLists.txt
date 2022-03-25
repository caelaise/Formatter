cmake_minimum_required(VERSION 3.21)
project(Formatter)

set(CMAKE_CXX_STANDARD 20)

add_library(Formatter src/Table.cpp include/Table.h src/utility.cpp include/utility.h)
