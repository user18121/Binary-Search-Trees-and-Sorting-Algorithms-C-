Sorting Algorithms, Binary Search Tree, Red-Black Tree, and AVL Tree

This repository implements fundamental data structures and algorithms in C++ using CMake. Developed in CLion, the project covers the following topics:

Features

Sorting Algorithms

Bubble Sort

Insertion Sort

Merge Sort

Quick Sort

Heap Sort

Binary Search Tree (BST)

Basic operations: Insert, Delete, Search

Traversals: Inorder, Preorder, Postorder

Red-Black Tree

Self-balancing binary search tree

Operations include insertion and deletion with balancing properties

AVL Tree

Height-balanced binary search tree

Rotations for maintaining balance: Left, Right, Left-Right, Right-Left

Prerequisites

C++17 or later

CMake 3.15 or later

Build Instructions

Clone the repository:

git clone <repository-url>
cd <repository-name>

Create a build directory:

mkdir build
cd build

Configure the project with CMake:

cmake ..

Build the project:

cmake --build .

Usage

After building, run the executable to test the implementation of sorting algorithms, BST, Red-Black Tree, and AVL Tree. You can modify the main.cpp file to experiment with different inputs and scenarios.

Directory Structure

<TsuDataStructures>/
├── DataStructures/
│   ├── BinarySearchTree/
│   │   ├── AVL.h
│   │   ├── BST.h
│   │   ├── RBT.h
│   │   ├── CMakeLists.txt
├── SortingAlgorithms/
│   ├── CMakeLists.txt
│   ├── SortingAlgorithms.cpp
│   ├── SortingAlgorithms.h
├── .gitignore
├── CMakeLists.txt
├── main.cpp

Contributing

Feel free to open issues or submit pull requests to improve the project.
