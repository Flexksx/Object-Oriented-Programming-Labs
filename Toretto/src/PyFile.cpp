#include "include/PyFile.h"
#include "include/CodeFile.h"
#include <filesystem>
#include <fstream>
#include <iostream>

namespace fs = std::filesystem;

PyFile::PyFile(fs::path _filePath, int *_date) : CodeFile(_filePath, _date) {
  this->filePath = _filePath;
  this->date = _date;
}

int PyFile::getNrOfClasses() {
  int nrOfClasses = 0;
  std::ifstream file(this->filePath);
  std::string line;
  while (std::getline(file, line)) {
    // Check if the line begins with "class"
    if (line.find("class") == 0) {
      nrOfClasses++;
    }
  }
  return nrOfClasses;
}
