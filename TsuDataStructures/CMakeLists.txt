cmake_minimum_required(VERSION 3.30)
project(DataStructuresSeminars CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 20)

add_executable(DataStructuresSeminars DataStructures/BinarySearchTree/DSMain.cpp
        DataStructures/BinarySearchTree/BST.h
        DataStructures/BinarySearchTree/RBT.h
        DataStructures/BinarySearchTree/AVL.h)

add_subdirectory(SortingAlgorithms)
add_subdirectory(DataStructures)
target_link_libraries(DataStructuresSeminars SortingAlgorithms)
