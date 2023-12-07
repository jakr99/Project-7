template <typename T> void MyHeap<T>::siftDown(int start) {
  int root = start;
  while (2 * root + 1 < m_size) {
    int child = 2 * root + 1;
    if ((child + 1 < m_size) && (m_data[child] < m_data[child + 1])) {
      ++child;
    }
    if (m_data[root] < m_data[child]) {
      std::swap(m_data[root], m_data[child]);
      root = child;
    } else {
      break;
    }
  }
}

template <typename T> MyHeap<T>::MyHeap(T *const new_data, int len) {
  m_size = len;
  m_capacity = len;
  m_data = new T[m_capacity];
  for (int i = 0; i < len; ++i) {
    m_data[i] = new_data[i];
  }

  for (int i = m_size / 2 - 1; i >= 0; --i) {
    siftDown(i);
  }
}

template <typename T> T &MyHeap<T>::top() const {
  if (empty()) {
    throw std::out_of_range("Heap is empty");
  }
  return m_data[0];
}

template <typename T> void MyHeap<T>::pop() {
  if (empty()) {
    throw std::out_of_range("Heap is empty");
  }
  std::swap(m_data[0], m_data[m_size - 1]);
  --m_size;
  siftDown(0);
}

template <typename T> void MyHeap<T>::push(const T &val) {
  reserve(m_size + 1);

  m_data[m_size++] = val;

  int child = m_size - 1;
  int parent = (child - 1) / 2;

  while (child > 0 && m_data[child] > m_data[parent]) {
    std::swap(m_data[child], m_data[parent]);
    child = parent;
    parent = (child - 1) / 2;
  }
}

template <typename T> bool MyHeap<T>::empty() const { return m_size == 0; }

// Free functions below

template <typename T> int MyHeap<T>::size() const { return m_size; }

template <typename T> MyHeap<T>::MyHeap(const MyHeap &source) {
  m_data = nullptr;
  m_size = 0;
  m_capacity = 0;
  reserve(source.m_capacity);
  m_size = source.m_size;
  for (int i = 0; i < m_size; i++) {
    m_data[i] = source.m_data[i];
  }
}

template <typename T> MyHeap<T>::~MyHeap() { delete[] m_data; }

template <typename T> MyHeap<T> &MyHeap<T>::operator=(const MyHeap &source) {
  m_size = source.m_size;
  reserve(source.m_capacity);
  shrink();
  for (int i = 0; i < m_size; i++) {
    m_data[i] = source.m_data[i];
  }
  return *this;
}

template <typename T> T *&MyHeap<T>::begin() { return m_data; }

template <typename T> bool MyHeap<T>::is_heap(int root) {
  int left = 2 * root + 1;
  int right = left + 1;
  int parent = (root - 1) / 2;

  if (root >= m_size)
    return true;

  if (parent >= 0 && m_data[root] > m_data[parent])
    return false;

  return (left >= m_size || is_heap(left)) &&
         (right >= m_size || is_heap(right));
}

template <typename T> void MyHeap<T>::shrink() {
  if (m_size <= (m_capacity / 4)) {
    T *temp = m_data;
    int newSize = m_size * 2;
    m_data = new T[newSize];
    for (int i = 0; i < m_size; i++) {
      m_data[i] = temp[i];
    }
    m_capacity = newSize;
    if (temp)
      delete[] temp;
  }
}

template <typename T> void MyHeap<T>::reserve(int newSize) {
  if (newSize > m_capacity) {
    T *temp = m_data;
    m_data = new T[newSize];

    if (temp) {
      for (int i = 0; i < m_size; i++) {
        m_data[i] = temp[i];
      }
      delete[] temp;
    }

    m_capacity = newSize;
  }
}

template <typename T> void MyHeap<T>::size_override(int size) { m_size = size; }
