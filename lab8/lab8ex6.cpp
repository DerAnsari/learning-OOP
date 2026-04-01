#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using std::vector, std::string, std::cout, std::endl;

class Logger {
public:
  virtual void logMessage(const string &message) = 0;
  virtual ~Logger() {}
};

class ConsoleLogger : public Logger {
public:
  void logMessage(const string &message) override {
    cout << "[CONSOLE]: " << message << endl;
  }
};

class FileLogger : public Logger {
private:
  string filename;

public:
  FileLogger(string f) : filename(f) {}

  void logMessage(const string &message) override {
    std::ofstream file(filename, std::ios::app);
    if (file.is_open()) {
      file << "[FILE]: " << message << endl;
      cout << "Successfully logged to file: " << filename << endl;
    }
  }
};

class DatabaseLogger : public Logger {
public:
  void logMessage(const string &message) override {
    cout << "[DATABASE]: Executing INSERT INTO logs VALUES ('" << message
         << "')" << endl;
  }
};

int main() {
  vector<Logger *> loggers;

  loggers.push_back(new ConsoleLogger());
  loggers.push_back(new FileLogger("app_log.txt"));
  loggers.push_back(new DatabaseLogger());

  string criticalError = "System overheat detected!";

  cout << "--- Dispatching Log Message ---" << endl;

  for (Logger *logger : loggers) {
    logger->logMessage(criticalError);
  }

  for (Logger *logger : loggers) {
    delete logger;
  }
  return 0;
}
