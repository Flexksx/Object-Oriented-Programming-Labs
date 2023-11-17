#include "include/allHeaders.h"

using namespace std;

template <class T> LinkedList<T>::LinkedList() {
  this->head = nullptr;
  this->tail = nullptr;
  this->size = 0;
}

template <class T> LinkedList<T>::LinkedList(Node<T> *head) {
  this->head = head;
  int size = 0;
  Node<T> *temp = head;
  while (temp->getNext() != nullptr) {
    size++;
    temp = temp->getNext();
  }
  this->tail = temp;
  this->size = size;
}

template <class T> void LinkedList<T>::add(T element) {
  if (this->size == 0) {
    this->head = new Node<T>(element);
    this->tail = this->head;
  } else {
    this->tail->setNext(new Node<T>(element));
    this->tail = this->tail->getNext();
  }
  this->size++;
}

template <class T> T LinkedList<T>::get(int index) {
  if (index < 0 || index >= this->size) {
    throw "Index out of bounds";
  }
  Node<T> *temp = this->head;
  for (int i = 0; i < index; i++) {
    temp = temp->getNext();
  }
  return temp->getData();
}