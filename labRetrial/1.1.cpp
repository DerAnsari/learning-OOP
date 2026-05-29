#include <iostream>
#include <string>
using namespace std;

class Date {
  int day, month, year;

public:
  Date() : day(0), month(0), year(0) {}

  Date(int d, int m, int y) : day(d), year(y) {
    if (m > 12 || m < 1)
      month = 1;
    else
      this->month = m;
  }

  string formatDate() {
    return (to_string(day) + "/" + to_string(month) + "/" + to_string(year));
  }

  void setDay(int d) { this->day = d; }
  void setMonth(int m) { this->month = m; }
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
