#include "src/include/FolderManager.h"
#include "src/include/GenericFileManager.h"
#include "src/include/CodeFileManager.h"
#include "src/include/ImageFileManager.h"
#include <filesystem>
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
  int* date = new int[5];
  std::cout<<argv[1]<<endl;
  string path = argv[2];
  cout << "Path: " << path << endl;
  ImageFileManager ifm = ImageFileManager(path, date);
  ifm.getSize();
  // CodeFileManager cfm = CodeFileManager(path, date);
  // cfm.showInfo();


  delete [] date;
  return 0;
}
