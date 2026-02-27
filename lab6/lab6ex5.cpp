#include <iostream>
#include <string>
using std::cout, std::endl, std::string;

class Employee {
protected:
  int employeeID;
  double baseSalary;

public:
  Employee(int employeeID, double baseSalary)
      : employeeID(employeeID), baseSalary(baseSalary) {}

  virtual void display() {
    cout << "Employee ID: " << employeeID << endl;
    cout << "Employee Base Salary: " << baseSalary << endl;
    cout << "Employee Base Bonus: " << baseSalary * 0.05 << endl;
    return;
  }

  virtual ~Employee() {};
};

class Manager : public Employee {
private:
  string department;

public:
  Manager(int employeeID, double baseSalary, string department)
      : Employee(employeeID, baseSalary), department(department) {}

  string getDepartment() { return department; }

  void display() override {
    cout << "Manager ID: " << employeeID << endl;
    cout << "Manager Base Salary: " << baseSalary << endl;
    cout << "Manager Department: " << department << endl;
    cout << "Manager Base Bonus: " << baseSalary * 0.10 << endl;
    return;
  }
};

class RegionalDirector : public Manager {
private:
  string region;

public:
  RegionalDirector(int employeeID, double baseSalary, string department,
                   string region)
      : Manager(employeeID, baseSalary, department), region(region) {}

  void display() override {
    cout << "Regional Director ID: " << employeeID << endl;
    cout << "Regional Director Base Salary: " << baseSalary << endl;
    cout << "Regional Director Department: " << getDepartment() << endl;
    cout << "Regional Director Region: " << region << endl;
    cout << "Regional Base Bonus: " << baseSalary * 0.15 << endl;
    return;
  }
};

int main() {
  Employee emp(101, 50000);
  Manager mgr(202, 75000, "Logistics");
  RegionalDirector rd(303, 100000, "Sales", "North America");

  cout << "INDIVIDUAL OBJECT TEST:" << endl;
  emp.display();
  cout << endl;
  mgr.display();
  cout << endl;
  rd.display();
  cout << endl;

  return 0;
}
