#ifndef STATIC_STACK_H
#define STATIC_STACK_H

#include "IStack.h"

template <typename T> class StaticStack : public IStack<T> {
private:
  T *data;
  int size;
  int top;

public:
  StaticStack() {
    this->data = new T[0];
    this->size = 0;
  };
  StaticStack(int size) {
    this->data = new T[size];
    this->size = size;
    this->top = -1;
  };
  ~StaticStack() { delete[] this->data; };
  void push(T data) override {
    if (this->top == this->size - 1) {
      return;
    }
    this->data[++this->top] = data;
  };
  T pop() override {
    if (this->top == -1) {
      return T();
    }
    return this->data[this->top--];
  };
  T peek() override {
    if (this->top == -1) {
      return T();
    }
    return this->data[this->top];
  };
  bool isEmpty() override { return this->top == -1; };
  int getSize() override { return this->size; };
  T peekTail() override { return this->data[this->size - 1]; };
  T peekAt(int index) override { return this->data[index]; };
  void clear() override {
    delete[] this->data;
    this->data = new T[0];
    this->size = 0;
    this->top = -1;
  };
  int getTop() { return this->top; };
};

#endif