#include "include/Commander.h"
#include "include/CodeFile.h"
#include "include/Folder.h"
#include "include/GenericFile.h"
#include "include/Stater.h"
#include <algorithm>
#include <cstring>
#include <filesystem>
#include <iostream>
#include <string>
#include <vector>

Commander::Commander(std::string _cmd, int *_date, Folder *_fm, Stater *_st,
                     GenericFile *_gfm, CodeFile *_cfm, ImageFile *_ifm) {
  this->st = _st;
  this->date = _date;
  this->cmd = _cmd;
  this->fm = _fm;
  this->cfm = _cfm;
  this->ifm = _ifm;
  this->gfm = _gfm;
  this->state = 0;
}

Commander::Commander(int *date, Folder *_fm, Stater *_st, GenericFile *_gfm,
                     CodeFile *_cfm, ImageFile *_ifm) {
  this->date = date;
  this->st = _st;
  this->fm = _fm;
  this->gfm = _gfm;
  this->ifm = _ifm;
  this->cfm = _cfm;
  this->state = 0;
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
    std::cout << "go    initializes the program on the desired folder."
              << std::endl;
    std::cout << "help    shows this message." << std::endl;
    std::cout << "info    shows info about the file or folder." << std::endl;
    std::cout << "exit    exits the program." << std::endl;
    std::cout << "sl    selects a file or folder." << std::endl;
    std::cout << "sl ..  goes back to the previous folder." << std::endl;
  }
  std::cout << "Invalid command." << std::endl;
}

void Commander::sl(fs::path filePath) {
  std::vector<std::string> programmingLanguages = {".c", ".cpp", ".java",
                                                   ".py"};

  if (filePath == "..") {
    // Move back one directory if ".." is entered
    if (fs::exists(this->fm->getPath().parent_path())) {
      this->fm->setPath(filePath.parent_path());
      std::cout << "Moved to: " << this->fm->getPath() << std::endl;
      this->state = 0;
    } else {
      std::cout << "You are currently not in a directory. Use the 'go' command "
                   "to choose one."
                << std::endl;
    }
  } else {
    // Concatenate the path with the file name
    filePath = this->fm->getPath().string() + "/" + filePath.string();

    if (fs::is_directory(filePath)) {
      // Move to the selected directory
      if (this->fm->getPath() == filePath) {
        std::cout << "Already in this directory." << std::endl;
      } else {
        this->fm->setPath(filePath);
        std::cout << "Moved to: " << this->fm->getPath().string() << std::endl;
        this->state = 0;
      }
    } else {
      // Select the file
      this->gfm->setPath(filePath);
      if (this->gfm->getFileExtension() == ".png") {
        this->ifm->GenericFile::setPath(filePath);
        std::cout << "Selected file: " << this->ifm->getPath().string()
                  << std::endl;
        this->fm->setPath(ifm->getPath().parent_path());
        this->state = 3;
      } else if (std::find(programmingLanguages.begin(),
                           programmingLanguages.end(),
                           this->gfm->getFileExtension()) !=
                 programmingLanguages.end()) {
        this->cfm->setPath(filePath);
        this->fm->setPath(cfm->getPath().parent_path());
        this->state = 2;
      } else {
        this->state = 1;
        std::cerr
            << "Unsupported file type. Selected with limited functionality."
            << std::endl;
      }
    }
  }
}

void Commander::go() {
  std::string filePathString;
  std::cin >> filePathString;
  fs::path filePath = filePathString;

  while (!fs::is_directory(filePath) || !fs::exists(filePath)) {
    std::cout << "Path does not exist. Please enter a valid path: (Commander)";
    std::cin >> filePathString;
    filePath = filePathString;
  }

  this->fm->setPath(filePath);
  std::cout << "Moved to: " << this->fm->getPath().string() << std::endl;
}

void Commander::info() {
  if (this->state == 0) {
    if (fs::is_directory(this->fm->getPath())) {
      this->fm->listAllFiles();
    }
  } else if (this->state == 1) {
    if (fs::exists(this->gfm->getPath())) {
      std::cout << "Extension: " << this->gfm->getFileExtension() << std::endl;
      std::cout << "Last time modified: ";
      this->gfm->showLastTimeModified();
      std::cout << std::endl;
    } else {
      std::cerr << "File does not exist or an error happened." << std::endl;
    }
  } else if (this->state == 2) {
    if (fs::exists(this->cfm->getPath())) {
      this->cfm->showInfo();
    } else {
      std::cerr << "File does not exist or an error happened." << std::endl;
    }
  } else if (this->state == 3) {
    if (fs::exists(this->ifm->getPath())) {
      this->ifm->showInfo();
    } else {
      std::cerr << "File does not exist or an error happened." << std::endl;
    }
  }
}

void Commander::commit() {
  std::string rettoName;
  std::cout << "Enter Retto name: ";
  std::cin >> rettoName;
  this->st->commit(rettoName);
}

void Commander::init() {
  std::string name;
  std::cout << "Give a name to this Rettository: ";
  std::string rettoName;
  std::cin >> rettoName;
  this->st->writeInitLog(this->fm->getPath(), name);
}

void Commander::init(std::string name) {
  this->st->writeInitLog(this->fm->getPath(), name);
}