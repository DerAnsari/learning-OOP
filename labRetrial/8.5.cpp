#include <iostream>
#include <string>
using std::string;

class Person {
  string name;
  int age;

public:
  Person(string n, int a) : name(n) {
    if (a < 0)
      throw std::invalid_argument("Age cannot be negative!");
    age = a;
  }

  virtual void display() = 0;

  virtual string getRole() = 0;

  string getName() { return name; }
  int getAge() { return age; }

  virtual ~Person() {}
};

class Student : virtual public Person {

public:
  Student(string n, int a) : Person(n, a) {}

  void display() override {
    std::cout << "Student: " + getName() + " Age: " + std::to_string(getAge());
  }
};

class Employee : virtual public Person {

public:
  Employee(string n, int a) : Person(n, a) {}

  void display() override {
    std::cout << "Employee: " + getName() + " Age: " + std::to_string(getAge());
  }
};

class TeachingAssistant : public Student, public Employee {
  TeachingAssistant(string n, int a)
      : Person(n, a), Student(n, a), Employee(n, a) {}

  void display() override {
    Person::display();
    std::cout << " | Role: " << getRole() << std::endl;
  }
};

int main() { return 0; }