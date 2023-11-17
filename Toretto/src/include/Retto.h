#ifndef RETTO_H
#define RETTO_H

#include <filesystem>
#include <iostream>

namespace fs = std::filesystem;

class Retto {
private:
  fs::path path;
  std::string name;

public:
  Retto(fs::path _path, std::string _name);
  std::string getName();
  void commit();
};

#endif