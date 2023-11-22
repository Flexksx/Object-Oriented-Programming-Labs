#include "src/include/Array.h"
#include <iostream>

using std::string, std::cout, std::cin;

int main() {
  Array<int> arr = Array<int>();
  arr.add(1);
  cout << arr.get(1);
  return 0;
};