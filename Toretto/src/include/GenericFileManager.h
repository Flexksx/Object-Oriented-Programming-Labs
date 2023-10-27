#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

#include <filesystem>
#include <iostream>

namespace fs = std::filesystem;

class GenericFileManager {
private:
  fs::path filePath;

protected:
  int *date;
  int *getTimeFromEpoch();
  void showLastTimeModified();

public:
  fs::file_time_type lastTimeModified();
  GenericFileManager(std::string _filePath, int *date);
  GenericFileManager(int *date);
  std::string getFileExtension();
  void selectManager();
  virtual void showInfo();
  int* getDate();
  void setPath(fs::path);
  fs::path getPath();
  ~GenericFileManager();
};

#endif
