#ifndef INTF_QUEUE_H
#define INTF_QUEUE_H

template <typename T> class IQueue {

public:
virtual void enqueue(T data);
virtual T dequeue();
virtual T peek();
virtual bool isEmpty();
virtual int getSize();
virtual T peekTail();
virtual T peekAt(int index);
virtual void clear();
};

#endif