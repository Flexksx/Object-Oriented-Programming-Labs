#include "include/JavaFile.h"


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
    // Using regular expressions to check for class declarations
    std::regex classRegex(R"(^\s*(public|private)?\s*(abstract)?\s*class\s)");
    if (std::regex_search(line, classRegex)) {
      nrOfClasses++;
    }
  }
  return nrOfClasses;
}

int JavaFile::getNrOfMethods() {
  int nrOfMethods = 0;
  std::ifstream file(this->filePath);
  std::string line;
  while (std::getline(file, line)) {
    // Using regular expressions to check for method declarations
    std::regex methodRegex(
        R"(^\s*(public|private|protected)?\s*(\w+)\s*\((.*?)\)\s*\{)");
    if (std::regex_search(line, methodRegex)) {
      nrOfMethods++;
    }
  }
  return nrOfMethods;
}
