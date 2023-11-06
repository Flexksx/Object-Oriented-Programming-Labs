#include "include/Stater.h"
#include <algorithm>
#include <filesystem>
#include <fstream>
#include <ios>
#include <string>

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
  std::ifstream ilog;
  ilog.open(this->logFile);
  std::string checkPath;
  while (std::getline(ilog, checkPath)) {
    if (std::find(this->rettos.begin(), this->rettos.end(),
                  this->fm->getPath()) != this->rettos.end()) {
      std::cout << "This is already a Rettository." << std::endl;
      return;
    }
  }
  std::ofstream olog;
  olog.open(this->logFile, std::ios::app);
  std::cout<<"Give a name to this Rettository: ";
  std::string rettoName;
  std::cin>>rettoName;
  olog << this->fm->getPath().string()<<" "<<rettoName << std::endl;
  olog.close();
  std::ofstream rettoLog;
  fs::path rettoLogPath = this->fm->getPath() / "rettolog.txt";
  rettoLog.open(rettoLogPath);
  for (auto &p : fs::directory_iterator(this->fm->getPath())) {
    if (fs::exists(p)) {
      this->gfm->setPath(p);
      rettoLog << p.path().filename().string() << " ";
      int *date = this->gfm->getTimeFromEpoch();
      for (int i = 0; i < 5; i++) {
        if (i <= 3)
          rettoLog << date[i] << ".";
        else
          rettoLog << date[i];
      }
      rettoLog << std::endl;
    }
  }
}

void Stater::readRettos() {
  std::ifstream log;
  log.open(this->logFile);
  std::string line;
  while (std::getline(log, line)) {
    this->rettos.push_back(line);
  }
  log.close();
  for (auto &p : this->rettos) {
    std::cout << p << std::endl;
  }
}

void Stater::writeRettos() {
  std::ofstream rettoLog;
  fs::path directoryPath = this->logFile.parent_path();
  fs::path rettoLogPath = directoryPath / "rettolog.txt";
  rettoLog.open(rettoLogPath);
  for (auto &p : fs::directory_iterator(this->fm->getPath())) {
    if (fs::exists(p)) {
      this->gfm->setPath(p);
      rettoLog << this->gfm->getPath().string() << " ";
      int *date = this->gfm->getTimeFromEpoch();
      for (int i = 0; i < 5; i++) {
        if (i <= 3)
          rettoLog << date[i] << ".";
        else
          rettoLog << date[i];
      }
      rettoLog << std::endl;
    }
  }
  rettoLog.close();
}


void Stater::deleteRetto(){
  return;
}

void Stater::commit(){
  return;
}


