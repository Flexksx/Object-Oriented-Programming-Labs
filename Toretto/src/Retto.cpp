#include "include/Retto.h"

using std::string, std::cout, std::endl;

Retto::Retto(fs::path _path, string _name) {
  this->path = _path;
  this->name = _name;
}