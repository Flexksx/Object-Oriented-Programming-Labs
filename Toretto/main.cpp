#include "include/FolderManager.h"
#include <filesystem>
#include <iostream>

using namespace std;

int main() {
  FolderManager folderManager =
      FolderManager("/home/cristi/Documents/GitHub/LabsOOP/UniversityManagement");
  folderManager.listAllFiles();
  return 0;
}
