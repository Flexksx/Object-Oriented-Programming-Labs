#include "include/Commander.h"
#include "include/FolderManager.h"
#include "include/GenericFileManager.h"
#include <algorithm>
#include <cstring>
#include <filesystem>
#include <iostream>
#include <string>
#include <vector>

Commander::Commander(std::string _cmd, std::string _path, int *_date,
                     FolderManager *_fm, GenericFileManager *_gfm,
                     CodeFileManager *_cfm, ImageFileManager *_ifm) {
  this->path = _path;
  this->date = _date;
  this->cmd = _cmd;
  this->fm = _fm;
  this->cfm = _cfm;
  this->ifm = _ifm;
  this->gfm = _gfm;
}

Commander::Commander(std::string _cmd) { this->cmd = _cmd; }

void Commander::giveCommand(std::string _cmd) { this->cmd = _cmd; }

void Commander::run(std::string _cmd) {
  this->cmd = _cmd;
  this->command();
}

void Commander::run() { this->command(); }

void Commander::command() {
  if (this->cmd == "help") {
    std::cout << "Commands: " << std::endl;
    std::cout << "init    initializes the program on the desired folder."
              << std::endl;
    std::cout << "help    shows this message." << std::endl;
    std::cout << "info    shows info about the file or folder." << std::endl;
    std::cout << "exit    exits the program." << std::endl;
    std::cout << "sl    selects a file or folder." << std::endl;
    std::cout << "sl ..  goes back to the previous folder." << std::endl;
  }

  else if (this->cmd == "exit") {
    std::cout << "Bye.";
    exit(0);
  }

  else if (this->cmd == "init") {
    if (fs::exists(this->fm->getPath())) {
      std::cout << "Successfully initialized on " << this->path.string() << "."
                << std::endl;
    }
  }

  else if (this->cmd == "sl") {
    std::vector<std::string> programmingLanguages = {".c", ".cpp", ".java",
                                                     ".py"};
    std::string filePath;
    std::cin >> filePath;
    filePath = this->path.string() + "/" + filePath;
    this->gfm->setPath(filePath);
    if (this->gfm->getFileExtension() == ".png") {
      this->ifm->setPath(filePath);
      std::cout << "Selected file: " << this->ifm->getPath().string()
                << std::endl;
    } else if (std::find(programmingLanguages.begin(),
                         programmingLanguages.end(),
                         this->gfm->getFileExtension()) !=
               programmingLanguages.end()) {
      this->cfm->setPath(filePath);
      std::cout << "Selected file: " << this->gfm->getPath().string()
                << std::endl;
    } else {
      std::cerr << "Unsupported file type." << std::endl;
    }
  }

  else if (this->cmd == "info") {
    if (fs::is_directory(this->path)) {
      this->fm->listAllFiles();
    }
  } else {
    std::cout << "Invalid command." << std::endl;
  }
}