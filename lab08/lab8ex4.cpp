#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>
using std::fstream, std::getline, std::runtime_error, std::string, std::cout,
    std::endl;

class FileHandler {
private:
  fstream file;
  string filename;

public:
  FileHandler(string name) : filename(name) {}

  void openFile(std::ios::openmode mode) {
    file.open(filename, mode);

    if (!file.is_open()) {
      throw runtime_error(
          "Could not open file: " + filename +
          " (Check if file exists or permissions are restricted)");
    }
    cout << "Successfully opened: " << filename << endl;
  }

  void writeFile(const string &content) {
    if (!file.is_open() || file.fail()) {
      throw runtime_error("Write error: File is not open or is read-only.");
    }
    file << content << std::endl;
    cout << "Data written successfully." << endl;
  }

  void readFile() {
    if (!file.is_open() || file.fail()) {
      throw runtime_error("Read error: File is not open or is write-only.");
    }
    string line;
    cout << "--- File Content ---" << endl;
    while (getline(file, line)) {
      cout << line << endl;
    }
  }

  void closeFile() {
    if (file.is_open()) {
      file.close();
      cout << "File closed." << endl;
    }
  }

  ~FileHandler() { closeFile(); }
};

int main() {
  // 1. Testing a successful Write/Read
  try {
    FileHandler fh("test.txt");
    fh.openFile(std::ios::out);
    fh.writeFile("Hello! This is a test for Exercise 4.");
    fh.closeFile();

    fh.openFile(std::ios::in);
    fh.readFile();
    fh.closeFile();
  } catch (const std::exception &e) {
    std::cerr << "EXCEPTION: " << e.what() << std::endl;
  }

  std::cout << "\n--- Testing Error Case ---\n";

  // 2. Testing a Failure (File that doesn't exist/No permission)
  try {
    FileHandler fh_bad("/root/secret.txt");
    fh_bad.openFile(std::ios::in);
  } catch (const std::exception &e) {
    std::cerr << "CAUGHT EXPECTED ERROR: " << e.what() << std::endl;
  }

  return 0;
}
