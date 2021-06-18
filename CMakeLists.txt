cmake_minimum_required(VERSION 3.17)
project(hash_tables)

set(CMAKE_CXX_STANDARD 14)

add_executable(hash_tables main.cpp hashOpen.h hashChain.h)