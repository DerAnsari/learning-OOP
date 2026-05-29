#include <iostream>
#include <string>
using std::string, std::cout, std::endl;

class Employee {
  string firstName, lastName;
  double monthlySalary;

public:
  void addBonus() { monthlySalary *= 1.10; }

  double getYearlySalary() const { return monthlySalary * 12; }

  void display() {
    cout << "Name: " << firstName << lastName
         << "monthlySalary: " << monthlySalary << endl;
  }
};

int main() { return 0; }
