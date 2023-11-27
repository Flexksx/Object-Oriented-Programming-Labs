#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "Node.h"

template <typename T> class LinkedList {
private:
  Node<T> *head;
  Node<T> *tail;
  int size;

public:
  LinkedList<T>() {
    this->head = nullptr;
    this->tail = nullptr;
    this->size = 0;
  };
  LinkedList<T>(T data) {
    this->head = new Node<T>(data);
    this->tail = this->head;
    this->size = 1;
  };
  ~LinkedList<T>() {
    Node<T> *current = this->head;
    while (current != nullptr) {
      Node<T> *next = current->getNext();
      delete current;
      current = next;
    }
  };
  void add(T data) {
    Node<T> *newNode = new Node<T>(data);
    if (this->head == nullptr) {
      this->head = newNode;
      this->tail = newNode;
    } else {
      this->tail->setNext(newNode);
      this->tail = newNode;
    }
    ++this->size;
  };
  void addAt(T data, int index) {
    if (index < 0 || index > this->size) {
      return;
    }
    if (index == 0) {
      Node<T> *newNode = new Node<T>(data);
      newNode->setNext(this->head);
      this->head = newNode;
      ++this->size;
      return;
    }
    Node<T> *current = this->head;
    for (int i = 0; i < index - 1; ++i) {
      current = current->getNext();
    }
    Node<T> *newNode = new Node<T>(data);
    newNode->setNext(current->getNext());
    current->setNext(newNode);
    ++this->size;
  };
  void remove() {
    if (this->head == nullptr) {
      return;
    }
    Node<T> *current = this->head;
    this->head = this->head->getNext();
    delete current;
    --this->size;
  };
  void removeAt(int index) {
    if (index < 0 || index >= this->size) {
      return;
    }
    if (index == 0) {
      Node<T> *current = this->head;
      this->head = this->head->getNext();
      delete current;
      --this->size;
      return;
    }
    Node<T> *current = this->head;
    for (int i = 0; i < index - 1; ++i) {
      current = current->getNext();
    }
    Node<T> *nodeToRemove = current->getNext();
    current->setNext(nodeToRemove->getNext());
    delete nodeToRemove;
    --this->size;
  };
  T get(int index) {
    if (index < 0 || index >= this->size) {
      return T();
    }
    Node<T> *current = this->head;
    for (int i = 0; i < index; ++i) {
      current = current->getNext();
    }
    return current->getData();
  };
  void clear() {
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
  int getSize() { return this->size; };
  T peekHead() {
    if (this->head == nullptr) {
      return T();
    }
    return this->head->getData();
  };
  T peekTail() {
    if (this->tail == nullptr) {
      return T();
    }
    return this->tail->getData();
  };
  bool isEmpty() { return this->head == nullptr; };
  T peekAt(int index) {
    if (index < 0 || index >= this->size) {
      return T();
    }
    Node<T> *current = this->head;
    for (int i = 0; i < index; ++i) {
      current = current->getNext();
    }
    return current->getData();
  };
  int indexOf(T data) {
    Node<T> *current = this->head;
    int index = 0;
    while (current != nullptr) {
      if (current->getData() == data) {
        return index;
      }
      current = current->getNext();
      ++index;
    }
    return -1;
  };
  void removeAll(T data) {
    Node<T> *current = this->head;
    while (current != nullptr) {
      if (current->getData() == data) {
        Node<T> *nodeToRemove = current;
        current = current->getNext();
        this->removeAt(this->indexOf(nodeToRemove->getData()));
        continue;
      }
      current = current->getNext();
    }
  };
};

#endif