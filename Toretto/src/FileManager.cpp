#include "/home/cristi/Documents/GitHub/LabsOOP/Toretto/include/FileManager.h"
#include <chrono>
#include <filesystem>
#include <format>
#include <iostream>

namespace fs = std::filesystem;
using namespace std::chrono_literals;

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

void FileManager::lastTimeModified() {
  fs::file_time_type ftime = fs::last_write_time(this->filePath);
  std::cout << std::format(ftime);
}
