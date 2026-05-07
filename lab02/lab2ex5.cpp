#include <iostream>

using std::cout, std::endl;

class Date {
  int month{0}, day{0}, year{0};

public:
  Date(int m, int d, int y) {
    month = m;
    day = d;
    year = y;
  }

  void displayDate() { cout << month << "/" << day << "/" << year << endl; }

  friend class AgeCalculator;
};

class AgeCalculator {
public:
  int calculate(Date &birth) {
    const int currentYear = 2026;
    return (currentYear - birth.year);
  }
};

int main() {
  Date myBirthday(5, 15, 2000);

  AgeCalculator calc;

  cout << "Date of Birth: ";
  myBirthday.displayDate();

  int age = calc.calculate(myBirthday);
  cout << "Calculated Age (in 2026): " << age << " years old." << endl;

  return 0;
}
