#ifndef STATIC_QUEUE_H
#define STATIC_QUEUE_H

#include "IQueue.h"

template <typename T> class StaticQueue : public IQueue<T> {
private:
  T *data;
  int front;
  int rear;
  int size;

public:
void enqueue(T data) override {
  if (this->rear == this->size - 1) {
    return;
  }
  this->data[++this->rear] = data;
};
T dequeue() override {
  if (this->front == this->rear) {
    return T();
  }
  return this->data[++this->front];
};
T peek() override {
  if (this->front == this->rear) {
    return T();
  }
  return this->data[this->front + 1];
};
bool isEmpty() override { return this->front == this->rear; };
int getSize() override { return this->size; };
T peekTail() override { return this->data[this->size - 1]; };
T peekAt(int index) override { return this->data[index]; };
void clear() override {
  delete[] this->data;
  this->data = new T[0];
  this->size = 0;
  this->front = -1;
  this->rear = -1;
};
StaticQueue() {
  this->data = new T[0];
  this->size = 0;
  this->front = -1;
  this->rear = -1;
};
StaticQueue(int size) {
  this->data = new T[size];
  this->size = size;
  this->front = -1;
  this->rear = -1;
};
~StaticQueue() { delete[] this->data; };
int getFront() { return this->front; };
int getRear() { return this->rear; };

};

#endif