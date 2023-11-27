#ifndef INTF_STACK_H
#define INTF_STACK_H

template <typename T> class IStack {
public:
  virtual void push(T data);
  virtual T pop();
  virtual T peek();
  virtual bool isEmpty();
  virtual int getSize();
  virtual T peekTail();
  virtual T peekAt(int index);
  virtual void clear();
};

#endif