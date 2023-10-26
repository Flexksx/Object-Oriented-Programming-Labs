#ifndef IMG_FILE_MANAGER_H
#define IMG_FILE_MANAGER_H

#include "GenericFileManager.h"
#include <filesystem>
#include <iostream>

namespace fs = std::filesystem;

class ImageFileManager : public GenericFileManager {
private:
  fs::path filePath;
  std::string fileExtension;
public:
  ImageFileManager(std::string _filePath, int* date);
  std::string getFileExtension();
  int getNrOfLines();
  void showInfo();
};

#endif