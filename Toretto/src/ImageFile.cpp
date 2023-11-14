#include "include/ImageFile.h"
#include "include/GenericFile.h"
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

ImageFile::ImageFile(std::string _filePath, int *date)
    : GenericFile(_filePath, date) {
  fileExtension = GenericFile::filePath.extension();
}

ImageFile::ImageFile(int *date) : GenericFile(date) { this->date = date; }

void ImageFile::getSize() {
  bool hadRun = false;
  int _width = 0, _height = 0;
  hadRun = GetImageSize(this->filePath, _width, _height);
  if (hadRun) {
    this->width = _width;
    this->height = _height;
  } else {
    std::cout << "Error getting image size." << std::endl;
  }
}

void ImageFile::showInfo() {
  std::cout << "File extension: " << this->filePath.extension() << std::endl;
  this->showLastTimeModified();
  this->getSize();
  std::cout << "Width: " << this->width << std::endl;
  std::cout << "Height: " << this->height << std::endl;
}

bool ImageFile::GetImageSize(std::filesystem::path filename, int &width,
                             int &height) {
  std::ifstream file(filename, std::ios::binary);
  if (!file) {
    std::cerr << "Error opening file." << std::endl;
    return false;
  }

  // Verify PNG file signature
  char signature[8];
  file.read(signature, 8);
  if (signature[0] != (char)137 || signature[1] != (char)80 ||
      signature[2] != (char)78 || signature[3] != (char)71 ||
      signature[4] != (char)13 || signature[5] != (char)10 ||
      signature[6] != (char)26 || signature[7] != (char)10) {
    std::cerr << "Not a valid PNG file." << std::endl;
    return false;
  }

  // Seek to IHDR chunk
  file.seekg(16, std::ios::beg);

  // Read width and height as big-endian integers
  char data[4];
  file.read(data, 4);
  width = (data[0] << 24) | (data[1] << 16) | (data[2] << 8) | data[3];
  file.read(data, 4);
  height = (data[0] << 24) | (data[1] << 16) | (data[2] << 8) | data[3];

  file.close();
  return true;
}

ImageFile::~ImageFile(){};