#ifndef NODE_H
#define NODE_H

template <typename T> class Node {
private:
  T data;
  Node<T> *next;

public:
void add(T data);
};

#endif