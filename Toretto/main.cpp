#include "src/include/CodeFileManager.h"
#include "src/include/Commander.h"
#include "src/include/FolderManager.h"
#include "src/include/GenericFileManager.h"
#include "src/include/ImageFileManager.h"
#include <filesystem>
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
  if (argc == 2) {
    Commander cmd = Commander(argv[1]);
    cmd.run();
  } else {

    int *date = new int[5];
    // std::cout << argv[1] << endl;
    string path = argv[2];
    while (!fs::exists(path)) {
      cout << "Path does not exist. Please enter a valid path: ";
      cin >> path;
    }
    // cout << "Path: " << path << endl;
    string command = argv[1];
    FolderManager *fm = new FolderManager(path);
    GenericFileManager *gfm = new GenericFileManager(date);
    ImageFileManager *ifm = new ImageFileManager(date);
    CodeFileManager *cfm = new CodeFileManager(date);
    Commander commander(command, path, date, fm, gfm, cfm, ifm);

    commander.run();
    commander.run("help");
    while (cin >> command) {
      commander.run(command);
    }
    delete fm;
    delete ifm;
    delete cfm;
    delete gfm;
    delete[] date;
  }
  return 0;
}
