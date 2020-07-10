cmake_minimum_required(VERSION 2.8.12)
project(binary_tree)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_executable(BinaryTreeTest BinaryTreeTest.cpp BinaryTree.cpp)
target_include_directories(BinaryTreeTest PRIVATE .)

# TODO: make CMake aware that BinaryTreeTest is a test so that CTest will detect it.
# Register the test with CMake under the name 'test_BinaryTreeTest'
add_test(NAME test_BinaryTreeTest
         COMMAND make -C build test 
                            --exe $<TARGET_FILE:BinaryTreeTest>)
