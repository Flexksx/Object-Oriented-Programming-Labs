#include "/home/cristi/Documents/GitHub/LabsOOP/Toretto/include/GenericFileManager.h"
#include <chrono>
#include <filesystem>
#include <format>
#include <iostream>

namespace fs = std::filesystem;

GenericFileManager::GenericFileManager(std::string _filePath) {
  this->filePath = _filePath;
}

std::string GenericFileManager::getFileExtension() {
  std::string extension = "";
  std::string filePathString = this->filePath.string();
  for (int i = filePathString.length() - 1; i >= 0; i--) {
    if (filePathString[i] == '.') {
      break;
    }
    extension = filePathString[i] + extension;
  }
  return extension;
}

fs::file_time_type GenericFileManager::lastTimeModified() {
  fs::file_time_type ftime = fs::last_write_time(this->filePath);
  return ftime;
}

GenericFileManager::~GenericFileManager() {}
