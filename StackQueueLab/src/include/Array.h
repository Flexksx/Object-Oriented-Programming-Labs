#ifndef ARRAY_H
#define ARRAY_H

#include <cstddef>

template <typename T> class Array {
private:
  T *head;
  std::size_t size;

public:
  Array() {
    this->head = nullptr;
    this->size = 0;
  }

  ~Array() { delete[] this->head; }

  void add(T data) {
    T *newHead = new T[this->size + 1];

    // Copy existing elements to the new array
    for (std::size_t i = 0; i < this->size; ++i) {
      newHead[i] = this->head[i];
    }

    // Add the new element to the end of the array
    newHead[this->size] = data;

    // Deallocate the old array
    delete[] this->head;

    // Update the pointer and size
    this->head = newHead;
    ++this->size;
  };
  void remove(T data) {
    for (int i = 0; i < this->size; i++) {
      if (this->head[i] == data) {
        this->removeAt(i);
        break;
      }
    }
  };
  void removeAt(int index) {
    if (index < 0 || index >= this->size) {
      // Index out of bounds, handle the error or return early
      return;
    }

    for (int i = index; i < this->size - 1; i++) {
      this->head[i] = this->head[i + 1];
    }
    this->size--;
  }
  void removeAll(T data) {
    for (int i = 0; i < this->size; i++) {
      if (this->head[i] == data) {
        this->removeAt(i);
      }
    }
  };
  T get(int index) { return this->head[index]; };
  void set(T data, int index) { this->head[index] = data; };
  int find(T data) {
    for (int i = 0; i < this->size; i++) {
      if (this->head[i] == data) {
        return i;
      }
    }
    return -1;
  }
  int getSize() { return this->size; };
};

#endif // ARRAY_H