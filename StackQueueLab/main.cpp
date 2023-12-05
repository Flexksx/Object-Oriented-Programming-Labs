#include "src/Array.h"
#include "src/Dog.h"
#include "src/DynamicQueue.h"
#include "src/DynamicStack.h"
#include "src/LinkedList.h"
#include "src/LinkedQueue.h"
#include "src/LinkedStack.h"
#include "src/StaticQueue.h"
#include "src/StaticStack.h"
#include <iostream>

using std::string, std::cout, std::cin;

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
  dogs.print();
  cout << "--------------------------------------------------------------------"
          "----\n";
  cout << "You can remove dogs at certain indexes\n";
  cout << "dogs.removeAt(2);\n";
  dogs.removeAt(2);
  dogs.print();
  cout << "--------------------------------------------------------------------"
          "----\n";
  cout << "You can remove dogs by their name\n";
  cout << "dogs.remove(Jesy);\n";
  dogs.remove(Jesy);
  dogs.print();
  cout << "--------------------------------------------------------------------"
          "----\n";
  cout << "You can remove all dogs by their name\n";
  cout << "dogs.add(Bruno);\n";
  dogs.add(Bruno);
  cout << "dogs.add(Bruno);\n";
  dogs.add(Bruno);
  dogs.print();
  cout << "dogs.removeAll(Bruno);\n";
  cout << "Removing all dogs named Bruno\n";
  dogs.removeAll(Bruno);
  dogs.print();
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

void linkedListDemo() {}

void dynamicQueueDemo() {}

void linkedQueueDemo() {}

void staticQueueDemo() {}
void dynamicStackDemo() {}
void linkedStackDemo() {}
void staticStackDemo() {}

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
  cout << "Hello World! This laboratory was about implementing different Data "
          "Structures using abstraction as a pillar of OOP.\n";
  cout << "The Data Structures implemented were:\n";
  cout << "1. Array\n";
  cout << "2. LinkedList\n";
  cout << "3. Dynamic Queue using simple pointers\n";
  cout << "4. Dynamic Queue using LinkedList Nodes\n";
  cout << "5. Static Queue using simple pointers\n";
  cout << "6. Dynamic Stack using simple pointers\n";
  cout << "7. Dynamic Stack using LinkedList Nodes\n";
  cout << "8. Static Stack using simple pointers\n";
  cout << "The Dog class is simple, having just 2 attributes with a pair of "
          "get/set methods.\n";
  cout << "No dogs were harmed in the proccess.\n";
  // Array of my dawgs
  cout << "These are the dogs that will be used in the examples:\n";
  cout << "1." << Bruno.getName() << ", " << Bruno.getAge() << "\n";
  cout << "2." << Jesy.getName() << ", " << Jesy.getAge() << "\n";
  cout << "3." << Max.getName() << ", " << Max.getAge() << "\n";
  cout << "4." << Rex.getName() << ", " << Rex.getAge() << "\n";
  cout << "--------------------------------------------------------------------"
          "----\n";
  cout << "Select a Data Structure to test. Write the number from the menu "
          "before:\n";
  cout << "--------------------------------------------------------------------"
          "----\n";
  int option;
  cin >> option;
  switch (option) {
  case 1:
    arrayDemo();
    break;
  case 2:
    linkedListDemo();
    break;
  case 3:
    dynamicQueueDemo();
    break;
  case 4:
    linkedQueueDemo();
    break;
  case 5:
    staticQueueDemo();
    break;
  case 6:
    dynamicStackDemo();
    break;
  case 7:
    linkedStackDemo();
    break;
  case 8:
    staticStackDemo();
    break;
  default:
    cout << "Invalid option. Please try again.\n";
    cin >> option;
    break;
  }
  return 0;
}