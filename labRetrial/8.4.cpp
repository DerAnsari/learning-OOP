#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>
using std::string;

class FileHandler {
  std::fstream file;
  string filename;

public:
  FileHandler(string n) : filename(n) {}

  void openFile(std::ios::openmode mode) {
    file.open(filename, mode);

    if (!file.is_open()) {
      if (errno == ENOENT) {
        throw std::runtime_error("Error: File '" + filename + "' not found.");
      } else if (errno == EACCES) {
        throw std::runtime_error("Error: Permission denied for file '" +
                                 filename + "'.");
      } else {
        throw std::runtime_error("Error: Could not open file.");
      }
    }
  }

  void writeFile(const string &content) {
    if (!file.is_open() || !file.good()) {
      throw std::runtime_error("Error: File is not open or not writable.");
    }
    file << content << std::endl;
  }

  string readFile() {
    if (!file.is_open()) {
      throw std::runtime_error("Error: File is not open for reading.");
    }
    string line, fulltext;
    while (std::getline(file, line)) {
      fulltext += line + "\n";
    }
    return fulltext;
  }

  void closeFile() {
    if (file.is_open()) {
      closeFile();
    }
  }

  ~FileHandler() { closeFile(); }
};

int main() {
  FileHandler handler("secret_data.txt");

  try {
    std::cout << "Attempting to open file..." << std::endl;
    handler.openFile(std::ios::in); // Attempting to read

    std::string content = handler.readFile();
    std::cout << "File Content:\n" << content;

    handler.closeFile();
  } catch (const std::runtime_error &e) {
    // This catches our "File Not Found" or "Permission" errors
    std::cerr << "Caught Exception: " << e.what() << std::endl;
  } catch (const std::exception &e) {
    std::cerr << "An unexpected error occurred: " << e.what() << std::endl;
  }

  return 0;
}