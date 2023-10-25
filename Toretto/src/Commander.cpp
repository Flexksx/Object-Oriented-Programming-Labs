#include "/home/cristi/Documents/GitHub/LabsOOP/Toretto/include/Commander.h"
#include "/home/cristi/Documents/GitHub/LabsOOP/Toretto/include/GenericFileManager.h"
#include <filesystem>
#include <format>
#include <iostream>
#include <string>

Commander::Commander(std::string _path) { this->path = _path; }

void Commander::fileInfo() {
  GenericFileManager gfm(this->path);
  fs::file_time_type lastModTime = gfm.lastTimeModified();
  std::string extension = gfm.getFileExtension();
  std::cout << std::format("Last Modified Time: {}\n", lastModTime);
  std::cout << "File extension: " << extension << std::endl;
  //   gfm.~GenericFileManager();
}

void handleCommand(std::string command) {
  if (command == "-info") {
    std::cout << "info" << std::endl;
  }
}