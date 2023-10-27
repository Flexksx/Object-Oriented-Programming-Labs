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
  bool GetImageSize(fs::path filename, int &width, int &height);

public:
  ImageFileManager(std::string _filePath, int *date);
  ImageFileManager(int* date);
  std::string getFileExtension();
  void getSize();
  void showInfo() override;
  ~ImageFileManager();
};

#endif