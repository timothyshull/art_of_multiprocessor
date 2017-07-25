cmake_minimum_required(VERSION 3.6)
project(multiprocessor_programming)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(catch)

enable_testing()

include_directories(include)
add_library(lock include/Lock.h)
set_target_properties(lock PROPERTIES LINKER_LANGUAGE CXX)

add_subdirectory(ch02)
