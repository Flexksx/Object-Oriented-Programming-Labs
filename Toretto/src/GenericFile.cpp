#include "include/GenericFile.h"


namespace fs = std::filesystem;

GenericFile::GenericFile(std::string _filePath, int *_date) {
  this->filePath = _filePath;
  this->date = _date;
}

GenericFile::GenericFile(int *_date) { this->date = _date; }

void GenericFile::setPath(fs::path _path) { this->filePath = _path; }

std::string GenericFile::getFileExtension() {
  return this->filePath.extension();
}
void GenericFile::showInfo() {
  std::cout << "This method is used only to be inherited and overriden."
            << std::endl;
}
fs::file_time_type GenericFile::lastTimeModified() {
  fs::file_time_type ftime = fs::last_write_time(this->filePath);
  std::chrono::time_point timePoint = ftime;
  return timePoint;
}

int *GenericFile::getDate() {
  this->getTimeFromEpoch();
  return this->date;
}

int *GenericFile::getTimeFromEpoch() {
  int *date = new int[5];
  std::filesystem::file_time_type lastModified = this->lastTimeModified();
  auto systemTime =
      std::chrono::clock_cast<std::chrono::system_clock>(lastModified);
  std::time_t epochTime = std::chrono::system_clock::to_time_t(systemTime);
  std::time_t time = static_cast<std::time_t>(epochTime);
  std::tm *timeInfo = std::localtime(&time);

  date[0] = timeInfo->tm_year + 1900;
  date[1] = timeInfo->tm_mon + 1;
  date[2] = timeInfo->tm_mday;
  date[3] = timeInfo->tm_hour;
  date[4] = timeInfo->tm_min;
  date[5] = timeInfo->tm_sec;
  return date;
}

fs::path GenericFile::getPath() { return this->filePath; }

void GenericFile::showLastTimeModified() {
  int *date = this->getTimeFromEpoch();
  std::cout << "Last time modified: ";
  for (int i = 0; i < 5; i++) {
    if (i < 2)
      std::cout << date[i] << "-";
    else if (i == 2)
      std::cout << date[i] << " ";
    else if (i > 2 && i < 4)
      std::cout << date[i] << ":";
    else
      std::cout << date[i];
  }
  std::cout << std::endl;
  delete[] date;
}

GenericFile::~GenericFile() {}
