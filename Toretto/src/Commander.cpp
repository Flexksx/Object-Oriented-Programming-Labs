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

  } else if (this->cmd == "commit") {
    this->initCommand();
  } else if (this->cmd == "exit") {
    std::cout << std::endl << "Bye." << std::endl;
    exit(0);
  } else if (this->cmd == "init") {
    this->initCommand();
  } else if (this->cmd == "go") {
    this->goCommand();
  }

  else if (this->cmd == "sl") {
    this->slCommand();

  } else if (this->cmd == "info") {
    this->infoCommand();
  } else {
    std::cout << "Invalid command." << std::endl;
  }
}

void Commander::slCommand() {
  std::vector<std::string> programmingLanguages = {".c", ".cpp", ".java",
                                                   ".py"};
  fs::path filePath;
  std::cin >> filePath;

  if (filePath == "..") {
    // Move back one directory if ".." is entered
    this->fm->setPath(filePath.parent_path());
    std::cout << "Moved to: " << this->fm->getPath() << std::endl;
    this->state = 0;
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

void Commander::goCommand() {
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

void Commander::infoCommand() {
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

void Commander::commitCommand(){std::cout<<"HI"<<std::endl;  }

void Commander::initCommand() { this->st->writeInitLog(); }