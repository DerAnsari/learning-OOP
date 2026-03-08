#include <iostream>
using namespace std;
#include <string>

class Person {
protected:
  string name;
  int age;

public:
  virtual void getdata() = 0;
  virtual void putdata() = 0;
};

class Professor : public Person {
private:
  int publications, cur_id;
  static int id_counter; // Kept here as you had it

public:
  void getdata() override {
    // Removed 'string' and 'int' to stop shadowing
    cin >> name >> age >> publications;
    cur_id = ++id_counter;
  }

  void putdata() override {
    cout << name << " " << age << " " << publications << " " << cur_id << endl;
  }
};

int Professor::id_counter = 0;

class Student : public Person {
private:
  int curr_id, mark;
  int marks[6];
  static int id_counter; // Kept here as you had it

public:
  void getdata() override {
    // Removed 'string' and 'int' here too
    cin >> name >> age;

    this->name = name;
    this->age = age;

    for (int i{0}; i < 6; i++) {
      cin >> mark;
      marks[i] = mark;
    }
    curr_id = ++id_counter;
  }

  // ADDED: This must exist or the code won't compile
  void putdata() override {
    int sum = 0;
    for (int i = 0; i < 6; i++)
      sum += marks[i];
    cout << name << " " << age << " " << sum << " " << curr_id << endl;
  }
};

int Student::id_counter = 0;

int main() {

  int n, val;
  cin >> n; // The number of objects that is going to be created.
  Person *per[n];

  for (int i = 0; i < n; i++) {

    cin >> val;
    if (val == 1) {
      // If val is 1 current object is of type Professor
      per[i] = new Professor;

    } else
      per[i] = new Student; // Else the current object is of type Student

    per[i]->getdata(); // Get the data from the user.
  }

  for (int i = 0; i < n; i++)
    per[i]->putdata(); // Print the required output for each object.

  return 0;
}
