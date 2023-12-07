#ifndef MY_SORT_H
#define MY_SORT_H
#include "MyHeap.h"
#include "my_is_sorted.h"

// Sort the T-array 'data' in-place in decreasing order
// Hint: start by converting to a heap, then sort using heap operations

template <typename T> void my_sort(T *data, int size) {
  // Convert to a max-heap
  MyHeap<T> heap(data, size);

  // Create an auxiliary array to store the sorted result
  T *sortedArray = new T[size];

  // Extract elements from the heap in decreasing order and store in the
  // auxiliary array
  for (int i = 0; i < size; ++i) {
    sortedArray[i] = heap.top(); // Get the maximum element
    heap.pop(); // Remove the maximum element and restore heap property
  }

  // Copy the sorted elements back to the original array
  for (int i = 0; i < size; ++i) {
    data[i] = sortedArray[i];
  }

  // Cleanup
  delete[] sortedArray;
}

#endif
