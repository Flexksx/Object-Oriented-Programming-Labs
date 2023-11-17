#ifndef NODE_H
#define NODE_H

template <class T> class Node {
private:
  T data;
  Node<T> *next;

public:
  T getData();
  Node<T>* getNext();
  void setNext(Node<T> *next);
  Node(T data);
  Node(T data, Node<T> *next);
  ~Node();
};

#endif