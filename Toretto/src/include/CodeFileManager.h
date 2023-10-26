#ifndef CODE_FILE_MANAGER_H
#define CODE_FILE_MANAGER_H

#include "GenericFileManager.h"
#include <filesystem>
#include <iostream>

namespace fs = std::filesystem;

class CodeFileManager : public GenericFileManager {
private:
  fs::path filePath;
  std::string fileExtension;
public:
  CodeFileManager(std::string _filePath, int* date);
  std::string getFileExtension();
  int getNrOfLines();
  void showInfo();
};

#endif