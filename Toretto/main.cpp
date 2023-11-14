#include "src/include/CodeFile.h"
#include "src/include/Commander.h"
#include "src/include/Folder.h"
#include "src/include/GenericFile.h"
#include "src/include/ImageFile.h"
#include "src/include/Stater.h"
#include <filesystem>
#include <iostream>

using std::string, std::cout, std::cin;
namespace fs = std::filesystem;

int main(int argc, char *argv[]) {
  int *date = new int[6];
  Folder *fm = new Folder();
  GenericFile *gfm = new GenericFile(date);
  ImageFile *ifm = new ImageFile(date);
  CodeFile *cfm = new CodeFile(date);
  Stater *st = new Stater(date, "log.txt", gfm, ifm, cfm, fm);
  Commander *comm = new Commander(date, fm, st, gfm, cfm, ifm);
  if (argc == 2) {
    string command = argv[1];
    if (command == "run") {
      comm->run();
    } else if (command == "listall") {
      st->listRettos();
    } else {
      comm->giveCommand(command);
      comm->run(command);
    }
  } else if (argc == 3) {
    string command = argv[1];
    if (command == "info") {
      if (fs::exists(argv[2])) {
        comm->sl(argv[2]);
        comm->info();
      } else{
        cout << "Path does not exist." << std::endl;
        // TODO: make function for retto info
      }

    } else if (command == "detect") {
      fs::path retto = argv[2];
      st->detectNewDeleted(retto);
    }
    if (command == "init") {
      string name;
      cout << "Give a name to this Rettository: ";
      string rettoName;
      cin >> rettoName;
      comm->sl(argv[2]);
      comm->init(rettoName);
    }
    if (command == "commit") {
      string rettoName = argv[2];
      comm->commit(rettoName);
    }
  } else if (argc == 4) {
    string command = argv[1];
    string path = argv[2];
    string name = argv[3];
    if (command == "init") {
      comm->sl(path);
      comm->init(name);
    }
  }
  return 0;
}