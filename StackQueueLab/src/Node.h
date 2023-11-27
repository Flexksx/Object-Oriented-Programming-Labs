#ifndef NODE_H
#define NODE_H

template <typename T> class Node {
private:
  T data;
  Node<T> *next;

public:
Node<T>(){
    this->next = nullptr;
}
Node<T>(T data){
    this->data = data;
    this->next = nullptr;
}
Node<T>(T data, Node<T>* next){
    this->data = data;
    this->next = next;
}
void setData(T data) { this->data = data; };
void setNext(Node<T> *next) { this->next = next; };
Node<T> *getNext() { return this->next; };
T getData() { return this->data; };
};

#endif