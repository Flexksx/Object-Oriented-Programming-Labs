#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

#include <filesystem>
#include <iostream>

namespace fs = std::filesystem;

class FileManager {
private:
  fs::path filePath;

public:
  void lastTimeModified();
  FileManager(fs::path filePath);
  std::string getFileExtension();
};

#endif
