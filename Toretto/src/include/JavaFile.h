#ifndef JAVA_FILE_MANAGER_H
#define JAVA_FILE_MANAGER_H

#include "CodeFile.h"
#include <filesystem>
#include <iostream>

namespace fs = std::filesystem;

class JavaFile : public CodeFile {
public:
  JavaFile(fs::path _filePath, int *date);
  int getNrOfClasses() override;
};

#endif