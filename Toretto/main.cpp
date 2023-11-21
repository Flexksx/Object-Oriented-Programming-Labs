#include "src/include/CodeFile.h"
#include "src/include/Commander.h"
#include "src/include/Folder.h"
#include "src/include/GenericFile.h"
#include "src/include/ImageFile.h"
#include "src/include/Stater.h"
#include <filesystem>
#include <iostream>

using std::string, std::cout, std::cin;

int main(int argc, char *argv[]) {
  int *date = new int[6];
  Folder *fm = new Folder();
  GenericFile *gfm = new GenericFile(date);
  ImageFile *ifm = new ImageFile(date);
  CodeFile *cfm = new CodeFile(date);
  Stater *st = new Stater(date, "log.txt", gfm, ifm, cfm, fm);
  Commander *comm = new Commander(date, fm, st, gfm, cfm, ifm);
  comm->cli(argc, argv);
  return 0;
}