#ifndef IMG_FILE_MANAGER_H
#define IMG_FILE_MANAGER_H

#include "GenericFile.h"
#include <filesystem>
#include <iostream>

namespace fs = std::filesystem;

class ImageFile : public GenericFile {
private:
  std::string fileExtension;
  int width;
  int height;
  bool GetImageSize(fs::path filename, int &width, int &height);

public:
  ImageFile(std::string _filePath, int *date);
  ImageFile(int* date);
  std::string getFileExtension();
  void getSize();
  void showInfo() override;
  ~ImageFile();
};

#endif