#include "/home/cristi/Documents/GitHub/LabsOOP/Toretto/include/FileManager.h"
#include <chrono>
#include <filesystem>
#include <iostream>

namespace fs = std::filesystem;

FileManager::FileManager(fs::path _filePath) { this->filePath = _filePath; }

std::string FileManager::getFileExtension() {
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


