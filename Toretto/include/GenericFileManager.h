#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

#include <filesystem>
#include <iostream>

namespace fs = std::filesystem;

class GenericFileManager {
private:
  fs::path filePath;

public:
  fs::file_time_type lastTimeModified();
  GenericFileManager(std::string _filePath);
  std::string getFileExtension();
  ~GenericFileManager();
};

#endif
