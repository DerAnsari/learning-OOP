#include <iostream>
#include <string>
using std::cout, std::endl, std::string, std::to_string;

class Date {
  int day{0};
  int month{0};
  int year{0};

public:
  Date(int d, int m, int y) {
    day = d;
    year = y;

    if (m >= 1 && m <= 12) {
      month = m;
    } else {
      month = 1;
    }
  };

  string formatDate() {
    const string forwardSlash = "/";
    string date = to_string(day) + forwardSlash + to_string(month) +
                  forwardSlash + to_string(year);
    return date;
  };

  void setDay(int d) { day = d; };

  void setMonth(int m) { month = m; };
};

int main() {
  Date d1(19, 1, 2024);
  cout << d1.formatDate() << endl; // should print 19/1/2024
  d1.setDay(17);
  cout << d1.formatDate() << endl; // should print 17/1/2024
  d1.setMonth(5);
  cout << d1.formatDate() << endl; // should print 17/5/2024
  Date d2(29, 13, 2024);           // should set month to 1
  cout << d2.formatDate() << endl; // should print 29/1/2024

  return 0;
}
