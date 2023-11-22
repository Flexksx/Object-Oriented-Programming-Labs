#ifndef STATE_MANAGER_H
#define STATE_MANAGER_H

#include "CodeFile.h"
#include "Folder.h"
#include "GenericFile.h"
#include "ImageFile.h"
#include <algorithm>
#include <chrono>
#include <filesystem>
#include <fstream>
#include <ios>
#include <iostream>
#include <map>
#include <string>
#include <thread>
#include <utility>
#include <vector>

namespace fs = std::filesystem;
using std::string, std::vector, std::pair;
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

  void detectDeleted(const std::vector<std::string> &loggedFileNames,
                     const std::vector<std::string> &existingFileNames,
                     std::vector<std::string> &deletedFiles);
  void detectNew(const std::vector<std::string> &loggedFileNames,
                 const std::vector<std::string> &existingFileNames,
                 std::vector<std::string> &newFiles);
  void detectMod(fs::path rettoPath, vector<pair<string, string>> &filesdates);

public:
  void guardRetto(std::string rettoName);
  Stater(int *_date, fs::path _logFile, GenericFile *_gfm, ImageFile *_ifm,
         CodeFile *_cfm, Folder *_fm);
  void commitChanges(fs::path rettoPath);
  void writeInitLog(fs::path path, std::string name);
  void writeLog(fs::path path);
  void readLog();
  void updateLog(fs::path rettoPath, vector<string> &deletedFiles,
                 vector<string> &newFiles,
                 vector<pair<string, string>> &filesdates);
  void deleteLog();
  void readRettos();
  void listRettos();
  void addRetto(fs::path filePath, std::string name);
  void deleteRetto(std::string name);
  void commit(std::string name);
  void writeRettos();
  void rettoInfo(std::string rettoName);
  fs::path getRettoPath(std::string rettoName);
};

#endif
