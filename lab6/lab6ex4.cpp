#include <iostream>
#include <string>

class person {
protected:
  std::string name;
  std::string CNIC;

public:
  person(std::string n, std::string c) {
    name = n;
    CNIC = c;
  }
  void displayInfo() {
    std::cout << "Name: " << name << " CNIC: " << CNIC << std::endl;
  }
};

class student : public person {
private:
  std::string Rollno;
  double GPA;

public:
  student(std::string n, std::string c, std::string r, double g)
      : person(n, c) {
    Rollno = r;
    GPA = g;
  }
  void displayInfo() {
    person::displayInfo();
    std::cout << "ROLL NO: " << Rollno << " GPA: " << GPA << std::endl;
  }
};

class Lecturer : public person {
private:
  std::string EmployeeID;
  std::string Department;

public:
  Lecturer(std::string n, std::string c, std::string e, std::string d)
      : person(n, c) {
    EmployeeID = e;
    Department = d;
  }
  void displayInfo() {
    person::displayInfo();
    std::cout << "Employee ID: " << EmployeeID << " Department: " << Department
              << std::endl;
  }
};

int main() {
  student s1("Jawwad Farid", "12345", "69420", 2.5);
  Lecturer L1("Sir Behraj", "56789", "456", "Computer Science");
  s1.displayInfo();
  L1.displayInfo();
  return 0;
}
