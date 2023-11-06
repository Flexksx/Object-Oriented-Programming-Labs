#include "include/Stater.h"
#include <algorithm>
#include <filesystem>
#include <fstream>
#include <ios>
#include <istream>
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
    if (std::find_if(this->rettos.begin(), this->rettos.end(),
                     [&](const std::map<fs::path, std::string> &m) {
                       return m.find(this->fm->getPath()) != m.end();
                     }) != this->rettos.end()) {
      std::cout << "This is already a Rettository." << std::endl;
      return;
    }
  }
  std::ofstream olog;
  olog.open(this->logFile, std::ios::app);
  std::cout << "Give a name to this Rettository: ";
  std::string rettoName;
  std::cin >> rettoName;
  std::map<fs::path, std::string> rettoEntry;
  rettoEntry[this->fm->getPath()] = rettoName;
  this->rettos.push_back(rettoEntry);
  olog << rettoName << std::endl << this->fm->getPath().string() << std::endl;
  olog.close();
  writeRettos();
}

void Stater::readLog() {}

void Stater::updateLog() {}

void Stater::deleteLog() {}

void Stater::readRettos() {
  std::ifstream log;
  log.open(this->logFile);
  std::string line;
  while (std::getline(log, line)) {
    std::string rettoName, pathString;
    std::getline(log, rettoName);
    std::getline(log, pathString);
    fs::path filePath = pathString;
    std::map<fs::path, std::string> rettoEntry;
    rettoEntry[filePath] = rettoName;
    this->rettos.push_back(rettoEntry);
  }
  log.close();
  for (auto &m : this->rettos) {
    for (auto &p : m) {
      std::cout << p.second << std::endl << p.first << std::endl;
    }
  }
}

void Stater::writeRettos() {
  std::ofstream rettoLog;
  fs::path directoryPath = this->logFile.parent_path();
  fs::path rettoLogPath = directoryPath / "rettolog.txt";
  rettoLog.open(rettoLogPath);
  for (auto &m : this->rettos) {
    for (auto &p : m) {
      rettoLog << p.first.string() << " " << p.second << std::endl;
      if (fs::is_directory(p.first)) {
        continue;
      }
    }
  }
  rettoLog.close();
}

void Stater::addRetto(fs::path filePath, std::string name) {
  std::map<fs::path, std::string> rettoEntry;
  rettoEntry[filePath] = name;
  this->rettos.push_back(rettoEntry);
  writeRettos();
}

void Stater::deleteRetto(fs::path filePath) {
  this->rettos.erase(
      std::remove_if(this->rettos.begin(), this->rettos.end(),
                     [&](const std::map<fs::path, std::string> &m) {
                       return m.find(filePath) != m.end();
                     }),
      this->rettos.end());
  writeRettos();
}

void Stater::commit(std::string name) {
  std::ifstream log;
  log.open(this->logFile);
  std::string line;
  std::string targetPath;
  bool found = false;
  while (std::getline(log, line)) {
    if (line == name) {
      found = true;
      break;
    }
  }
  if (!found) {
    std::cerr << "Name not found in the log file." << std::endl;
    return;
  }

  // Extract the path for the found name
  std::getline(log, targetPath);

  // Construct the path to rettolog.txt
  fs::path rettoLogPath = fs::path(targetPath) / "rettolog.txt";
  std::ifstream rettoLog;
  rettoLog.open(rettoLogPath);
  std::string fileLine;
  while (std::getline(rettoLog, fileLine)) {
    std::istringstream iss(fileLine);
    std::string fileName;
    std::string dateStr;
    iss >> fileName >> dateStr;

    // Convert the date string to integer array
    int fileDate[6] = {0};
    std::stringstream dateStream(dateStr);
    std::string dateSegment;
    int i = 0;
    while (std::getline(dateStream, dateSegment, '.')) {
      fileDate[i] = std::stoi(dateSegment);
      i++;
    }

    // Compare dates using generic file manager's getDate() method
    this->gfm->setPath(fs::path(targetPath) / fileName);
    int *currentDate = this->gfm->getDate();
    bool modified = false;
    for (int j = 0; j < 6; j++) {
      if (currentDate[j] > fileDate[j]) {
        modified = true;
        break;
      }
    }
    if (modified) {
      std::cout << fileName << " has been modified since the last commit." << std::endl;
    } else {
      std::cout << fileName << " has not been modified since the last commit." << std::endl;
    }
  }
  rettoLog.close();
}

