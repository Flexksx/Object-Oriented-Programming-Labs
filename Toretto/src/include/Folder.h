#ifndef FOLDER_MANAGER_H
#define FOLDER_MANAGER_H

#include <filesystem>
#include <iostream>

namespace fs = std::filesystem;

class Folder {
private:
    fs::path path;
public:
    Folder(fs::path _path);
    void listAllFiles(fs:: path, int depth); // Updated function signature
    void listAllFiles();
    fs::path getPath();
    void setPath(fs::path _path);
};

#endif
