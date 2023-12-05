#include "src/Array.h"
#include "src/Dog.h"
#include "src/LinkedList.h"
#include "src/Queues/Queues.h"
#include "src/printDemos.cpp"
#include <iostream>

using std::string, std::cout, std::cin;

using std::cout;

using std::cout;

void demoForLab() {
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
  cout << "To help in the demonstration of the Data Structures, I created a "
          "Dog class. The Dog class is simple, having just 2 attributes with a "
          "pair of "
          "get/set methods.\n";
  cout << "No dogs were harmed in the proccess.\n";
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
}

int main() {
  demoForLab();
  return 0;
}