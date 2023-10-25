#ifndef COMMANDER_H
#define COMMANDER_H

#include <filesystem>
#include <iostream>

namespace fs = std::filesystem;

class Commander {
private:
  fs::path path;

public:
  Commander(std::string _path);
  void fileInfo();
  void handleCommand(std::string command);
};

#endif