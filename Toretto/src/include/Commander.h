#ifndef COMMANDER_H
#define COMMANDER_H

#include "CodeFileManager.h"
#include "FolderManager.h"
#include "GenericFileManager.h"
#include "ImageFileManager.h"
#include <cstddef>
#include <filesystem>
#include <iostream>

namespace fs = std::filesystem;

class Commander {
private:
  std::string cmd;
  fs::path path;
  int *date;
  void command();
  unsigned short int state;
  /*
  There are 4 states:
  0: Working with the folder manager
  1: Working with the generic file manager
  2: Working with the code file manager
  3: Working with the image file manager
  */
  /*
  I thought it would be interesting to implement them as unsigned chars
  and have some byte operations fun, but the deadline kills me.
  */
  FolderManager *fm;
  CodeFileManager *cfm;
  ImageFileManager *ifm;
  GenericFileManager *gfm;
  void slCommand();
public:
  Commander(std::string _cmd);
  Commander(std::string _cmd, std::string _path, int *date, FolderManager *_fm, GenericFileManager *_gfm,
            CodeFileManager *_cfm, ImageFileManager *_ifm);
  void run(std::string _cmd);
  void giveCommand(std::string _cmd);
  void run();
};

#endif