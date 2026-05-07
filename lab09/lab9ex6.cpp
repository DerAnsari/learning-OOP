#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using std::string, std::vector, std::cout;

struct Event {
  string level{""};
  string message{""};
  int code{0};
};

template <typename T, typename Pred>
vector<T> filter(const vector<T> &v, Pred pred) {
  vector<T> result;
  std::copy_if(v.begin(), v.end(), std::back_inserter(result), pred);
  return result;
}

int main() {

  vector<Event> log{{"INFO", "System started successfully", 100},
                    {"WARN", "Low disk space on /dev/sda1", 201},
                    {"ERROR", "Failed to connect to database", 500},
                    {"INFO", "User 'admin' logged in", 102},
                    {"ERROR", "Null pointer exception in module X", 505},
                    {"WARN", "High memory usage detected", 202},
                    {"INFO", "Backup completed", 105},
                    {"ERROR", "Permission denied: access /etc/shadow", 403}};

  vector<Event> errorLog;

  std::copy_if(log.begin(), log.end(), std::back_inserter(errorLog),
               [](const Event &e) { return e.level == "ERROR"; });

  log.erase(std::remove_if(log.begin(), log.end(),
                           [](Event &e) { return e.level == "INFO"; }),
            log.end());

  cout << "REMAINING LABLES \n";

  for (const auto &x : log)
    cout << x.level << " ";
  cout << " \n ";

  // Demonstrate generic filter on ints
  vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  vector<int> evens = filter(numbers, [](int n) { return n % 2 == 0; });

  cout << "\nGENERIC FILTER TEST (Ints): ";
  for (int n : evens)
    cout << n << " ";
  cout << "\n";

  return 0;
}
