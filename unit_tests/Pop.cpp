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

    your_heap.begin() = new int[7];
    int r[7] = {50, 25, 34, 16, 7, 26, 2};
    for (int k = 0; k < 7; k++) {
      your_heap.begin()[k] = r[k];
    }
    your_heap.size_override(7);

    your_heap.pop();
    your_heap.pop();

    if (your_heap.size() != 5 || your_heap.is_heap(0) == false) {
      return false;
    }

    for (int k = 0; k < 5; k++)
      your_heap.pop();

    try {
      your_heap.pop();
    } catch (std::out_of_range e) {
      return true;
    }

    std::cerr << "exception test failed" << std::endl;
    return true;
  });
}
