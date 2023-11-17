#ifndef NODE_H
#define NODE_H

template <class T> class Node {
private:
  T data;
  Node<T> *next;

public:
  void getData();
  void getNext();
};

#endif