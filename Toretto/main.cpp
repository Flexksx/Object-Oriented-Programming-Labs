#include "src/include/CodeFile.h"
#include "src/include/Commander.h"
#include "src/include/Folder.h"
#include "src/include/GenericFile.h"
#include "src/include/ImageFile.h"
#include <filesystem>
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
  // int *date = new int[5];
  // ImageFile *ifm = new
  // ImageFile("/home/cristi/Documents/GitHub/LabsOOP/Labs1OOP/dom.png", date);
  // ifm->showInfo();
  if (argc == 2) {
    Commander cmd = Commander(argv[1]);
    cmd.run();
  } else {

    int *date = new int[5];
    // std::cout << argv[1] << endl;
    string path = argv[2];
    while (!fs::exists(path)) {
      cout << "Path does not exist. Please enter a valid path: (Main)";
      cin >> path;
    }
    // std::cout << "Path: " << path << endl;
    string command = argv[1];
    // std::cout<<command;
    Folder *fm = new Folder(path);
    GenericFile *gfm = new GenericFile(date);
    ImageFile *ifm = new ImageFile(date);
    CodeFile *cfm = new CodeFile(date);
    Commander commander(command, path, date, fm, gfm, cfm, ifm);
    std::cout << "Hello!";
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
