#include "include/Commander.h"
#include "include/CodeFile.h"
#include "include/Folder.h"
#include "include/GenericFile.h"
#include "include/Stater.h"
#include <algorithm>
#include <atomic>
#include <chrono>
#include <cstring>
#include <filesystem>
#include <iostream>
#include <string>
#include <thread>
#include <vector>

using std::string, std::cout, std::cin, std::endl;

Commander::Commander(std::string _cmd, int *_date, Folder *_fm, Stater *_st,
                     GenericFile *_gfm, CodeFile *_cfm, ImageFile *_ifm) {
  this->st = _st;
  this->date = _date;
  this->cmd = _cmd;
  this->fm = _fm;
  this->cfm = _cfm;
  this->ifm = _ifm;
  this->gfm = _gfm;
  this->state = 0;
}

Commander::Commander(int *date, Folder *_fm, Stater *_st, GenericFile *_gfm,
                     CodeFile *_cfm, ImageFile *_ifm) {
  this->date = date;
  this->st = _st;
  this->fm = _fm;
  this->gfm = _gfm;
  this->ifm = _ifm;
  this->cfm = _cfm;
  this->state = 0;
}

Commander::Commander(std::string _cmd) { this->cmd = _cmd; }

void Commander::giveCommand(std::string _cmd) { this->cmd = _cmd; }

void Commander::mainloop() {
  std::string command;
  fs::path selectedRetto;
  std::map<std::string, std::thread> guardThreads;

  while (true) {
    std::cout << "> Enter a command: ";
    std::cin >> command;

    if (command == "exit") {
      // Stop all guard threads if running
      for (auto &thread : guardThreads) {
        if (thread.second.joinable()) {
          thread.second.join();
        }
      }
      break;
    } else if (command == "go") {
      this->go();
    } else if (command == "info") {
      this->info();
    } else if (command == "commit") {
      this->commit();
    } else if (command == "sl") {
      std::string filePathString;
      cout<<"Enter a path: ";
      cin>>filePathString;
      this->sl(filePathString);
    } else if (command == "help") {
      this->help();
    } else if (command == "init") {
      std::string name;
      std::cout << "Give a name to the Rettository: ";
      std::cin >> name;
      this->init(name);
    } else if (command == "listall") {
      this->st->listRettos();
    } else if (command == "rm") {
      std::string rettoName;
      std::cout << "Enter Retto name: ";
      std::cin >> rettoName;
      this->st->deleteRetto(rettoName);
    } else if (command == "guard") {
      std::string rettoName;
      std::cout << "Enter Retto name to guard: ";
      std::cin >> rettoName;

      // Stop the existing guard thread if running
      if (guardThreads.find(rettoName) != guardThreads.end() &&
          guardThreads[rettoName].joinable()) {
        guardThreads[rettoName].join();
        std::cout << "Guarding stopped for Retto: " << rettoName << std::endl;
      }

      // Start a new guard thread
      guardThreads[rettoName] =
          std::thread([this, rettoName]() { this->st->guardRetto(rettoName); });

      std::cout << "Guarding started for Retto: " << rettoName << std::endl;

    } else if (command == "unguard") {
      std::string rettoName;
      std::cout << "Enter Retto name to unguard: ";
      std::cin >> rettoName;

      // Stop the guard thread if running
      auto it = guardThreads.find(rettoName);
      if (it != guardThreads.end()) {
        if (it->second.joinable()) {
          it->second.join();
          std::cout << "Guarding stopped for Retto: " << rettoName << std::endl;
        } else {
          std::cout << "No active guard for Retto: " << rettoName << std::endl;
        }
        guardThreads.erase(it);

        // Optionally, start a new thread for guarding
        // guardThreads[rettoName] = std::thread([this, rettoName]() {
        // this->st->guardRetto(rettoName); });
      } else {
        std::cout << "No active guard for Retto: " << rettoName << std::endl;
      }
    }
  }
}

void Commander::cli(int argc, char *argv[]) {
  if (argc == 1) {
    this->mainloop();
  } else {
    string command = argv[1];
    if (command == "init") {
      if (argc == 3) {
        this->sl(argv[2]);
        string name;
        cout << "Give a name to the Rettository: ";
        cin >> name;
        this->init(name);
      } else if (argc == 4) {
        this->sl(argv[2]);
        this->init(argv[3]);
      } else {
        cout << "Invalid number of arguments." << endl;
        cout << "Usage: toretto init <path> <name>" << endl;
      }
    } else if (command == "commit") {
      if (argc == 3) {
        this->commit(argv[2]);
      } else {
        cout << "Invalid number of arguments." << endl;
        cout << "Usage: toretto commit <name>" << endl;
      }
    } else if (argc == 2) {
      if (command == "listall") {
        this->st->listRettos();
      } else if (command == "help") {
        this->help();
      }
    } else if (command == "info") {
      if (argc == 3) {
        if (fs::is_directory(argv[2]) || fs::is_regular_file(argv[2])) {
          this->sl(argv[2]);
          this->info();
        } else {
          this->st->rettoInfo(argv[2]);
        }
      } else if (argc == 4) {
        this->sl(this->st->getRettoPath(argv[2]) / argv[3]);
        this->info();
      } else {
        cout << "Invalid number of arguments." << endl;
        cout << "Usage: toretto info <directory path>     Lists all files and "
                "subdirectories of that path."
             << endl;
        cout << "       toretto info <file path>          Shows info about "
                "the file."
             << endl;
        cout << "toretto info <retto name>         Shows info about the retto."
             << endl;
        cout << "toretto info <retto name> <file> Shows info about the file in "
                "the retto."
             << endl;
      }
    } else if (command == "rm") {
      if (argc == 3) {
        this->st->deleteRetto(argv[2]);
      } else if (argc == 4) {
        this->sl(this->st->getRettoPath(argv[2]) / argv[3]);
        fs::remove(this->fm->getPath());
      } else {
        cout << "Invalid number of arguments." << endl;
        cout << "Usage: toretto rm <retto name>         Deletes the retto."
             << endl;
        cout << "       toretto rm <retto name> <file>  Deletes the file in "
                "the retto."
             << endl;
      }
    }
  }
}
void Commander::sl(fs::path filePath) {
  std::vector<std::string> programmingLanguages = {".c", ".cpp", ".java",
                                                   ".py"};

  if (filePath == "..") {
    // Move back one directory if ".." is entered
    if (fs::exists(this->fm->getPath().parent_path())) {
      this->fm->setPath(filePath.parent_path());
      std::cout << "Moved to: " << this->fm->getPath() << std::endl;
      this->state = 0;
    } else {
      std::cout << "You are currently not in a directory. Use the 'go' command "
                   "to choose one."
                << std::endl;
    }
  } else {
    // Concatenate the path with the file name
    filePath = this->fm->getPath().string() + "/" + filePath.string();

    if (fs::is_directory(filePath)) {
      // Move to the selected directory
      if (this->fm->getPath() == filePath) {
        std::cout << "Already in this directory." << std::endl;
      } else {
        this->fm->setPath(filePath);
        std::cout << "Moved to: " << this->fm->getPath().string() << std::endl;
        this->state = 0;
      }
    } else {
      // Select the file
      this->gfm->setPath(filePath);
      if (this->gfm->getFileExtension() == ".png") {
        this->ifm->GenericFile::setPath(filePath);
        std::cout << "Selected file: " << this->ifm->getPath().string()
                  << std::endl;
        this->fm->setPath(ifm->getPath().parent_path());
        this->state = 3;
      } else if (std::find(programmingLanguages.begin(),
                           programmingLanguages.end(),
                           this->gfm->getFileExtension()) !=
                 programmingLanguages.end()) {
        this->cfm->setPath(filePath);
        this->fm->setPath(cfm->getPath().parent_path());
        this->state = 2;
      } else {
        this->state = 1;
        std::cerr
            << "Unsupported file type. Selected with limited functionality."
            << std::endl;
      }
    }
  }
}

void Commander::go() {
  std::cout << "Enter a path:";
  std::string filePathString;
  std::cin >> filePathString;
  fs::path filePath = filePathString;

  while (!fs::is_directory(filePath) || !fs::exists(filePath)) {
    std::cout << "Path does not exist. Please enter a valid path: ";
    std::cin >> filePathString;
    filePath = filePathString;
  }

  this->fm->setPath(filePath);
  std::cout << "Moved to: " << this->fm->getPath().string() << std::endl;
}

void Commander::info() {
  if (this->state == 0) {
    if (fs::is_directory(this->fm->getPath())) {
      this->fm->listAllFiles();
    }
  } else if (this->state == 1) {
    if (fs::exists(this->gfm->getPath())) {
      std::cout << "Extension: " << this->gfm->getFileExtension() << std::endl;
      std::cout << "Last time modified: ";
      this->gfm->showLastTimeModified();
      std::cout << std::endl;
    } else {
      std::cerr << "File does not exist or an error happened." << std::endl;
    }
  } else if (this->state == 2) {
    if (fs::exists(this->cfm->getPath())) {
      this->cfm->showInfo();
    } else {
      std::cerr << "File does not exist or an error happened." << std::endl;
    }
  } else if (this->state == 3) {
    if (fs::exists(this->ifm->getPath())) {
      this->ifm->showInfo();
    } else {
      std::cerr << "File does not exist or an error happened." << std::endl;
    }
  }
}

void Commander::commit() {
  std::string rettoName;
  std::cout << "Enter Retto name: ";
  std::cin >> rettoName;
  this->st->commit(rettoName);
}

void Commander::init(std::string name) {
  this->st->writeInitLog(this->fm->getPath(), name);
}

void Commander::commit(std::string name) { this->st->commit(name); }

void Commander::help() {
  cout << R"(
  *   )                   )    )
` )  /(     (      (   ( /( ( /(
 ( )(_))(   )(    ))\  )\()))\()) (
(_(_()) )\ (()\  /((_)(_))/(_))/  )\
|_   _|((_) ((_)(_))  | |_ | |_  ((_)
  | | / _ \| '_|/ -_) |  _||  _|/ _ \
  |_| \___/|_|  \___|  \__| \__|\___/
                                                                              )";

  cout << "A simple version control system for your files." << endl;
  cout << "Usage: toretto <command> <path> <name>" << endl;
  cout << "Commands:" << endl;
  cout << "  init <path> <name>  Initializes a Rettository in the given path. "
          "(You may not specify the name in the command. You will have to name "
          "it however.)"
       << endl;
  cout << "  commit <name>       Commits the changes to the given Rettository."
       << endl;
  cout << "  listall             Lists all the Rettositories." << endl;
  cout << "  help                Shows this message." << endl;
  cout << "  info <directory path>            Lists all files and "
          "subdirectories of that path."
       << endl;
  cout << "  info <file path>                 Shows info about the file."
       << endl;
  cout << "  info <retto name>                Shows info about the retto."
       << endl;
  cout << "  info <retto name> <file>         Shows info about the file in the "
          "retto."
       << endl;
  cout << "  rm <retto name>                  Deletes the retto." << endl;
  cout << "  rm <retto name> <file>           Deletes the file in the retto."
       << endl;
}
