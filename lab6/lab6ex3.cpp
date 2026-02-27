#include <iostream>

class logger {
public:
  void log(std::string message) { std::cout << "[LOG]: " << message << "\n"; }
};

class FileManager : private logger {
public:
  void saveFile(std::string filename) {
    log("File saved: " +
        filename); // this is a member function of the base class, and we can
                   // only access it in the derived class
  }
};

int main() {
  FileManager obj;
  obj.saveFile("example.txt");
}
