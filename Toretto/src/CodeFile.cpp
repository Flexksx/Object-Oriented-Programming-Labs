#include "include/CodeFile.h"
#include "include/GenericFile.h"
#include <filesystem>
#include <fstream>
#include <iostream>

CodeFile::CodeFile(std::string _filePath, int *_date)
    : GenericFile(_filePath, _date) {
  this->fileExtension = GenericFile::getFileExtension();
  this->filePath = _filePath;
}

CodeFile::CodeFile(int *_date) : GenericFile(_date) {
  this->date = _date;
}

void CodeFile::showInfo() {
  using namespace std::literals;
  std::string extension = GenericFile::getFileExtension();
  std::cout << "Extension: " << extension << std::endl;
  this->showLastTimeModified();
  std::cout << "Nr of lines: " << getNrOfLines() << std::endl;
}

int CodeFile::getNrOfLines() {
  int nrOfLines = 0;
  std::ifstream file(this->filePath);
  std::string line;
  while (std::getline(file, line)) {
    nrOfLines++;
  }
  return nrOfLines;
}
