#include "SortingAlgorithms.h"

#include <algorithm>
#include <filesystem>
#include <random>
#include <utility>

void BubbleSort( int *arr, int size )
{
    for ( int i{ 1 }; i < size; i++ ) {
        bool swapped = false;
        for ( int j{}; j < size - 1; j++ ) {
            if ( arr[j + 1] < arr[j] ) {
                std::swap( arr[j], arr[j + 1] );
                swapped = true;
            }
        }
        if ( !swapped )
            break;
    }
}

void SelectionSort( int *array, int size )
{
    for ( int i{}; i < size - 1; i++ ) {
        int min{ i };
        for ( int j{ i + 1 }; j < size; j++ )
            if ( array[j] < array[min] )
                min = j;
        std::swap( array[min], array[i] );
    }
}

void InsertionSort( int *arr, int size )
{
    for ( int i{ 1 }; i < size; i++ )
        for ( int j{ i }; j > 0 && arr[j] < arr[j - 1]; j-- )
            std::swap( arr[j], arr[j - 1] );
}

static void Merge( int *arr1, int size1, int *arr2, int size2, int *dest )
{
    int l{};
    int r{};
    int d{};

    while ( l < size1 && r < size2 )
        dest[d++] = arr2[r] < arr1[l] ? arr2[r++] : arr1[l++];

    while ( l < size1 )
        dest[d++] = arr1[l++];

    while ( r < size2 )
        dest[d++] = arr2[r++];
}

void MergeSort( int *arr, int size )
{
    if ( size < 2 )
        return;

    int *arr1{ arr };
    int size1{ size / 2 };
    int *arr2{ arr + size1 };
    int size2{ size - size1 };

    MergeSort( arr1, size1 );
    MergeSort( arr2, size2 );

    int *temp{ new int[size] };
    Merge( arr1, size1, arr2, size2, temp );

    std::copy( temp, temp + size, arr );
    delete[] temp;
}

static int Partition( int *arr, int size, int pivot )
{
    if ( size < 1 )
        return 0;
    int l{};
    int r{ size };

    // same as while(true)
    for ( ;; ) {
        // skip in-place elements at the begining
        for ( ;; ) {
            if ( l == r )
                return l;

            if ( arr[l] >= pivot )
                break;

            l++;
        }

        // skip in-place elements at the end
        do {
            --r;

            if ( l == r )
                return l;
        } while ( arr[r] >= pivot );

        std::swap( arr[l], arr[r] ); // swap out-of-place elements
        ++l;                         // advance and loop
    }
}

void QuickSort( int *arr, int size )
{
    if ( size < 2 )
        return;
    static std::default_random_engine dre( time( nullptr ) );
    std::uniform_int_distribution<int> di( 0, size - 1 );

    int pivot_index{ di( dre ) };
    std::swap( arr[pivot_index], arr[size - 1] );

    pivot_index = size - 1;
    int pivot = arr[pivot_index];

    int partition_point = Partition( arr, size, pivot );
    std::swap( arr[partition_point], arr[pivot_index] );

    int left_size = partition_point;
    int right_size = size - partition_point - 1;

    QuickSort( arr, left_size );
    QuickSort( arr + partition_point + 1, right_size );
}

static void heapify( int *arr, int size, int i )
{
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    int largest = i;
    if ( l < size && arr[largest] < arr[l] )
        largest = l;
    if ( r < size && arr[largest] < arr[r] )
        largest = r;

    if ( largest != i ) {
        std::swap( arr[i], arr[largest] );
        heapify( arr, size, largest );
    }
}

static void push_heap( int *arr, int size )
{
    for ( int i = size; i > 0 && arr[i / 2] < arr[i]; i /= 2 )
        std::swap( arr[i / 2], arr[i] );
}

static void pop_heap( int *arr, int size )
{
    std::swap( arr[0], arr[size - 1] );
    heapify( arr, size - 1, 0 );
}

static void make_heap( int *arr, int size )
{
    for ( int i = ( size - 1 ) / 2; i >= 0; i-- )
        heapify( arr, size, i );
}

void HeapSort( int *arr, int size )
{
    make_heap( arr, size );
    while ( size > 1 )
        pop_heap( arr, size-- );
}
