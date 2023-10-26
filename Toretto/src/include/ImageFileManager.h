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
  int width;
  int height;
  bool GetImageSize(const char *fn, int *x, int *y);
public:
  ImageFileManager(std::string _filePath, int* date);
  std::string getFileExtension();
  void getSize();
  void showInfo();
};

#endif