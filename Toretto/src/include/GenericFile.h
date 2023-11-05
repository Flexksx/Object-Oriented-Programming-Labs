#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

#include <filesystem>
#include <iostream>

namespace fs = std::filesystem;

class GenericFile {

protected:
  fs::path filePath;
  int *date;

public:
  int *getTimeFromEpoch();
  void showLastTimeModified();
  fs::file_time_type lastTimeModified();
  GenericFile(std::string _filePath, int *date);
  GenericFile(int *date);
  std::string getFileExtension();
  void selectManager();
  virtual void showInfo();
  int *getDate();
  void setPath(fs::path);
  fs::path getPath();
  ~GenericFile();
};

#endif
