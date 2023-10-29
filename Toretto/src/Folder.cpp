#include "include/Folder.h"
#include <filesystem>
#include <iostream>

namespace fs = std::filesystem;

Folder::Folder(fs::path path) { this->path = path; }

void Folder::setPath(fs::path _path) { this->path = _path; }

void Folder::listAllFiles(fs::path path, int depth) {
  if (!fs::exists(path)) {
    std::cout << "Path does not exist." << std::endl;
    return;
  }

  if (!fs::is_directory(path)) {
    std::cout << "Provided path is not a directory." << std::endl;
    return;
  }

  if (depth > 3) {
    return;
  }

  for (const auto &entry : fs::directory_iterator(path)) {
    for (int i = 0; i < depth; ++i) {
      std::cout << "|   ";
    }
    if (fs::is_directory(entry.path())) {
      std::cout << "|---" << entry.path().filename() << " [Directory]"
                << std::endl;
      listAllFiles(entry.path(),
                   depth + 1); // Increase the depth for subdirectories
    } else {
      std::cout << "|---" << entry.path().filename() << std::endl;
    }
  }
}

void Folder::listAllFiles() {
  if (!fs::exists(this->path)) {
    std::cout << "Path does not exist." << std::endl;
    return;
  }

  if (!fs::is_directory(this->path)) {
    std::cout << "Provided path is not a directory." << std::endl;
    return;
  }

  for (const auto &entry : fs::directory_iterator(this->path)) {
    std::cout << "|---" << entry.path().filename() << std::endl;
    if (fs::is_directory(entry.path())) {
      listAllFiles(entry.path(),
                   1); // Start at depth 1 for the first-level directories
    }
  }
}

fs::path Folder::getPath() { return this->path; }