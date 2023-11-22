#include "include/Array.h"

template <typename T> Array<T>::Array() {
  this->head = nullptr;
  this->size = 0;
}

template <typename T> Array<T>::~Array() {
  for (int i = 0; i < this->size; i++) {
    delete [] this->head;
  }
}

template <typename T> void Array<T>::add(T data) {
  this->head[this->size] = data;
  this->size++;
}

template <typename T> T Array<T>::get(int index) { return this->head[index]; }

template <typename T> void Array<T>::remove(T data) {
  for (int i = 0; i < this->size; i++) {
    if (this->head[i] == data) {
      this->removeAt(i);
      break;
    }
  }
}

template <typename T> void Array<T>::removeAt(int index) {
  if (index < 0 || index >= this->size) {
    // Index out of bounds, handle the error or return early
    return;
  }

  for (int i = index; i < this->size - 1; i++) {
    this->head[i] = this->head[i + 1];
  }
  this->size--;
}

template <typename T> void Array<T>::removeAll(T data) {
  for (int i = 0; i < this->size; i++) {
    if (this->head[i] == data) {
      this->removeAt(i);
    }
  }
}

template <typename T> int Array<T>::find(T data) {
  for (int i = 0; i < this->size; i++) {
    if (this->head[i] == data) {
      return i;
    }
  }
  return -1;
}
