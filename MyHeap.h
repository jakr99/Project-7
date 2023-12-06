#ifndef MYHEAP_H
#define MYHEAP_H

#include <iostream>
#include <stdexcept>
#include <string>

using std::cout;
using std::endl;

template <typename T> class MyHeap {
private:
  T *m_data = nullptr;
  int m_size = 0;
  int m_capacity = 0;

  void shrink();

  void reserve(int newSize);

  // moves the element at index `start` down the heap
  // to an appropriate position for a max heap
  void siftDown(int start);

public:
  MyHeap() {
    m_data = nullptr;
    m_size = 0;
    m_capacity = 0;
  }

  // Heapify constructor
  // Copy data from newData array
  // Then create the heap property
  MyHeap(T *const newData, int len);

  MyHeap(const MyHeap &source);

  ~MyHeap();

  MyHeap &operator=(const MyHeap &source);

  // Returns a reference to the highest priority element
  // Should throw an out_of_range exception if the heap is empty
  T &top() const;

  // Removes the highest priority element, and restores heap property
  // should throw out_of_range exception if heap is empty
  void pop();

  // Adds `val` to the heap, and restores heap property
  // Special case needed for empty heap (m_data = nullptr)
  void push(const T &val);

  // True if heap is empty, false otherwise
  bool empty() const;

  // returns number of elements stored
  int size() const;

  // testing utils
  T *&begin();

  void size_override(int size);

  bool is_heap(int root);
};

#include "MyHeap.hpp"

#endif
