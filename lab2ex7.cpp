#include <iostream>
#include <string>

using std::string, std::cout, std::endl;

class player {
  string firstName{""}, lastName{""};
  double monthlyContract{0};

public:
  player(string fName, string lName, int m) {
    firstName = fName;
    lastName = lName;

    if (monthlyContract > 0) {
      monthlyContract = m;
    } else {
      monthlyContract = 0.0;
    }
  }

  void contractValidation() { monthlyContract *= 1.10; }

  int yearlyEarning() { return monthlyContract * 12; }

  void displayInfo() {
    cout << firstName << " " << lastName << " | Yearly Earnings: $"
         << yearlyEarning() << endl;
  }
};

int main() {
  player p1("Faker", "Lee", 5000.0);
  player p2("S1mple", "Kostyliev", 4000.0);

  cout << "--- Initial Yearly Earnings ---" << endl;
  p1.displayInfo();
  p2.displayInfo();

  p1.contractValidation();
  p2.contractValidation();

  cout << "\n--- After 10% Performance Bonus ---" << endl;
  p1.displayInfo();
  p2.displayInfo();

  return 0;
}
