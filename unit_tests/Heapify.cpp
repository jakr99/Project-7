#include "MyHeap.h"
#include "test_utils.hpp"
#include <algorithm>
#include <ctime>
#include <functional>
#include <queue>
#include <stdlib.h>
#include <vector>

int main(const int argc, const char **argv) {
  return test_wrapper(argc, argv, []() {
    time_t seed;
    srand(time(&seed));

    std::priority_queue<int> test_heap;

    int r[10];
    for (int k = 0; k < 10; k++) {
      r[k] = rand() % 100;
    }

    MyHeap<int> your_heap = MyHeap<int>(r, 10);
    if (your_heap.is_heap(0) == false)
      return false;

    return true;
  });
}
