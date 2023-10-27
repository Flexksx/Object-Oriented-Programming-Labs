#ifndef COMMANDER_H
#define COMMANDER_H

#include <filesystem>
#include <iostream>

namespace fs = std::filesystem;

class Commander {
private:
  std::string cmd;
  fs::path path;
  int *date;
  void command();

public:
  Commander(std::string _cmd, std::string _path, int *date);
  void run(std::string _cmd);
  void run();
};

#endif