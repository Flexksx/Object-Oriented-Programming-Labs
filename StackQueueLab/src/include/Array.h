#ifndef ARRAY_H
#define ARRAY_H

#include <cstddef>
template <typename T> class Array {
private:
  T *head;
  int lenght;
  std::size_t size;

public:
  Array();
  ~Array();
  void add(T data);
  void remove(T data);
  void removeAt(int index);
  void removeAll(T data);
  T get(int index);
  void set(T data, int index);
  int find(T data);
  int getSize();
};


#endif // ARRAY_H