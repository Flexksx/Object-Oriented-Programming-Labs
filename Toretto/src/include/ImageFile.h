#ifndef IMG_FILE_MANAGER_H
#define IMG_FILE_MANAGER_H

#include "GenericFile.h"
#include <filesystem>
#include <fstream>
#include <iostream>
#ifdef _WIN32
// Windows specific includes
#include <windows.h>
#elif __linux__
// Linux specific includes
#include <arpa/inet.h>
#else
#error "Unsupported operating system"
#endif

namespace fs = std::filesystem;

class ImageFile : public GenericFile {
private:
  std::string fileExtension;
  int width;
  int height;
  bool GetImageSize(fs::path filename, int &width, int &height);

public:
  ImageFile(std::string _filePath, int *date);
  ImageFile(int *date);
  std::string getFileExtension();
  void getSize();
  void showInfo() override;
  ~ImageFile();
};

#endif