#ifndef QUEUE_H
#define QUEUE_H

#include "IQueue.h"

template <typename T> class DynamicQueue : public IQueue<T> {
private:
  T *head;
  T *tail;
  int size;

public:
  DynamicQueue<T>() {
    this->head = nullptr;
    this->tail = nullptr;
    this->size = 0;
  }

  DynamicQueue<T>(T data) {
    this->head = new T[1];
    this->head[0] = data;
    this->tail = this->head;
    this->size = 1;
  }

  ~DynamicQueue<T>() { delete[] this->head; }

  void enqueue(T data) override {
    T *newHead = new T[this->size + 1];
    for (int i = 0; i < this->size; ++i) {
      newHead[i] = this->head[i];
    }
    newHead[this->size] = data;
    delete[] this->head;
    this->head = newHead;
    this->tail = &(this->head[this->size]);
    ++this->size;
  };

  T dequeue() override {
    if (isEmpty()) {
      return T();
    }
    T *newHead = new T[this->size - 1];
    T data = this->head[0];
    for (int i = 0; i < this->size - 1; ++i) {
      newHead[i] = this->head[i + 1];
    }
    delete[] this->head;
    this->head = newHead;
    this->tail = &(this->head[this->size - 2]);
    --this->size;
    return data;
  };

  T peek() override { return this->head[0]; };
  bool isEmpty() override { return this->size == 0; };
  int getSize() override { return this->size; };
  T peekTail() override { return this->head[this->size - 1]; };
  T peekAt(int index) override { return this->head[index]; };
  void clear() override {
    delete[] this->head;
    this->head = nullptr;
    this->tail = nullptr;
    this->size = 0;
  };
};

#endif