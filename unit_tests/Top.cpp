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

    your_heap.begin() = new int[3];
    int r = rand() % 50;
    your_heap.begin()[0] = r;
    your_heap.size_override(1);

    if (your_heap.top() != r)
      return false;

    MyHeap<int> other_heap;
    try {
      int test = other_heap.top();
    } catch (std::out_of_range e) {
      return true;
    }

    std::cerr << "exception test failed" << std::endl;
    return false;
  });
}
