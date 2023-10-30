#include "include/JavaFile.h"
#include "include/CodeFile.h"

#include <filesystem>
#include <fstream>
#include <iostream>

namespace fs = std::filesystem;

JavaFile::JavaFile(fs::path _filePath, int *_date)
    : CodeFile(_filePath, _date) {
  this->filePath = _filePath;
  this->date = _date;
}

int JavaFile::getNrOfClasses() {
  int nrOfClasses = 0;
  std::ifstream file(this->filePath);
  std::string line;
  while (std::getline(file, line)) {
    if (line.find("class") != std::string::npos) {
      nrOfClasses++;
    }
  }
  return nrOfClasses;
}