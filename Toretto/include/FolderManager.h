#ifndef FOLDER_MANAGER_H
#define FOLDER_MANAGER_H

#include <filesystem>
#include <iostream>

using namespace std;

class FolderManager {
private:
    string path;
public:
    FolderManager(string _path);
    void listAllFiles(string path, int depth); // Updated function signature
    void listAllFiles();
};

#endif
