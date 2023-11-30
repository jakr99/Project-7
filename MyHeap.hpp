

template <typename T> void MyHeap<T>::siftDown(int start) {
}

template <typename T> MyHeap<T>::MyHeap(T *const new_data, int len) {
}


template <typename T> T &MyHeap<T>::top() const {
}

template <typename T> void MyHeap<T>::pop() {
}

template <typename T> void MyHeap<T>::push(const T &val) {
}

template <typename T> bool MyHeap<T>::empty() const {  }


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

  if (m_data[root] > m_data[parent])
    return false;

  return is_heap(left) && is_heap(right);
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
    }

    m_capacity = newSize;

    if (temp)
      delete[] temp;
  }
}

template <typename T> void MyHeap<T>::size_override(int size) { m_size = size; }
