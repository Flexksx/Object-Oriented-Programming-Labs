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
  std::ofstream log;
  log.open(this->logFile, std::ios::app);
  log << this->fm->getPath().string() << std::endl;
  for (auto &p : fs::directory_iterator(this->fm->getPath())) {
    if (fs::exists(p)) {
      this->gfm->setPath(p);
      log << this->gfm->getPath().string() << " ";
      int *date = this->gfm->getTimeFromEpoch();
      for (int i = 0; i < 5; i++) {
        if (i <= 3)
          log << date[i] << ".";
        else
          log << date[i];
      }
      log << std::endl;
    }
  }
  log.close();
}


void Stater::readRettos(){
  std::ifstream log;
  log.open(this->logFile);
  std::string line;
  while (std::getline(log, line)) {
    this->rettos.push_back(line);
  }
  log.close();
}