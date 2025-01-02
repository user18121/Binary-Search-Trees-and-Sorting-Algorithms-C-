#include <iostream>
#include <random>
#include "DataStructures/BinarySearchTree/AVL.h"
#include "DataStructures/BinarySearchTree/RBT.h"
#include "DataStructures/BinarySearchTree/BST.h"

#include "SortingAlgorithms.h"
template<class Rng>
void print(Rng &range);

int main()
{

    random_device rd;
    uniform_int_distribution<int> af(0, 100);
    BST<int> bsttree;
    AVL<int> avltree;
    RedBlackTree redBlackTree;
    int array[]={10,32,43,21,50,62,45,23,500,32,49,58,6,76,21,540,232,523,521,604,230,230};
    int size=sizeof(array)/sizeof(array[0]);
    avltree.easyAdd();
    bsttree.easyAdd();
    redBlackTree.easyAdd();



    cout<<"-------------AVL Tree-------------- \n";
    cout<<avltree;
    cout<<"\n---------------------------------- \n";

    cout<<"-------------Binary Search Tree -------------- \n";
    cout<<bsttree;
    cout<<"\n-------------------------------------------- \n";
    cout<<"-------------Red Black Tree-------------- \n";
    cout<<redBlackTree;
    cout<<"\n-------------------------------------------- \n";

    cout<<"This section is about Array sorting algorithms: \n";

    // BubbleSort(array, size);   // Time Complexity: O(n^2) in the worst case
    // SelectionSort(array, size); // Time Complexity: O(n^2) in the worst case
    // InsertionSort(array, size); // Time Complexity: O(n^2) in the worst case
    // MergeSort(array, size);     // Time Complexity: O(n log n)
    // QuickSort(array, size);     // Time Complexity: O(n log n) on average
    // HeapSort(array, size);      // Time Complexity: O(n log n)

    cout<<"Not sorted array: ";
    print(array);
    cout<<"Sorted array: ";
    QuickSort(array,size);//რადგან ყველაზე სწრაფია მოცემულთაგან
    print(array);
}

template<class Rng>
void print(Rng &range)
{
    for (const auto &item : range)
        std::cout << item << " ";
    std::cout << std::endl;
}

