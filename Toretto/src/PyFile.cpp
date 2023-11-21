#include "include/PyFile.h"


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

int PyFile::getNrOfMethods() {
  int nrOfMethods = 0;
  bool inClassDeclaration = false;
  std::ifstream file(this->filePath);
  std::string line;
  while (std::getline(file, line)) {
    // Check if the line is a class declaration
    if (line.find("class") == 0) {
      inClassDeclaration = true;
      continue;
    }

    // Check if the line is a method definition
    if (inClassDeclaration && line.find("def") == 0 &&
        (line.find("\t") == 0 || line.find("    ") == 0 ||
         line.find("  ") == 0)) {
      nrOfMethods++;
      inClassDeclaration = false;
      continue;
    }

    // Reset the flag if the line is not part of a class declaration
    inClassDeclaration = false;
  }
  return nrOfMethods;
}
