#ifndef DOG_H
#define DOG_H

#include <iostream>
using std::string;

class Dog {
private:
  string name;
  int age;

public:
  Dog() {
    this->name = "";
    this->age = 0;
  }
  Dog(string name, int age) {
    this->name = name;
    this->age = age;
  }
  bool operator==(const Dog &other) const {
    return this->name == other.name && this->age == other.age;
  }
  string getName() { return this->name; }
  int getAge() { return this->age; }
  void setName(string name) { this->name = name; }
  void setAge(int age) { this->age = age; }
};

#endif