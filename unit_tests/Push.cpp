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
    MyHeap<int> your_heap;

    int r[5] = {rand() % 50, rand() % 50, rand() % 50, rand() % 50,
                rand() % 50};
    for (int k = 0; k < 5; k++) {
      your_heap.push(r[k]);
    }

    if (your_heap.size() != 5 || your_heap.is_heap(0) == false) {
      return false;
    }

    return true;
  });
}
