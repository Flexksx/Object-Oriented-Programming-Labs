#ifndef PY_FILE_MANAGER_H
#define PY_FILE_MANAGER_H

#include "GenericFile.h"
#include "CodeFile.h"
#include <filesystem>
#include <iostream>

namespace fs = std::filesystem;

class PyFile : public CodeFile {
public:
  PyFile(fs::path _filePath, int* date);
  int getNrOfClasses() override;
};

#endif