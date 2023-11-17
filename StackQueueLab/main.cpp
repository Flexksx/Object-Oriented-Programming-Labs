#include "src/include/allHeaders.h"
#include <iostream>
#include <string>
using namespace std;

class Animal {
private:
  string name;
  int age;

public:
  Animal(string name, int age) {
    this->name = name;
    this->age = age;
  }
  string getName() { return this->name; }
  int getAge() { return this->age; }
};

int main() {
  Animal cat = Animal("cat", 5);
  Animal dog = Animal("dog", 10);
  Animal bird = Animal("bird", 15);
  LinkedList<Animal> *list = new LinkedList<Animal>();
  list->add(cat);
  list->add(dog);
  list->add(bird);
  list->get(0).getName();
  list->get(1).getName();
  list->get(2).getName();
  return 0;
}