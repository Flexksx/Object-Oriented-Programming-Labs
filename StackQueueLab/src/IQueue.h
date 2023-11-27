#ifndef INTF_QUEUE_H
#define INTF_QUEUE_H

template <typename T> class IQueue {

public:
virtual void enqueue(T data)=0;
virtual T dequeue()=0;
virtual T peek()=0;
virtual bool isEmpty()=0;
virtual int getSize()=0;
virtual T peekTail()=0;
virtual T peekAt(int index)=0;
virtual void clear()=0;
};

#endif