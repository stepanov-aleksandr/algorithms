cmake_minimum_required(VERSION 3.5)

project(test_nokia LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(test_nokia main.cpp function.cpp function.h bst.h bst.cpp list.cpp list.h headers.h)
