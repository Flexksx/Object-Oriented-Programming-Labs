#ifndef COMMANDER_H
#define COMMANDER_H

#include "CodeFile.h"
#include "Folder.h"
#include "GenericFile.h"
#include "ImageFile.h"
#include "Stater.h"
#include <cstddef>
#include <filesystem>
#include <iostream>

namespace fs = std::filesystem;

class Commander {
private:
  std::string cmd;
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
  Stater *st;
  Folder *fm;
  CodeFile *cfm;
  ImageFile *ifm;
  GenericFile *gfm;

public:
  Commander(std::string _cmd);
  Commander(int *date, Folder *_fm, Stater *_st, GenericFile *_gfm,
            CodeFile *_cfm, ImageFile *_ifm);
  Commander(std::string _cmd, int *date, Folder *_fm, Stater *_st,
            GenericFile *_gfm, CodeFile *_cfm, ImageFile *_ifm);
  void run(std::string _cmd);
  void giveCommand(std::string _cmd);
  void run();
  void sl(fs::path path);
  void go();
  void info();
  void init(std::string name);
  void commit();
  void commit(std::string name);
  void slRetto();
};
#endif
