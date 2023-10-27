#include "include/CodeFileManager.h"
#include "include/GenericFileManager.h"
#include <filesystem>
#include <fstream>
#include <iostream>

CodeFileManager::CodeFileManager(std::string _filePath, int *_date)
    : GenericFileManager(_filePath, _date) {
  this->fileExtension = GenericFileManager::getFileExtension();
  this->filePath = _filePath;
}

CodeFileManager::CodeFileManager(int *_date) : GenericFileManager(_date) {
  this->date=_date;
}

void CodeFileManager::showInfo() {
  using namespace std::literals;
  std::string extension = GenericFileManager::getFileExtension();
  std::cout << "Extension: " << extension << std::endl;
  this->showLastTimeModified();
  std::cout << "Nr of lines: " << getNrOfLines() << std::endl;
}

int CodeFileManager::getNrOfLines() {
  int nrOfLines = 0;
  std::ifstream file(this->filePath);
  std::string line;
  while (std::getline(file, line)) {
    nrOfLines++;
  }
  return nrOfLines;
}
