#include "MyHeap.h"

int main() {
  MyHeap<int> your_heap;
  your_heap.begin() = new int[3]{42, 21, 1};
  your_heap.size_override(3);

  your_heap.pop();
  your_heap.pop();
  your_heap.pop();

  try {
    your_heap.pop();
  } catch (...) {
  }

  return 0;
}
