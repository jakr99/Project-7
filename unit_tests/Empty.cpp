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

    if (your_heap.empty() == false)
      return false;

    return true;
  });
}
