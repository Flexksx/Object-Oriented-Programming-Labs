#include "/home/cristi/Documents/GitHub/LabsOOP/Toretto/include/FolderManager.h"
#include "/home/cristi/Documents/GitHub/LabsOOP/Toretto/include/GenericFileManager.h"
#include "include/GenericFileManager.h"
#include <filesystem>
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
  if (argc < 2) {
    cerr << "Usage: " << argv[0] << " <path>" << endl;
    return 1;
  }
  std::cout<<argv[0]<<endl;
  string path = argv[1];
  cout << "Path: " << path << endl;
  return 0;
}
