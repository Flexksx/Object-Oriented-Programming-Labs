#include "src/Array.h"
#include "src/Queue.h"
#include "src/LinkedQueue.h"
#include "src/Dog.h"
#include "src/LinkedStack.h"
#include "src/Stack.h"
#include "src/LinkedList.h"
#include <iostream>
#include <vector>
using std::string, std::cout, std::cin;
/*
This laboratory work will demonstrate my implementation of different Data
Structures. These are:
1. Array
2. LinkedList
3. Queue using simple pointers
4. Queue using LinkedList Nodes
5. Stack using simple pointers
6. Stack using LinkedList Nodes
*/
int main() {
  /*
  The Dog class is simple, having just 2 attributes
  with a pair of get/set methods.
  No dogs were harmed in the proccess.
  */
  Dog Bruno = Dog("Bruno", 5);
  Dog Jesy = Dog("Jesy", 3);
  Dog Max = Dog("Max", 7);
  Dog Rex = Dog("Rex", 2);

  // Array of my dawgs
  Array<Dog> dogs;
  dogs.add(Bruno);
  dogs.add(Jesy);
  dogs.add(Max);
  dogs.add(Rex);

  // Print the dogs
  cout << "My dogs are: \n";
  for (int i = 0; i < dogs.len(); i++) {
    // There is also a get(int index) method,
    // but i have overriden the [] operator
    cout << i << ". " << dogs[i].getName() << "\n";
    // 0. Bruno
    // 1. Jesy
    // 2. Max
    // 3. Rex
  }
  /* Remove Bruno
     In order to remove a Dog object, you have to override the == operator
     Otherwise, you can just remove the object at a given index with
     array.removeAt(int index)*/
  dogs.remove(Bruno);

  // Print the dogs
  cout << "My dogs after removing Bruno are: \n";
  for (int i = 0; i < dogs.len(); i++) {
    cout << i << ". " << dogs[i].getName() << "\n";
    // 0. Jesy
    // 1. Max
    // 2. Rex
  }
  // If you add 2 identycal dawgs
  dogs.add(Bruno);
  dogs.add(Bruno);
  cout << "My dogs after adding 2 identical dogs are: \n";
  for (int i = 0; i < dogs.len(); i++) {
    cout << i << ". " << dogs[i].getName() << "\n";
    // 0. Jesy
    // 1. Max
    // 2. Rex
    // 3. Bruno
    // 4. Bruno
  }
  // You can remove them all at once
  dogs.removeAll(Bruno);
  cout << "My dogs after removing all Bruno are: \n";
  for (int i = 0; i < dogs.len(); i++) {
    cout << i << ". " << dogs[i].getName() << "\n";
    // 0. Jesy
    // 1. Max
    // 2. Rex
  }

  // Create 2 queues, a simple one and one using Linked List Nodes
  Queue<Dog> simpleQueue = Queue<Dog>();
  LinkedQueue<Dog> linkedQueue = LinkedQueue<Dog>();
  simpleQueue.enqueue(Bruno);
  simpleQueue.enqueue(Jesy);
  simpleQueue.enqueue(Max);
  simpleQueue.enqueue(Rex);
  linkedQueue.enqueue(Bruno);
  linkedQueue.enqueue(Jesy);
  linkedQueue.enqueue(Max);
  linkedQueue.enqueue(Rex);
  cout << "Simple Queue: \n";
  while (!simpleQueue.isEmpty()) {
    cout << simpleQueue.dequeue().getName() << "\n";
    // Bruno
    // Jesy
    // Max
    // Rex
  }
  cout << "Linked Queue: \n";
  while (!linkedQueue.isEmpty()) {
    cout << linkedQueue.dequeue().getName() << "\n";
    // Bruno
    // Jesy
    // Max
    // Rex
  }
  linkedQueue.enqueue(Bruno);
  linkedQueue.enqueue(Jesy);
  linkedQueue.enqueue(Max);
  //You can peek at different indexes
  cout << "Peek at index 1: " << linkedQueue.peekAt(1).getName() << "\n";
  // Jesy

  // Create 2 stacks, a simple one and one using Linked List Nodes
  Stack<Dog> simpleStack = Stack<Dog>();
  LinkedStack<Dog> linkedStack = LinkedStack<Dog>();
  simpleStack.push(Bruno);
  simpleStack.push(Jesy);
  simpleStack.push(Max);
  simpleStack.push(Rex);
  linkedStack.push(Bruno);
  linkedStack.push(Jesy);
  linkedStack.push(Max);
  linkedStack.push(Rex);
  cout << "Simple Stack: \n";
  while (!simpleStack.isEmpty()) {
    cout << simpleStack.pop().getName() << "\n";
    // Rex
    // Max
    // Jesy
    // Bruno
  }
  cout << "Linked Stack: \n";
  while (!linkedStack.isEmpty()) {
    cout << linkedStack.pop().getName() << "\n";
    // Rex
    // Max
    // Jesy
    // Bruno
  }

};
