#ifndef STATE_MANAGER_H
#define STATE_MANAGER_H

#include "CodeFile.h"
#include "Folder.h"
#include "GenericFile.h"
#include "ImageFile.h"
#include <filesystem>
#include <fstream>
#include <iostream>
#include <vector>

namespace fs = std::filesystem;

class Stater {
private:
  fs::path logFile;
  int *date;
  GenericFile *gfm;
  ImageFile *ifm;
  CodeFile *cfm;
  Folder *fm;
  std::vector<fs::path> rettos;

public:
  Stater(int *_date, fs::path _logFile, GenericFile *_gfm, ImageFile *_ifm,
         CodeFile *_cfm, Folder *_fm);
  void writeInitLog();
  void writeLog();
  void readLog();
  void updateLog();
  void deleteLog();
  void readRettos();
  void writeRettos();
  void addRetto();
  void deleteRetto();
  void commit();
};

#endif