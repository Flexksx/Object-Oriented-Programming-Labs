#include "include/Commander.h"
#include "include/GenericFileManager.h"
#include <cstring>
#include <filesystem>
#include <iostream>
#include <string>

Commander::Commander(std::string _cmd, std::string _path, int *_date) {
  this->path = _path;
  this->date = _date;
  this->cmd = _cmd;
}

void Commander::run(std::string _cmd) {
  this->cmd = _cmd;
  this->command();
}

void Commander::run() { this->command(); }

void Commander::command() {
  if (this->cmd == "info") {

  }
}