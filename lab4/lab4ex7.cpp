#include <iostream>
#include <string>
using std::cout, std::endl, std::string;

struct Patient {
  string name;
  int severity;
  int arrivalTime;
};

class ERQueue {
private:
  Patient *patients;
  int size;
  int capacity;

  void resize() {
    capacity *= 2;
    Patient *newPatients = new Patient[capacity];
    for (int i = 0; i < size; i++)
      newPatients[i] = patients[i];
    delete[] patients;
    patients = newPatients;
  }

  // helperFunction
  bool higherPriority(const Patient &a, const Patient &b) {
    if (a.severity != b.severity)
      return a.severity > b.severity;
    return a.arrivalTime < b.arrivalTime;
  }

public:
  ERQueue(int capacity = 10) : size(0), capacity(capacity) {
    patients = new Patient[capacity];
  }

  void addPatient(string name, int severity, int arrivalTime) {
    if (size == capacity)
      resize();
    patients[size++] = {name, severity, arrivalTime};
    int i = size - 1;
    while (i > 0 && higherPriority(patients[i], patients[i - 1])) {
      Patient temp = patients[i];
      patients[i] = patients[i - 1];
      patients[i - 1] = temp;
      i--;
    }
  }

  Patient treatPatient() {
    if (size == 0)
      throw std::runtime_error("No patients");
    Patient p = patients[0];
    for (int i = 0; i < size - 1; i++)
      patients[i] = patients[i + 1];
    size--;
    return p;
  }

  Patient peek() {
    if (size == 0)
      throw std::runtime_error("No patients");
    return patients[0];
  }

  bool isEmpty() { return size == 0; }
};

int main() {
  ERQueue er;
  er.addPatient("Alice", 5, 1001);
  er.addPatient("Bob", 8, 1002);
  er.addPatient("Charlie", 8, 1003);
  er.addPatient("Dana", 3, 1004);

  while (!er.isEmpty()) {
    Patient p = er.treatPatient();
    cout << p.name << " (severity: " << p.severity << ")" << endl;
  }

  return 0;
}
