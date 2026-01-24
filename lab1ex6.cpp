#include <iostream>
#include <string>

using std::string, std::cout, std::endl;
;

class Employee {
  string name{""}, lastName{""};
  double salaryMonth{0};

public:
  Employee(string n, string ln, double sm) {
    if (sm > 0) {
      salaryMonth = sm;
    } else {
      salaryMonth = 0.0;
    }
    name = n;
    lastName = ln;
  }

  double getYearly() { return salaryMonth * 12; }

  string getFullName() { return name + " " + lastName; }

  void giveRaise(double percentage) {
    salaryMonth = salaryMonth * (1 + (percentage / 100));
  }
};

int main() {
  Employee emp1("Sarmad", "Ansari", 5000.0);
  Employee emp2("John", "Doe", 6000.0);

  cout << emp1.getFullName() << " Yearly Salary: $" << emp1.getYearly() << endl;
  cout << emp2.getFullName() << " Yearly Salary: $" << emp2.getYearly() << endl;

  cout << "\n--- Applying 10% Raise ---" << endl;
  emp1.giveRaise(10.0);
  emp2.giveRaise(10.0);

  cout << emp1.getFullName() << " New Yearly Salary: $" << emp1.getYearly()
       << endl;
  cout << emp2.getFullName() << " New Yearly Salary: $" << emp2.getYearly()
       << endl;

  return 0;
}
