#ifndef COMMANDER_H
#define COMMANDER_H

#include "CodeFileManager.h"
#include "FolderManager.h"
#include "GenericFileManager.h"
#include "ImageFileManager.h"
#include <filesystem>
#include <iostream>

namespace fs = std::filesystem;

class Commander {
private:
  std::string cmd;
  fs::path path;
  int *date;
  void command();
  FolderManager *fm;
  CodeFileManager *cfm;
  ImageFileManager *ifm;

public:
  Commander(std::string _cmd);
  Commander(std::string _cmd, std::string _path, int *date, FolderManager *_fm,
            CodeFileManager *_cfm, ImageFileManager *_ifm);
  void run(std::string _cmd);
  void run();
};

#endif