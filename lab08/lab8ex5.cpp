#include <iostream>
#include <stdexcept>
#include <string>
using std::string, std::endl, std::cout;

class Person {
protected:
  string name{""};
  int age{0};

public:
  Person(string n, int a) : name(n), age(a) {
    if (a < 0)
      throw std::invalid_argument("Age cannot be negative!");
    cout << "Person obj Created" << endl;
  }

  virtual void display() {
    cout << "Name: " << name << ", Age: " << age << endl;
  };

  virtual string getRole() = 0;

  virtual ~Person() {};
};

class Student : public virtual Person {
  string major{""};

public:
  Student(string n, int a, string m) : Person(n, a), major(m) {
    cout << "Student obj Created" << endl;
  }

  string getRole() override { return "Student"; }
};

class Employee : public virtual Person {
  string department{""};

public:
  Employee(string n, int a, string d) : Person(n, a), department(d) {
    cout << "Employee obj Created" << endl;
  }

  string getRole() override { return "Employee"; }
};

class TeachingAssistant : public Student, public Employee {
public:
  TeachingAssistant(const string &n, int a, const string &m, const string &d)
      : Person(n, a), Student(n, a, m), Employee(n, a, d) {
    cout << "TeachingAssistant constructor called\n";
  }
  string getRole() override { return "Teaching Assistant"; }
  void display() override {
    cout << "Role: " << getRole() << "\n";
    Person::display();
  }
};

void testDiamondProblem() {
  cout << "\nTesting Diamond Problem...\n";
  cout << "Base class Person appears only once "
          "due to virtual inheritance.\n";
}

int main() {
  cout << "Creating a Teaching Assistant...\n";
  TeachingAssistant ta("Alice", 25, "CS", "Engineering");
  cout << "\n";
  ta.display();
  testDiamondProblem();
  Person *p = &ta;
  cout << "\nCalling display() via base pointer:\n";
  p->display();
}
