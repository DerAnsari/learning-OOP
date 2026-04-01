#include <fstream>
#include <iostream>
#include <string>
#include <vector>

// 1. Base Class (The Interface)
class Logger {
public:
  virtual void logMessage(const std::string &message) = 0; // Pure virtual
  virtual ~Logger() {} // Essential for polymorphic cleanup
};

// 2. Console Logger
class ConsoleLogger : public Logger {
public:
  void logMessage(const std::string &message) override {
    std::cout << "[CONSOLE]: " << message << std::endl;
  }
};

// 3. File Logger
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

// 4. Database Logger (Simulated)
class DatabaseLogger : public Logger {
public:
  void logMessage(const std::string &message) override {
    // In a real scenario, you'd connect to SQL here
    std::cout << "[DATABASE]: Executing INSERT INTO logs VALUES ('" << message
              << "')" << std::endl;
  }
};

int main() {
  // We create a list of different loggers using the Base Class Pointer
  std::vector<Logger *> loggers;

  loggers.push_back(new ConsoleLogger());
  loggers.push_back(new FileLogger("app_log.txt"));
  loggers.push_back(new DatabaseLogger());

  std::string criticalError = "System overheat detected!";

  std::cout << "--- Dispatching Log Message ---" << std::endl;

  // Polymorphism in action: one call, different behaviors
  for (Logger *logger : loggers) {
    logger->logMessage(criticalError);
  }

  // Cleanup
  for (Logger *logger : loggers) {
    delete logger;
  }

  return 0;
}
