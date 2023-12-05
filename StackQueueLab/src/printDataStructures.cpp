#include "Array.h"
#include "Stacks/Stacks.h"
#include "LinkedList.h"
#include "Queues/Queues.h"
#include <iostream>

using std::cout;
template <typename T> void printArray(Array<T> &array) {
  cout << "[";
  for (int i = 0; i < array.getSize(); ++i) {
    cout << "{";
    cout << array[i].getName();
    cout << ", ";
    cout << array[i].getAge();
    cout << "}";
    if (i != array.getSize() - 1) {
      cout << ", ";
    }
  }
  cout << "]\n";
}
template <typename T> void printLinkedList(LinkedList<T> &linkedlist) {
  cout << "[";
  for (int i = 0; i < linkedlist.getSize(); ++i) {
    cout << "{";
    cout << linkedlist.get(i).getName();
    cout << ", ";
    cout << linkedlist.get(i).getAge();
    cout << "}";
    if (i != linkedlist.getSize() - 1) {
      cout << ", ";
    }
  }
  cout << "]\n";
}

template <typename T> void printQueue(DynamicQueue<T> &queue) {
  cout << "[";
  for (int i = 0; i < queue.getSize(); ++i) {
    cout << "{";
    cout << queue.peekAt(i).getName();
    cout << ", ";
    cout << queue.peekAt(i).getAge();
    cout << "}";
    if (i != queue.getSize() - 1) {
      cout << ", ";
    }
  }
  cout << "]\n";
}

template <typename T> void printQueue(StaticQueue<T> &queue) {
  cout << "[";
  for (int i = 0; i < queue.getSize(); ++i) {
    cout << "{";
    cout << queue.peekAt(i).getName();
    cout << ", ";
    cout << queue.peekAt(i).getAge();
    cout << "}";
    if (i != queue.getSize() - 1) {
      cout << ", ";
    }
  }
  cout << "]\n";
}

template <typename T> void printQueue(LinkedQueue<T> &queue) {
  cout << "[";
  for (int i = 0; i < queue.getSize(); ++i) {
    cout << "{";
    cout << queue.peekAt(i).getName();
    cout << ", ";
    cout << queue.peekAt(i).getAge();
    cout << "}";
    if (i != queue.getSize() - 1) {
      cout << ", ";
    }
  }
  cout << "]\n";
}

template <typename T> void printStack(DynamicStack<T> &stack) {
  cout << "[";
  for (int i = 0; i < stack.getSize(); ++i) {
    cout << "{";
    cout << stack.peekAt(i).getName();
    cout << ", ";
    cout << stack.peekAt(i).getAge();
    cout << "}";
    if (i != stack.getSize() - 1) {
      cout << ", ";
    }
  }
  cout << "]\n";
}

template <typename T> void printStack(StaticStack<T> &stack) {
  cout << "[";
  for (int i = 0; i < stack.getSize(); ++i) {
    cout << "{";
    cout << stack.peekAt(i).getName();
    cout << ", ";
    cout << stack.peekAt(i).getAge();
    cout << "}";
    if (i != stack.getSize() - 1) {
      cout << ", ";
    }
  }
  cout << "]\n";
}

template <typename T> void printStack(LinkedStack<T> &stack) {
  cout << "[";
  for (int i = 0; i < stack.getSize(); ++i) {
    cout << "{";
    cout << stack.peekAt(i).getName();
    cout << ", ";
    cout << stack.peekAt(i).getAge();
    cout << "}";
    if (i != stack.getSize() - 1) {
      cout << ", ";
    }
  }
  cout << "]\n";
}
