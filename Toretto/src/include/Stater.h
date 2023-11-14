#ifndef STATE_MANAGER_H
#define STATE_MANAGER_H

#include "CodeFile.h"
#include "Folder.h"
#include "GenericFile.h"
#include "ImageFile.h"
#include <filesystem>
#include <fstream>
#include <iostream>
#include <map>
#include <string>
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
  std::vector<std::pair<fs::path, std::string>>
      rettos; // Change the type of rettos

public:
  Stater(int *_date, fs::path _logFile, GenericFile *_gfm, ImageFile *_ifm,
         CodeFile *_cfm, Folder *_fm);
  void writeInitLog(fs::path path, std::string name);
  void writeLog(fs::path path, std::string name);
  void readLog();
  void updateLog();
  void deleteLog();
  void readRettos();
  void listRettos();
  void addRetto(fs::path filePath, std::string name);
  void deleteRetto(fs::path filePath);
  void commit(std::string name);
  void writeRettos();
  void commitChanges(fs::path rettoPath);
};

#endif
