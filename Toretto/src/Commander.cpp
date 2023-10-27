#include "include/Commander.h"
#include "include/FolderManager.h"
#include "include/GenericFileManager.h"
#include <cstring>
#include <filesystem>
#include <iostream>
#include <string>

Commander::Commander(std::string _cmd, std::string _path, int *_date,
                     FolderManager *_fm, CodeFileManager *_cfm,
                     ImageFileManager *_ifm) {
  this->path = _path;
  this->date = _date;
  this->cmd = _cmd;
  this->fm = _fm;
  this->cfm = _cfm;
  this->ifm = _ifm;
}

Commander::Commander(std::string _cmd) { this->cmd = _cmd; }

void Commander::run(std::string _cmd) {
  this->cmd = _cmd;
  this->command();
}

void Commander::run() { this->command(); }

void Commander::command() {
  if (this->cmd == "help") {
    std::cout << "Commands: " << std::endl;
    std::cout << "info    shows info about the file" << std::endl;
    std::cout << "help    shows this message" << std::endl;
    std::cout << "exit    exits the program" << std::endl;
  }

  if (this->cmd == "exit") {
    std::cout << "Bye.";
    exit(0);
  }

  if (this->cmd == "info") {
    if (fs::is_directory(this->path)) {
      this->fm->listAllFiles();
    }
  }
}