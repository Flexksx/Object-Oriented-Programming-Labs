#include "include/Stater.h"

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
  fs::path rettoDir = path / ".retto";
  if (!fs::exists(rettoDir)) {
    fs::create_directory(rettoDir);
  }

  std::ofstream log(rettoDir / "rettolog.txt");

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

void Stater::updateLog(fs::path rettoPath, vector<string> &deletedFiles,
                       vector<string> &newFiles,
                       vector<pair<string, string>> &filesdates) {

  for (const auto &fileName : newFiles) {
    if (fs::exists(rettoPath / fileName)) {
      std::vector<int> dateComponents;
      this->gfm->setPath(rettoPath / fileName);
      this->date = this->gfm->getTimeFromEpoch();

      std::string dateString = "";
      for (int i = 0; i < 6; i++) {
        dateString += std::to_string(this->date[i]) + ((i != 5) ? "." : "");
      }

      filesdates.push_back({fileName, dateString});
    }
  }

  auto it = std::remove_if(
      filesdates.begin(), filesdates.end(), [&](const auto &entry) {
        return std::find(deletedFiles.begin(), deletedFiles.end(),
                         entry.first) != deletedFiles.end();
      });
  filesdates.erase(it, filesdates.end());
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

void Stater::deleteLog() {
  std::ofstream logFile;
  logFile.open(this->logFile, std::ios::trunc);
  logFile.close();
}

void Stater::deleteRetto(std::string name) {
  this->readRettos();
  auto rettoEntry =
      std::find_if(this->rettos.begin(), this->rettos.end(),
                   [&](const auto &entry) { return entry.second == name; });

  if (rettoEntry != this->rettos.end()) {
    fs::path rettoPath = rettoEntry->first;

    fs::remove_all(rettoPath / ".retto");

    this->rettos.erase(rettoEntry);

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

    std::ifstream rettolog(rettoPath / ".retto/rettolog.txt");
    std::string fileName;
    std::string dateString;
    std::vector<std::pair<string, string>> filesdates;
    std::vector<string> deletedFiles;
    std::vector<string> newFiles;

    while (rettolog >> fileName >> dateString) {
      filesdates.push_back({fileName, dateString});
    }

    std::vector<string> existingFileNames;
    for (const auto &entry : fs::directory_iterator(rettoPath)) {
      if (fs::is_directory(entry)) {
        continue;
      }
      existingFileNames.push_back(entry.path().filename().string());
    }

    std::vector<string> loggedFileNames;
    for (const auto &fileName : filesdates) {
      loggedFileNames.push_back(fileName.first);
    }

    this->detectDeleted(loggedFileNames, existingFileNames, deletedFiles);
    this->detectNew(loggedFileNames, existingFileNames, newFiles);
    this->detectMod(rettoPath, filesdates);
    this->updateLog(rettoPath, deletedFiles, newFiles, filesdates);

  } else {
    std::cerr << "Error: Retto '" << name << "' not found." << std::endl;
  }
}

void Stater::detectDeleted(const std::vector<std::string> &loggedFileNames,
                           const std::vector<std::string> &existingFileNames,
                           std::vector<std::string> &deletedFiles) {
  for (const auto &logFileName : loggedFileNames) {
    if (std::find(existingFileNames.begin(), existingFileNames.end(),
                  logFileName) == existingFileNames.end()) {
      deletedFiles.push_back(logFileName);
    }
  }
}

void Stater::detectNew(const std::vector<std::string> &loggedFileNames,
                       const std::vector<std::string> &existingFileNames,
                       std::vector<std::string> &newFiles) {

  for (const auto &exFileName : existingFileNames) {
    if (std::find(loggedFileNames.begin(), loggedFileNames.end(), exFileName) ==
        loggedFileNames.end()) {
      newFiles.push_back(exFileName);
    }
  }
}

void Stater::detectMod(fs::path rettoPath,
                       std::vector<std::pair<string, string>> &filesdates) {
  std::vector<std::pair<string, string>> updatedFilesdates;

  for (const std::pair<string, string> &fileDate : filesdates) {
    fs::path filePath = rettoPath / fileDate.first;

    if (fs::exists(filePath)) {
      this->gfm->setPath(filePath);
      this->date = this->gfm->getTimeFromEpoch();

      bool fileChanged = false;
      std::vector<int> dateComponents;
      std::stringstream dateStream(fileDate.second);
      std::string dateSegment;

      while (std::getline(dateStream, dateSegment, '.')) {
        dateComponents.push_back(std::stoi(dateSegment));
      }

      for (int i = 0; i < 6; i++) {
        if (dateComponents[i] != this->date[i]) {
          fileChanged = true;
          break;
        }
      }

      if (fileChanged) {
        cout << fileDate.first << " - File Changed." << endl;
      } else {
        cout << fileDate.first << " - File Not Changed." << endl;
      }

      string dateString = "";
      for (int i = 0; i < 6; i++) {
        dateString += std::to_string(this->date[i]) + ((i != 5) ? "." : "");
      }

      updatedFilesdates.push_back({fileDate.first, dateString});
    } else {
      cout << fileDate.first << " - File Deleted." << endl;
    }
  }

  filesdates = updatedFilesdates;
}

void Stater::commitChanges(fs::path rettoPath) {}
void Stater::writeInitLog(fs::path path, string name) {
  this->readRettos();

  if (path.empty() || name.empty()) {
    cout << "Invalid retto entry. Name and path must be provided." << endl;
    return;
  }

  auto duplicateEntry = std::find_if(
      this->rettos.begin(), this->rettos.end(), [&](const auto &entry) {
        return entry.first == path || entry.second == name;
      });

  if (duplicateEntry != this->rettos.end()) {
    cout << "Rettository already exists." << endl;
    return;
  }

  this->addRetto(path, name);
  this->writeLog(path);
  this->writeRettos();
}

void Stater::addRetto(fs::path filePath, string name) {
  std::pair<fs::path, string> rettoEntry = {filePath, name};
  this->rettos.push_back(rettoEntry);
}

void Stater::readRettos() {
  this->rettos.clear();

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

void Stater::guardRetto(std::string rettoName) {
  auto guardFunction = [this, rettoName]() {
    while (true) {
      std::this_thread::sleep_for(std::chrono::seconds(5));

      // Check for changes in the retto
      std::vector<std::pair<string, string>> filesdates;
      std::vector<string> deletedFiles;
      std::vector<string> newFiles;

      fs::path rettoPath = getRettoPath(rettoName);

      if (!rettoPath.empty()) {
        std::ifstream rettolog(rettoPath / ".retto/rettolog.txt");
        std::string fileName;
        std::string dateString;

        while (rettolog >> fileName >> dateString) {
          filesdates.push_back({fileName, dateString});
        }

        std::vector<string> existingFileNames;
        for (const auto &entry : fs::directory_iterator(rettoPath)) {
          if (fs::is_directory(entry)) {
            continue;
          }
          existingFileNames.push_back(entry.path().filename().string());
        }

        std::vector<string> loggedFileNames;
        for (const auto &fileName : filesdates) {
          loggedFileNames.push_back(fileName.first);
        }

        this->detectDeleted(loggedFileNames, existingFileNames, deletedFiles);
        this->detectNew(loggedFileNames, existingFileNames, newFiles);
        this->detectMod(rettoPath, filesdates);
        // this->updateLog(rettoPath, deletedFiles, newFiles, filesdates);
        if (!deletedFiles.empty() || !newFiles.empty()) {
          std::cout << "Changes detected in retto: " << rettoName << std::endl;
          std::cout << "Deleted files:" << std::endl;
          for (const auto &deletedFile : deletedFiles) {
            std::cout << " - " << deletedFile << std::endl;
          }
          std::cout << "New files:" << std::endl;
          for (const auto &newFile : newFiles) {
            std::cout << " - " << newFile << std::endl;
          }
        }
      }
    }
  };

  std::thread guardThread(guardFunction);

  guardThread.detach();
}