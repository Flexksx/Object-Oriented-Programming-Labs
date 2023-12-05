#ifndef LINKED_STACK_H
#define LINKED_STACK_H

#include "/home/cristi/Documents/GitHub/LabsOOP/StackQueueLab/src/Node.h"
#include "IStack.h"

template <typename T> class LinkedStack : public IStack<T> {
private:
  Node<T> *head;
  Node<T> *tail;
  int size;

public:
  LinkedStack<T>() {
    this->head = nullptr;
    this->tail = nullptr;
    this->size = 0;
  };
  LinkedStack<T>(T data) {
    this->head = new Node<T>(data);
    this->tail = this->head;
    this->size = 1;
  };
  ~LinkedStack<T>() {
    Node<T> *current = this->head;
    while (current != nullptr) {
      Node<T> *next = current->getNext();
      delete current;
      current = next;
    }
  };
  void push(T data) override {
    Node<T> *newNode = new Node<T>(data);
    if (this->head == nullptr) {
      this->head = newNode;
      this->tail = newNode;
    } else {
      newNode->setNext(this->head);
      this->head = newNode;
    }
    ++this->size;
  };
  T pop() override {
    if (this->head == nullptr) {
      return T();
    }
    Node<T> *current = this->head;
    this->head = this->head->getNext();
    T data = current->getData();
    delete current;
    --this->size;
    return data;
  };
  T peek() override {
    if (this->head == nullptr) {
      return T();
    }
    return this->head->getData();
  };
  bool isEmpty() override { return this->head == nullptr; };
  int getSize() override { return this->size; };
  T peekTail() override {
    if (this->tail == nullptr) {
      return T();
    }
    return this->tail->getData();
  };
  T peekAt(int index) override {
    if (index < 0 || index >= this->size) {
      return T();
    }
    Node<T> *current = this->head;
    for (int i = 0; i < index; ++i) {
      current = current->getNext();
    }
    return current->getData();
  };
  void clear() override {
    Node<T> *current = this->head;
    while (current != nullptr) {
      Node<T> *next = current->getNext();
      delete current;
      current = next;
    }
    this->head = nullptr;
    this->tail = nullptr;
    this->size = 0;
  };
};

#endif