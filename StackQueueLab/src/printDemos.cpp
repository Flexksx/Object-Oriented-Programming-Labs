#include "Array.h"
#include "Dog.h"
#include "LinkedList.h"
#include "Stacks/Stacks.h"
#include "printDataStructures.cpp"
#include "Queues/Queues.h"
#include <iostream>

using std::cout;

void arrayDemo() {
  cout << "Array Demo\n";
  cout << "--------------------------------------------------------------------"
          "----\n";
  cout << "Creating an array of 4 dogs\n";
  Array<Dog> dogs = Array<Dog>();
  cout << "Array<Dog> dogs = Array<Dog>();\n";
  cout << "Adding dogs to the array\n";
  Dog Bruno = Dog("Bruno", 5);
  Dog Jesy = Dog("Jesy", 3);
  Dog Max = Dog("Max", 7);
  Dog Rex = Dog("Rex", 2);
  dogs.add(Bruno);
  dogs.add(Jesy);
  dogs.add(Max);
  dogs.add(Rex);
  cout << "Printing the array\n";
  printArray(dogs);
  cout << "--------------------------------------------------------------------"
          "----\n";
  cout << "You can remove dogs at certain indexes\n";
  cout << "dogs.removeAt(2);\n";
  dogs.removeAt(2);
  printArray(dogs);
  cout << "--------------------------------------------------------------------"
          "----\n";
  cout << "You can remove dogs by their name\n";
  cout << "dogs.remove(Jesy);\n";
  dogs.remove(Jesy);
  printArray(dogs);
  cout << "--------------------------------------------------------------------"
          "----\n";
  cout << "You can remove all dogs by their name\n";
  cout << "dogs.add(Bruno);\n";
  dogs.add(Bruno);
  cout << "dogs.add(Bruno);\n";
  dogs.add(Bruno);
  printArray(dogs);
  cout << "dogs.removeAll(Bruno);\n";
  cout << "Removing all dogs named Bruno\n";
  dogs.removeAll(Bruno);
  printArray(dogs);
  cout << "--------------------------------------------------------------------"
          "----\n";
  cout << "You can address the array as if it were a normal array\n";
  cout << "dogs[0].getName() = " << dogs[0].getName() << "\n";
  cout << "dogs[0].getAge() = " << dogs[0].getAge() << "\n";
  cout << "Or using the get method\n";
  cout << "dogs.get(0).getName() = " << dogs.get(0).getName() << "\n";
  cout << "dogs.get(0).getAge() = " << dogs.get(0).getAge() << "\n";
  cout << "--------------------------------------------------------------------"
          "----\n";
  cout << "That's it about the array. Launch the program again to test another "
          "data structure\n";
}

void linkedListDemo() {
  cout << "Linked List Demo\n";
  cout << "--------------------------------------------------------------------"
          "----\n";
  cout << "Creating a linked list of dogs\n";
  LinkedList<Dog> dogList;
  cout << "Adding dogs to the linked list\n";
  Dog Bruno = Dog("Bruno", 5);
  Dog Jesy = Dog("Jesy", 3);
  Dog Max = Dog("Max", 7);
  Dog Rex = Dog("Rex", 2);
  dogList.add(Bruno);
  dogList.add(Jesy);
  dogList.add(Max);
  dogList.add(Rex);
  cout << "Printing the linked list\n";
  printLinkedList(dogList);
  cout << "--------------------------------------------------------------------"
          "----\n";
  cout << "You can remove dogs at certain indexes\n";
  cout << "dogList.removeAt(2);\n";
  dogList.removeAt(2);
  printLinkedList(dogList);
  cout << "--------------------------------------------------------------------"
          "----\n";
  cout << "You can remove dogs by their name\n";
  cout << "dogList.remove(Jesy);\n";
  dogList.removeAt(dogList.indexOf(Jesy));
  printLinkedList(dogList);
  cout << "--------------------------------------------------------------------"
          "----\n";
  cout << "You can remove all dogs by their name\n";
  cout << "dogList.add(Bruno);\n";
  dogList.add(Bruno);
  cout << "dogList.add(Bruno);\n";
  dogList.add(Bruno);
  printLinkedList(dogList);
  cout << "dogList.removeAll(Bruno);\n";
  cout << "Removing all dogs named Bruno\n";
  dogList.removeAll(Bruno);
  printLinkedList(dogList);
  cout << "--------------------------------------------------------------------"
          "----\n";
  cout << "You can address the linked list as if it were a normal array\n";
  cout << "dogList[0].getName() = " << dogList.get(0).getName() << "\n";
  cout << "dogList[0].getAge() = " << dogList.get(0).getAge() << "\n";
  cout << "Or using the get method\n";
  cout << "dogList.get(0).getName() = " << dogList.get(0).getName() << "\n";
  cout << "dogList.get(0).getAge() = " << dogList.get(0).getAge() << "\n";
  cout << "--------------------------------------------------------------------"
          "----\n";
  cout << "That's it about the linked list. Launch the program again to test "
          "another data structure\n";
}

void dynamicQueueDemo() {
  cout << "Dynamic Queue Demo\n";
  cout << "This Dynamic Queue can be resized and added as many elements as you "
          "want\n";
  cout << "--------------------------------------------------------------------"
          "----\n";
  cout << "Creating a dynamic queue of dogs\n";
  DynamicQueue<Dog> dogQueue;
  cout << "Adding dogs to the dynamic queue\n";
  Dog Bruno = Dog("Bruno", 5);
  Dog Jesy = Dog("Jesy", 3);
  Dog Max = Dog("Max", 7);
  Dog Rex = Dog("Rex", 2);
  dogQueue.enqueue(Bruno);
  dogQueue.enqueue(Jesy);
  dogQueue.enqueue(Max);
  dogQueue.enqueue(Rex);
  cout << "Printing the dynamic queue\n";
  printQueue(dogQueue);
  cout << "--------------------------------------------------------------------"
          "----\n";
  cout << "You can dequeue dogs from the dynamic queue\n";
  cout << "dogQueue.dequeue();\n";
  dogQueue.dequeue();
  printQueue(dogQueue);
  cout << "--------------------------------------------------------------------"
          "----\n";
  cout << "You can peek at the front of the dynamic queue\n";
  cout << "dogQueue.peek();\n";
  cout << dogQueue.peek().getName() << ", " << dogQueue.peek().getAge() << "\n";
  cout << "--------------------------------------------------------------------"
          "----\n";
  cout << "You can peek at the back of the dynamic queue\n";
  cout << "dogQueue.peekTail();\n";
  cout << dogQueue.peekTail().getName() << ", " << dogQueue.peekTail().getAge()
       << "\n";
  cout << "--------------------------------------------------------------------"
          "----\n";
  cout << "You can check if the dynamic queue is empty\n";
  cout << "dogQueue.isEmpty();\n";
  cout << dogQueue.isEmpty() << "\n";
  cout << "--------------------------------------------------------------------"
          "----\n";
  cout << "You can check the size of the dynamic queue\n";
  cout << "dogQueue.getSize();\n";
  cout << dogQueue.getSize() << "\n";
  cout << "--------------------------------------------------------------------"
          "----\n";
  cout << "That's it about the dynamic queue. Launch the program again to test "
          "another data structure\n";
}

void linkedQueueDemo() {
  cout << "Linked Queue Demo\n";
  cout << "This Linked Queue uses Nodes that point to the next element in the "
          "queue. This is more efficient when you have to work with queues of "
          "big size.\n";
  cout << "--------------------------------------------------------------------"
          "----\n";
  cout << "Creating a linked queue of dogs\n";
  LinkedQueue<Dog> dogQueue;
  cout << "Adding dogs to the linked queue\n";
  Dog Bruno = Dog("Bruno", 5);
  Dog Jesy = Dog("Jesy", 3);
  Dog Max = Dog("Max", 7);
  Dog Rex = Dog("Rex", 2);
  dogQueue.enqueue(Bruno);
  dogQueue.enqueue(Jesy);
  dogQueue.enqueue(Max);
  dogQueue.enqueue(Rex);
  cout << "Printing the linked queue\n";
  printQueue(dogQueue);
  cout << "--------------------------------------------------------------------"
          "----\n";
  cout << "You can dequeue dogs from the linked queue\n";
  cout << "dogQueue.dequeue();\n";
  dogQueue.dequeue();
  printQueue(dogQueue);
  cout << "--------------------------------------------------------------------"
          "----\n";
  cout << "You can peek at the front of the linked queue\n";
  cout << "dogQueue.peek();\n";
  cout << dogQueue.peek().getName() << ", " << dogQueue.peek().getAge() << "\n";
  cout << "--------------------------------------------------------------------"
          "----\n";
  cout << "You can peek at the back of the linked queue\n";
  cout << "dogQueue.peekTail();\n";
  cout << dogQueue.peekTail().getName() << ", " << dogQueue.peekTail().getAge()
       << "\n";
  cout << "--------------------------------------------------------------------"
          "----\n";
  cout << "You can check if the linked queue is empty\n";
  cout << "dogQueue.isEmpty();\n";
  cout << dogQueue.isEmpty() << "\n";
  cout << "--------------------------------------------------------------------"
          "----\n";
  cout << "You can check the size of the linked queue\n";
  cout << "dogQueue.getSize();\n";
  cout << dogQueue.getSize() << "\n";
  cout << "--------------------------------------------------------------------"
          "----\n";
  cout << "That's it about the linked queue. Launch the program again to test "
          "another data structure\n";
}

void staticQueueDemo() {
  cout << "Static Queue Demo\n";
  cout << "This Static Queue has a fixed size and cannot be resized\n";
  cout << "--------------------------------------------------------------------"
          "----\n";
  cout << "Creating a static queue of dogs\n";
  StaticQueue<Dog> dogQueue = StaticQueue<Dog>(4);
  cout << "Adding dogs to the static queue\n";
  Dog Bruno = Dog("Bruno", 5);
  Dog Jesy = Dog("Jesy", 3);
  Dog Max = Dog("Max", 7);
  Dog Rex = Dog("Rex", 2);
  dogQueue.enqueue(Bruno);
  dogQueue.enqueue(Jesy);
  dogQueue.enqueue(Max);
  dogQueue.enqueue(Rex);
  cout << "Printing the static queue\n";
  printQueue(dogQueue);
  cout << "--------------------------------------------------------------------"
          "----\n";
  cout << "You can dequeue dogs from the static queue\n";
  cout << "dogQueue.dequeue();\n";
  dogQueue.dequeue();
  printQueue(dogQueue);
  cout << "--------------------------------------------------------------------"
          "----\n";
  cout << "You can peek at the front of the static queue\n";
  cout << "dogQueue.peek();\n";
  cout << dogQueue.peek().getName() << ", " << dogQueue.peek().getAge() << "\n";
  cout << "--------------------------------------------------------------------"
          "----\n";
  cout << "You can peek at the back of the static queue\n";
  cout << "dogQueue.peekTail();\n";
  cout << dogQueue.peekTail().getName() << ", " << dogQueue.peekTail().getAge()
       << "\n";
  cout << "--------------------------------------------------------------------"
          "----\n";
  cout << "You can check if the static queue is empty\n";
  cout << "dogQueue.isEmpty();\n";
  cout << dogQueue.isEmpty() << "\n";
  cout << "--------------------------------------------------------------------"
          "----\n";
  cout << "You can check the size of the static queue\n";
  cout << "dogQueue.getSize();\n";
  cout << dogQueue.getSize() << "\n";
  cout << "--------------------------------------------------------------------"
          "----\n";
  cout << "That's it about the static queue. Launch the program again to test "
          "another data structure\n";
}
void dynamicStackDemo() {
  cout << "Dynamic Stack Demo\n";
  cout << "This Dynamic Stack can be resized and added as many elements as you "
          "want\n";
  cout << "--------------------------------------------------------------------"
          "----\n";
  cout << "Creating a dynamic stack of dogs\n";
  DynamicStack<Dog> dogStack;
  cout << "Adding dogs to the dynamic stack\n";
  Dog Bruno = Dog("Bruno", 5);
  Dog Jesy = Dog("Jesy", 3);
  Dog Max = Dog("Max", 7);
  Dog Rex = Dog("Rex", 2);
  dogStack.push(Bruno);
  dogStack.push(Jesy);
  dogStack.push(Max);
  dogStack.push(Rex);
  cout << "Printing the dynamic stack\n";
  printStack(dogStack);
  cout << "--------------------------------------------------------------------"
          "----\n";
  cout << "You can pop dogs from the dynamic stack\n";
  cout << "dogStack.pop();\n";
  dogStack.pop();
  printStack(dogStack);
  cout << "--------------------------------------------------------------------"
          "----\n";
  cout << "You can peek at the top of the dynamic stack\n";
  cout << "dogStack.peek();\n";
  cout << dogStack.peek().getName() << ", " << dogStack.peek().getAge() << "\n";
  cout << "--------------------------------------------------------------------"
          "----\n";
  cout << "You can check if the dynamic stack is empty\n";
  cout << "dogStack.isEmpty();\n";
  cout << dogStack.isEmpty() << "\n";
  cout << "--------------------------------------------------------------------"
          "----\n";
  cout << "You can check the size of the dynamic stack\n";
  cout << "dogStack.getSize();\n";
  cout << dogStack.getSize() << "\n";
  cout << "--------------------------------------------------------------------"
          "----\n";
  cout << "That's it about the dynamic stack. Launch the program again to test "
          "another data structure\n";
}
void linkedStackDemo() {
  cout << "Linked Stack Demo\n";
  cout << "This Linked Stack can be resized and added as many elements as you "
          "want. It uses Nodes that point to the next element. This is more "
          "efficient when you have to work with stacks of big size.\n";
  cout << "--------------------------------------------------------------------"
          "----\n";
  cout << "Creating a linked stack of dogs\n";
  LinkedStack<Dog> dogStack;
  cout << "Adding dogs to the linked stack\n";
  Dog Bruno = Dog("Bruno", 5);
  Dog Jesy = Dog("Jesy", 3);
  Dog Max = Dog("Max", 7);
  Dog Rex = Dog("Rex", 2);
  dogStack.push(Bruno);
  dogStack.push(Jesy);
  dogStack.push(Max);
  dogStack.push(Rex);
  cout << "Printing the linked stack\n";
  printStack(dogStack);
  cout << "--------------------------------------------------------------------"
          "----\n";
  cout << "You can pop dogs from the linked stack\n";
  cout << "dogStack.pop();\n";
  dogStack.pop();
  printStack(dogStack);
  cout << "--------------------------------------------------------------------"
          "----\n";
  cout << "You can peek at the top of the linked stack\n";
  cout << "dogStack.peek();\n";
  cout << dogStack.peek().getName() << ", " << dogStack.peek().getAge() << "\n";
  cout << "--------------------------------------------------------------------"
          "----\n";
  cout << "You can check if the linked stack is empty\n";
  cout << "dogStack.isEmpty();\n";
  cout << dogStack.isEmpty() << "\n";
  cout << "--------------------------------------------------------------------"
          "----\n";
  cout << "You can check the size of the linked stack\n";
  cout << "dogStack.getSize();\n";
  cout << dogStack.getSize() << "\n";
  cout << "--------------------------------------------------------------------"
          "----\n";
  cout << "That's it about the linked stack. Launch the program again to test "
          "another data structure\n";
}
void staticStackDemo() {
  cout << "Static Stack Demo\n";
  cout << "This Static Stack has a finite number of elements and can not be "
          "resized.\n";
  cout << "--------------------------------------------------------------------"
          "----\n";
  cout << "Creating a static stack of dogs\n";
  StaticStack<Dog> dogStack = StaticStack<Dog>(4);
  cout << "Adding dogs to the static stack\n";
  Dog Bruno = Dog("Bruno", 5);
  Dog Jesy = Dog("Jesy", 3);
  Dog Max = Dog("Max", 7);
  Dog Rex = Dog("Rex", 2);
  dogStack.push(Bruno);
  dogStack.push(Jesy);
  dogStack.push(Max);
  dogStack.push(Rex);
  cout << "Printing the static stack\n";
  printStack(dogStack);
  cout << "--------------------------------------------------------------------"
          "----\n";
  cout << "You can pop dogs from the static stack\n";
  cout << "dogStack.pop();\n";
  dogStack.pop();
  printStack(dogStack);
  cout << "--------------------------------------------------------------------"
          "----\n";
  cout << "You can peek at the top of the static stack\n";
  cout << "dogStack.peek();\n";
  cout << dogStack.peek().getName() << ", " << dogStack.peek().getAge() << "\n";
  cout << "--------------------------------------------------------------------"
          "----\n";
  cout << "You can check if the static stack is empty\n";
  cout << "dogStack.isEmpty();\n";
  cout << dogStack.isEmpty() << "\n";
  cout << "--------------------------------------------------------------------"
          "----\n";
  cout << "You can check the size of the static stack\n";
  cout << "dogStack.getSize();\n";
  cout << dogStack.getSize() << "\n";
  cout << "--------------------------------------------------------------------"
          "----\n";
  cout << "That's it about the static stack. Launch the program again to test "
          "another data structure\n";
}
