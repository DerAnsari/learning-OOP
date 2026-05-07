#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <vector>
using std::string, std::cout, std::vector;

string formatMessage(const string &prefix, const string &msg,
                     const string &suffix) {
  return prefix + msg + suffix;
}

int main() {
  using namespace std::placeholders;

  auto makeInfo = std::bind(formatMessage, "[INFO] ", _1, "");
  auto makeError = std::bind(formatMessage, "[ERROR] ", _1, " !!!");
  auto makeDebug = std::bind(formatMessage, "[DEBUG] ", _1, " (line?)");

  std::vector<std::function<string(const string &)>> formatters = {
      makeInfo, makeError, makeDebug};

  std::cout << "--- Single Message Formatting ---\n";
  for (const auto &formatter : formatters) {
    cout << formatter("Connection timeout") << "\n";
  }

  vector<string> rawErrors = {"Database failure", "Invalid token",
                              "Out of memory", "Stack overflow", "Disk full"};
  vector<string> formattedErrors;

  std::transform(rawErrors.begin(), rawErrors.end(),
                 std::back_inserter(formattedErrors), makeError);

  for (const auto &err : formattedErrors) {
    cout << err << "\n";
  }

  return 0;
}
