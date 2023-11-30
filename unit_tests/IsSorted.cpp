#include "MyHeap.h"
#include "my_is_sorted.h"
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

    // std::priority_queue<int> test_heap;
    // MyHeap<int> your_heap;

    int r[10];
    for (int k = 0; k < 9; k++) {
      r[k] = rand() % 100;
    }
    r[9] = 100;

    if (my_is_sorted(r, 10) == true)
      return false;

    std::sort(r, r + 10, std::greater<int>());

    if (my_is_sorted(r, 10) == false)
      return false;

    return true;
  });
}
