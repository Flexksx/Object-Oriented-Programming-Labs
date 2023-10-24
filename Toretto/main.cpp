// #include "include/FileManager.h"
#include "/home/cristi/Documents/GitHub/LabsOOP/Toretto/include/FileManager.h"
#include "/home/cristi/Documents/GitHub/LabsOOP/Toretto/include/FolderManager.h"
#include <filesystem>
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
  if (argc < 2) {
    cerr << "Usage: " << argv[0] << " <path>" << endl;
    return 1;
  }

  string path = argv[1];
  cout << "Path: " << path << endl;
  FolderManager folderManager = FolderManager(path);
  folderManager.listAllFiles();
  FileManager fileManager = FileManager(path);
  cout<<fileManager.getFileExtension();
  fileManager.lastTimeModified();
  return 0;
}
