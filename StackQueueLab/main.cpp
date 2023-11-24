#include "src/include/Array.h"
#include <iostream>

using std::string, std::cout, std::cin;

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
  string getName() { return this->name; }
  int getAge() { return this->age; }
  void setName(string name) { this->name = name; }
  void setAge(int age) { this->age = age; }
  string toString() {
    return "Name: " + this->name + ", Age: " + std::to_string(this->age);
  }
};

int main() {
  Array<Array<int>> matrix = Array<Array<int>>();
  Array<int> row1 = Array<int>();
  Array<int> row2 = Array<int>();
  Array<int> row3 = Array<int>();
  row1.add(1);
  row1.add(2);
  row1.add(3);
  row2.add(4);
  row2.add(5);
  row2.add(6);
  row3.add(7);
  row3.add(8);
  row3.add(9);
  matrix.add(row1);
  matrix.add(row2);
  matrix.add(row3);
  for (int i = 0; i < matrix.getSize(); i++) {
    for (int j = 0; j < matrix.get(i).getSize(); j++) {
      cout << matrix.get(i).get(j) << " ";
    }
    cout << "\n";
  }
  return 0;
};
