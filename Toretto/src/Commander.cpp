#include "include/Commander.h"
#include "include/GenericFileManager.h"
#include <filesystem>
#include <format>
#include <iostream>
#include <string>

Commander::Commander(std::string _path, int* _date) { this->path = _path; this->date = _date; }

void Commander::fileInfo() {
  GenericFileManager gfm(this->path, this->date);
}

void handleCommand(std::string command) {
  if (command == "-info") {
    std::cout << "info" << std::endl;
  }
}