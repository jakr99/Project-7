#ifndef MY_IS_SORTED_H
#define MY_IS_SORTED_H

// Return true if T-array 'data' is in decreasing sorted order
// size is the length of the array
template <typename T> bool my_is_sorted(const T *data, int size) {
  for (int i = 1; i < size; ++i) {
    if (data[i - 1] < data[i]) {
      return false;
    }
  }
  return true;
}

#endif
