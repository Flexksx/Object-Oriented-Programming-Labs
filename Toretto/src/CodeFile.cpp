#include "include/CodeFile.h"
#include "include/GenericFile.h"
#include "include/JavaFile.h"
#include "include/PyFile.h"
#include <cstring>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

CodeFile::CodeFile(std::string _filePath, int *_date)
    : GenericFile(_filePath, _date) {
  this->fileExtension = GenericFile::getFileExtension();
  this->filePath = _filePath;
}

CodeFile::CodeFile(int *_date) : GenericFile(_date) { this->date = _date; }

void CodeFile::showInfo() {
  using namespace std::literals;
  std::string extension = GenericFile::getFileExtension();
  std::cout << "Extension: " << extension << std::endl;
  this->showLastTimeModified();
  std::cout << "Nr of lines: " << getNrOfLines() << std::endl;
  std::cout << "Nr of classess: " << this->getNrOfClasses() << std::endl;
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

int CodeFile::getNrOfClasses() {
  if (this->GenericFile::getFileExtension() == ".java") {
    JavaFile *javaFile = new JavaFile(this->filePath, this->date);
    return javaFile->getNrOfClasses();
  } else if (this->GenericFile::getFileExtension() == ".py") {
    PyFile *pyFile = new PyFile(this->filePath, this->date);
    return pyFile->getNrOfClasses();
  }

  return 0;
}

bool CodeFile::isCodeFileExtension() {
  std::vector<std::string> codeExtensions = {".c", ".cpp", ".java", ".py"};
  return std::find(codeExtensions.begin(), codeExtensions.end(),
                   this->filePath.extension()) != codeExtensions.end();
}