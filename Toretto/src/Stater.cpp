#include "include/Stater.h"
#include <filesystem>
#include <fstream>
#include <ios>

namespace fs = std::filesystem;

Stater::Stater(int *date, fs::path logFile, GenericFile *gfm, ImageFile *ifm,
               CodeFile *cfm, Folder *fm) {
  this->cfm = cfm;
  this->fm = fm;
  this->gfm = gfm;
  this->ifm = ifm;
  this->date = date;
  this->logFile = logFile;
}

void Stater::writeLog() {}

void Stater::writeInitLog() {
  this->fm->getPath();
  std::ofstream log;
  log.open(this->logFile, std::ios::app);
  log << this->fm->getPath() << std::endl;
  log.close();
}
