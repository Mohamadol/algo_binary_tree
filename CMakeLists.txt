cmake_minimum_required(VERSION 3.15)
project(BinaryTreePractice LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Library
add_library(binary_tree
    src/binary_tree.cpp
)
target_include_directories(binary_tree PUBLIC ${CMAKE_SOURCE_DIR}/include)

# Tests executable
add_executable(binary_tree_tests
    src/main.cpp
)
target_link_libraries(binary_tree_tests PRIVATE binary_tree)

# Nice default
enable_testing()
add_test(NAME run_all COMMAND binary_tree_tests)

