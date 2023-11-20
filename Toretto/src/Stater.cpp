#include "include/Stater.h"
#include "include/Retto.h"
#include <algorithm>
#include <filesystem>
#include <fstream>
#include <ios>
#include <iostream>
#include <map>
#include <string>
#include <vector>

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
  // Create the .retto directory if it doesn't exist
  fs::path rettoDir = path / ".retto";
  if (!fs::exists(rettoDir)) {
    fs::create_directory(rettoDir);
  }

  // Open the rettolog.txt file
  std::ofstream log(rettoDir / "rettolog.txt");

  // Write file names and dates to rettolog.txt
  for (const auto &entry : fs::directory_iterator(path)) {
    if (entry.is_directory())
      continue;

    fs::path file = entry.path().filename();
    log << file.c_str() << " ";
    this->gfm->setPath(path / file);
    this->date = this->gfm->getTimeFromEpoch();
    for (int i = 0; i < 6; i++)
      log << this->date[i] << ((i != 5) ? '.' : ' ');
    log << std::endl;
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

void Stater::deleteRetto(std::string name) {
    this->readRettos();
    auto rettoEntry = std::find_if(
        this->rettos.begin(), this->rettos.end(),
        [&](const auto &entry) { return entry.second == name; });

    if (rettoEntry != this->rettos.end()) {
        fs::path rettoPath = rettoEntry->first;

        // Remove the .retto folder
        fs::remove_all(rettoPath / ".retto");

        // Erase the retto entry from the vector
        this->rettos.erase(rettoEntry);

        // Update the rettos logfile
        this->writeRettos();
    } else {
        std::cerr << "Error: Retto '" << name << "' not found." << std::endl;
    }
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
    // this->detectNewDeleted(rettoPath);
  } else {
    std::cerr << "Error: Retto '" << name << "' not found." << std::endl;
  }
}

void Stater::commitChanges(fs::path rettoPath) {
  std::ifstream rettolog;
  rettolog.open(rettoPath / ".retto/rettolog.txt");
  std::string fileName;
  std::string dateString;
  std::vector<std::pair<string, string>> filesdates;

  while (rettolog >> fileName) {
    rettolog >> dateString;

    // Skip directories
    fs::path filePath = rettoPath / fileName;
    if (fs::is_directory(filePath)) {
      continue;
    }

    std::vector<int> dateComponents;
    std::stringstream dateStream(dateString);
    std::string dateSegment;

    while (std::getline(dateStream, dateSegment, '.')) {
      dateComponents.push_back(std::stoi(dateSegment));
    }
    if (fs::exists(filePath)) {
      this->gfm->setPath(filePath);
      this->date = this->gfm->getTimeFromEpoch();
      for (int i = 0; i < 6; i++) {
        if (dateComponents[i] != this->date[i]) {
          cout << fileName << " - File Changed." << endl;
          break;
        } else if (i == 5) {
          cout << fileName << " - File Not Changed." << endl;
        }
      }

      dateString = "";
      for (int i = 0; i < 6; i++) {
        dateString += std::to_string(this->date[i]) + ((i != 5) ? "." : "");
      }

      filesdates.push_back({fileName, dateString});
      continue;
    }
  }

  // Detect new and deleted files
  std::vector<string> existingFileNames;
  for (const auto &entry : fs::directory_iterator(rettoPath)) {
    // Skip directories
    if (fs::is_directory(entry)) {
      continue;
    }
    existingFileNames.push_back(entry.path().filename().string());
  }

  std::vector<string> loggedFileNames;
  for (const auto &fileName : filesdates) {
    loggedFileNames.push_back(fileName.first);
  }

  // Identify deleted files
  std::vector<string> deletedFiles;
  for (const auto &logFileName : loggedFileNames) {
    if (std::find(existingFileNames.begin(), existingFileNames.end(),
                  logFileName) == existingFileNames.end()) {
      deletedFiles.push_back(logFileName);
    }
  }

  // Identify new files
  std::vector<string> newFiles;
  for (const auto &exFileName : existingFileNames) {
    if (std::find(loggedFileNames.begin(), loggedFileNames.end(), exFileName) ==
        loggedFileNames.end()) {
      newFiles.push_back(exFileName);
    }
  }

  // Print detected changes
  if (!deletedFiles.empty()) {
    std::cout << "Deleted files:" << std::endl;
    for (const auto &fileName : deletedFiles) {
      std::cout << " - " << fileName << std::endl;
    }
  }

  if (!newFiles.empty()) {
    std::cout << "New files:" << std::endl;
    for (const auto &fileName : newFiles) {
      std::cout << " - " << fileName << std::endl;
    }
    for (const auto &fileName : newFiles) {
      if (fs::exists(rettoPath / fileName)) {
        std::vector<int> dateComponents;
        this->gfm->setPath(rettoPath / fileName);
        this->date = this->gfm->getTimeFromEpoch();

        dateString = "";
        for (int i = 0; i < 6; i++) {
          dateString += std::to_string(this->date[i]) + ((i != 5) ? "." : "");
        }

        filesdates.push_back({fileName, dateString});
        continue;
      }
    }
  }
  rettolog.close();
  std::ofstream clearRettolog(rettoPath / ".retto/rettolog.txt",
                              std::ofstream::out | std::ofstream::trunc);
  clearRettolog.close();
  std::ofstream rettologOut(rettoPath / ".retto/rettolog.txt",
                            std::ofstream::app);

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

void Stater::writeRettos() {
  // this->listRettos(); // Optionally print the rettos for debugging

  // this->deleteLog(); // Optionally delete the log file for debugging

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

void Stater::rettoInfo(std::string rettoName) {
  this->readRettos();
  auto rettoEntry = std::find_if(
      this->rettos.begin(), this->rettos.end(),
      [&](const auto &entry) { return entry.second == rettoName; });
  if (rettoEntry != this->rettos.end()) {
    fs::path rettoPath = rettoEntry->first;
    std::cout << "Retto: " << rettoName << std::endl;
    std::cout << "Path: " << rettoPath.string() << std::endl;
    std::cout << "Files:" << std::endl;
    for (const auto &entry : fs::directory_iterator(rettoPath)) {
      std::cout << " - " << entry.path().filename().string() << std::endl;
    }
  } else {
    std::cerr << "Error: Retto '" << rettoName << "' not found." << std::endl;
  }
}

fs::path Stater::getRettoPath(std::string rettoName) {
  this->readRettos();
  auto rettoEntry = std::find_if(
      this->rettos.begin(), this->rettos.end(),
      [&](const auto &entry) { return entry.second == rettoName; });
  if (rettoEntry != this->rettos.end()) {
    fs::path rettoPath = rettoEntry->first;
    return rettoPath;
  } else {
    std::cerr << "Error: Retto '" << rettoName << "' not found." << std::endl;
    return "";
  }
}