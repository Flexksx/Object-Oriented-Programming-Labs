#include "src/include/CodeFileManager.h"
#include "src/include/Commander.h"
#include "src/include/FolderManager.h"
#include "src/include/GenericFileManager.h"
#include "src/include/ImageFileManager.h"
#include <filesystem>
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
  if (argc == 1) {
    Commander cmd = Commander(argv[1]);
    cmd.run();
  } else {

    int *date = new int[5];
    std::cout << argv[1] << endl;
    string path = argv[2];
    cout << "Path: " << path << endl;

    FolderManager *fm = new FolderManager(path);
    GenericFileManager *gfm = new GenericFileManager(date);
    ImageFileManager *ifm = new ImageFileManager(date);
    CodeFileManager *cfm = new CodeFileManager(date);
    Commander commander(argv[1], path, date, fm, cfm, ifm);

    commander.run();

    delete fm;
    delete ifm;
    delete cfm;
    delete gfm;
    delete[] date;
  }
  return 0;
}
