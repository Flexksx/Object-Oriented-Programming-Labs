#include "include/Stater.h"
#include <algorithm>
#include <filesystem>
#include <fstream>
#include <ios>
#include <iostream>
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

void Stater::listRettos() {
  for (auto &retto : this->rettos) {
    std::cout << retto.second << " " << retto.first.string() << std::endl;
  }
}

void Stater::readLog() {}

void Stater::updateLog() {}

void Stater::deleteLog() {
  std::ofstream logFile;
  logFile.open(this->logFile, std::ios::trunc);
  logFile.close();
}

void Stater::addRetto(fs::path filePath, std::string name) {
  std::pair<fs::path, std::string> rettoEntry = {filePath, name};
  this->rettos.push_back(rettoEntry);
}

void Stater::deleteRetto(fs::path filePath) {
  this->rettos.erase(
      std::remove_if(this->rettos.begin(), this->rettos.end(),
                     [&](const std::pair<fs::path, std::string> &entry) {
                       return entry.first == filePath;
                     }),
      this->rettos.end());
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

    // Extract the file name and date
    iss >> fileName;
    std::getline(iss, dateStr);

    // Remove leading whitespace from the date string
    dateStr = dateStr.substr(1);

    // Convert the date string to integer array
    int fileDate[6] = {0};
    std::stringstream dateStream(dateStr);
    std::string dateSegment;
    int i = 0;
    while (std::getline(dateStream, dateSegment, '.')) {
      fileDate[i] = std::stoi(dateSegment);
      std::cout << fileDate[i];
      i++;
    }

    // Compare dates using generic file manager's getDate() method
    this->gfm->setPath(fs::path(targetPath) / fileName);
    int *currentDate = this->gfm->getDate();
    bool modified = false;
    for (int j = 0; j < 6; j++) {
      if (currentDate[j] != fileDate[j]) {
        modified = true;
        break;
      }
    }
    if (modified) {
      std::cout << fileName << " No changes." << std::endl;
    } else {
      std::cout << fileName << " Changed." << std::endl;
    }
  }
  rettoLog.close();
  this->writeRettos();
}

void Stater::writeInitLog(fs::path path, std::string name) {
  this->readRettos();

  // Check if the newEntry is "full"
  if (path.empty() || name.empty()) {
    std::cout << "Invalid retto entry. Name and path must be provided."
              << std::endl;
    return;
  }

  // Check if newEntry already exists in rettos
  auto duplicateEntry = std::find_if(
      this->rettos.begin(), this->rettos.end(), [&](const auto &entry) {
        return entry.first == path || entry.second == name;
      });

  if (duplicateEntry != this->rettos.end()) {
    std::cout << "Rettository already exists." << std::endl;
    return;
  }

  // Add the new entry to the vector
  this->addRetto(path, name);
  this->writeRettos();
}

void Stater::readRettos() {
  this->rettos.clear(); // Clear the vector before reading from the file

  std::ifstream log;
  log.open(this->logFile);
  if (!log.is_open()) {
    std::cerr << "Error opening log file for reading." << std::endl;
    return;
  }

  std::string line;
  while (std::getline(log, line)) {
    std::string name, pathString;
    std::getline(log, name);
    std::getline(log, pathString);
    fs::path filePath = pathString;
    if (filePath.empty() || name.empty()) {
      continue;
    } else {
      this->rettos.push_back({filePath, name});
    }
  }
  log.close();

  for (const auto &p : this->rettos) {
    std::cout << p.second << std::endl << p.first.string() << std::endl;
  }
}

void Stater::writeRettos() {
  this->listRettos(); // Optionally print the rettos for debugging

  this->deleteLog(); // Optionally delete the log file for debugging

  std::ofstream log(this->logFile);
  if (!log.is_open()) {
    std::cerr << "Error opening log file for writing." << std::endl;
    return;
  }

  for (const auto &p : this->rettos) {
    log << p.second << std::endl << p.first.string() << std::endl;
  }

  log.close();
}
