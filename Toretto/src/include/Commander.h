#ifndef COMMANDER_H
#define COMMANDER_H

#include <filesystem>
#include <iostream>

namespace fs = std::filesystem;

class Commander {
private:
  fs::path path;
  int* date;

public:
  Commander(std::string _path, int* date);
  void fileInfo();
  void handleCommand(std::string command);
};

#endif