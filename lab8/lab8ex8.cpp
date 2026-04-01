#include <fstream>
#include <iostream>
#include <string>
#include <vector>

class Logger {
public:
  virtual void logMessage(const std::string &message) = 0; // Pure virtual
  virtual ~Logger() {} // Essential for polymorphic cleanup
};

class ConsoleLogger : public Logger {
public:
  void logMessage(const std::string &message) override {
    std::cout << "[CONSOLE]: " << message << std::endl;
  }
};

class FileLogger : public Logger {
private:
  std::string filename;

public:
  FileLogger(std::string f) : filename(f) {}

  void logMessage(const std::string &message) override {
    std::ofstream file(filename, std::ios::app);
    if (file.is_open()) {
      file << "[FILE]: " << message << std::endl;
      std::cout << "Successfully logged to file: " << filename << std::endl;
    }
  }
};

class DatabaseLogger : public Logger {
public:
  void logMessage(const std::string &message) override {
    std::cout << "[DATABASE]: Executing INSERT INTO logs VALUES ('" << message
              << "')" << std::endl;
  }
};

int main() {
  std::vector<Logger *> loggers;

  loggers.push_back(new ConsoleLogger());
  loggers.push_back(new FileLogger("app_log.txt"));
  loggers.push_back(new DatabaseLogger());

  std::string criticalError = "System overheat detected!";

  std::cout << "--- Dispatching Log Message ---" << std::endl;

  for (Logger *logger : loggers) {
    logger->logMessage(criticalError);
  }

  for (Logger *logger : loggers) {
    delete logger;
  }

  return 0;
}
