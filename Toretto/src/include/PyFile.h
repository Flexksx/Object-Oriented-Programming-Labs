#ifndef PY_FILE_MANAGER_H
#define PY_FILE_MANAGER_H

#include "CodeFile.h"
#include "GenericFile.h"
#include <filesystem>
#include <fstream>
#include <iostream>

namespace fs = std::filesystem;

class PyFile : public CodeFile {
public:
  PyFile(fs::path _filePath, int *date);
  int getNrOfClasses() override;
  int getNrOfMethods() override;
};

#endif