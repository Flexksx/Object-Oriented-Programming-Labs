#include "include/Stater.h"
#include "include/Retto.h"
#include <algorithm>
#include <filesystem>
#include <fstream>
#include <ios>
#include <iostream>
#include <map>
#include <string>

namespace fs = std::filesystem;
using std::string, std::cout, std::endl;

Stater::Stater(int *date, fs::path logFile, GenericFile *gfm, ImageFile *ifm,
               CodeFile *cfm, Folder *fm) {
  this->cfm = cfm;
  this->fm = fm;
  this->gfm = gfm;
  this->ifm = ifm;
  this->date = date;
  this->logFile = logFile;
}

void Stater::writeLog(fs::path path) {
  std::ofstream log;
  fs::path rettoLogPath = path / "rettolog.txt";
  log.open(rettoLogPath);
  for (const auto &entry : fs::directory_iterator(path)) {
    if (entry.is_directory())
      continue;
    fs::path file = entry.path().filename();
    log << file.c_str() << " ";
    this->gfm->setPath(path / file);
    this->date = this->gfm->getTimeFromEpoch();
    for (int i = 0; i < 6; i++)
      log << this->date[i] << ((i != 5) ? '.' : ' ');
    log << endl;
  }
}

void Stater::listRettos() {
  this->readRettos();
  for (auto &retto : this->rettos) {
    cout << retto.second << " " << retto.first.string() << endl;
  }
}

void Stater::readLog() {}

void Stater::updateLog() {}

void Stater::deleteLog() {
  std::ofstream logFile;
  logFile.open(this->logFile, std::ios::trunc);
  logFile.close();
}

void Stater::deleteRetto(fs::path filePath) {
  this->rettos.erase(
      std::remove_if(this->rettos.begin(), this->rettos.end(),
                     [&](const std::pair<fs::path, string> &entry) {
                       return entry.first == filePath;
                     }),
      this->rettos.end());
}

void Stater::commit(std::string name) {
  this->readRettos();
  auto rettoEntry =
      std::find_if(this->rettos.begin(), this->rettos.end(),
                   [&](const auto &entry) { return entry.second == name; });
  if (rettoEntry != this->rettos.end()) {
    fs::path rettoPath = rettoEntry->first;
    std::cout << "Committing changes for retto: " << name
              << " at path: " << rettoPath.string() << std::endl;
    this->commitChanges(rettoPath);
    this->detectNewDeleted(rettoPath);
  } else {
    std::cerr << "Error: Retto '" << name << "' not found." << std::endl;
  }
}

void Stater::detectNewDeleted(fs::path rettopath){

}



void Stater::commitChanges(fs::path rettoPath) {
  std::ifstream rettolog;
  rettolog.open(rettoPath / "rettolog.txt");
  std::string fileName;
  std::string dateString;
  std::vector<std::pair<string, string>> filesdates;

  while (rettolog >> fileName) {
    rettolog >> dateString;
    cout << fileName;
    std::vector<int> dateComponents;
    std::stringstream dateStream(dateString);
    std::string dateSegment;

    while (std::getline(dateStream, dateSegment, '.')) {
      dateComponents.push_back(std::stoi(dateSegment));
    }

    this->gfm->setPath(rettoPath / fileName);
    this->date = this->gfm->getTimeFromEpoch();

    for (int i = 0; i < 6; i++) {
      if (dateComponents[i] != this->date[i]) {
        cout << " - File Changed." << endl;
        break;
      } else if (i == 5) {
        cout << " - File Not Changed." << endl;
      }
    }

    dateString = "";
    for (int i = 0; i < 6; i++) {
      dateString += std::to_string(this->date[i]) + ((i != 5) ? "." : "");
    }

    filesdates.push_back({fileName, dateString});
    continue;
  }
  rettolog.close();
  std::ofstream clearRettolog(rettoPath / "rettolog.txt",
                              std::ofstream::out | std::ofstream::trunc);
  clearRettolog.close();
  std::ofstream rettologOut(rettoPath / "rettolog.txt", std::ofstream::app);

  for (const auto &fileDate : filesdates) {
    rettologOut << fileDate.first << " " << fileDate.second << endl;
  }
  rettologOut.close();
}

void Stater::writeInitLog(fs::path path, string name) {
  this->readRettos();

  // Check if the newEntry is "full"
  if (path.empty() || name.empty()) {
    cout << "Invalid retto entry. Name and path must be provided." << endl;
    return;
  }

  // Check if newEntry already exists in rettos
  auto duplicateEntry = std::find_if(
      this->rettos.begin(), this->rettos.end(), [&](const auto &entry) {
        return entry.first == path || entry.second == name;
      });

  if (duplicateEntry != this->rettos.end()) {
    cout << "Rettository already exists." << endl;
    return;
  }

  // Add the new entry to the vector
  this->addRetto(path, name);
  this->writeLog(path);
  this->writeRettos();
}

// Write an entry to the log file
void Stater::addRetto(fs::path filePath, string name) {
  std::pair<fs::path, string> rettoEntry = {filePath, name};
  this->rettos.push_back(rettoEntry);
}

// Read rettos from the log file
void Stater::readRettos() {
  this->rettos.clear(); // Clear the vector before reading from the file

  std::ifstream log;
  log.open(this->logFile);
  if (!log.is_open()) {
    std::cerr << "Error opening log file for reading." << endl;
    return;
  }

  string line;
  while (std::getline(log, line)) {
    std::istringstream iss(line);
    string name, pathString;
    iss >> name >> pathString;
    fs::path filePath = pathString;
    if (filePath.empty() || name.empty()) {
      continue;
    } else {
      this->rettos.push_back({filePath, name});
    }
  }
  log.close();
}

// Write rettos to the log file
void Stater::writeRettos() {
  this->listRettos(); // Optionally print the rettos for debugging

  this->deleteLog(); // Optionally delete the log file for debugging

  std::ofstream log(this->logFile);
  if (!log.is_open()) {
    std::cerr << "Error opening log file for writing." << endl;
    return;
  }

  for (const auto &p : this->rettos) {
    log << p.second << ' ' << p.first.string() << endl;
  }

  log.close();
}
