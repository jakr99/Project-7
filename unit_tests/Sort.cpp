#include "MyHeap.h"
#include "my_sort.h"
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
    int test_r[10];

    // std::vector<int> test_vect;
    for (int k = 0; k < 10; k++) {
      int tmp = rand() % 100;
      r[k] = tmp;
      test_r[k] = tmp;

      // test_vect.push_back(tmp);
    }

    my_sort(r, 10);
    std::sort(test_r, test_r + 10, std::greater<int>());

    for (int k = 0; k < 10; k++) {
      if (r[k] != test_r[k])
        return false;
    }

    return true;
  });
}
