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

void CodeFileManager::showInfo() {
  using namespace std::literals;
  std::string extension = GenericFileManager::getFileExtension();
  int *date = GenericFileManager::getTimeFromEpoch();
  std::cout << "Extension: " << extension << std::endl;
  std::cout << "Last time modified: ";
  for (int i = 0; i < 5; i++) {
    if (i < 2)
      std::cout << date[i] << "-";
    else if (i == 2)
      std::cout << date[i] << " ";
    else if (i > 2 && i < 4)
      std::cout << date[i] << ":";
    else
      std::cout << date[i];
  }
  std::cout << std::endl;
  std::cout << "Nr of lines: " << getNrOfLines() << std::endl;
  delete[] date;
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
