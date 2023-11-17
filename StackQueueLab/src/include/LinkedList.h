#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"
#include <functional>
#include <iostream>

template <class T> class LinkedList {
private:
  Node<T> *head;
  Node<T> *tail;
  int size;

public:
  LinkedList();
  LinkedList(Node<T> *head);
  T get(int index);
  void add(T element);
  void exec_all();
  ~LinkedList();
};

#endif