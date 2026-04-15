#ifndef WARD_H
#define WARD_H

#include "CustomUtils.h"
#include "People.h"
#include <iostream>
#include <string>
#include <vector>

using std::string, std::vector, std::cout, std::endl;

class Ward {
protected:
  string name;
  int capacity;
  vector<Patient *> admittedPatients;
  double dailyRate;

public:
  Ward(string n, int cap, double rate)
      : name(n), capacity(cap), dailyRate(rate) {}
  virtual ~Ward() {}

  virtual bool admit(Patient *p) = 0;

  void removePatient(Patient *p) {
    for (auto it = admittedPatients.begin(); it != admittedPatients.end();
         ++it) {
      if (*it == p) {
        admittedPatients.erase(it);
        return;
      }
    }
  }

  double getOccupancy() const {
    if (capacity == 0)
      return 0;
    return (double)admittedPatients.size() / capacity;
  }

  bool operator<(const Ward &other) const {
    return this->getOccupancy() < other.getOccupancy();
  }
  bool operator>(const Ward &other) const {
    return this->getOccupancy() > other.getOccupancy();
  }
  bool operator==(const Ward &other) const {
    return this->getOccupancy() == other.getOccupancy();
  }

  string getName() const { return name; }
  double getDailyRate() const { return dailyRate; }
};

class GeneralWard : public Ward {
public:
  GeneralWard(string n, int cap, double rate = 1000) : Ward(n, cap, rate) {}
  bool admit(Patient *p) override {
    if (admittedPatients.size() < (size_t)capacity) {
      admittedPatients.push_back(p);
      p->setWard(this);
      return true;
    }
    return false;
  }
};

class ICU : public Ward {
public:
  ICU(string n, int cap, double rate = 5000) : Ward(n, cap, rate) {}
  bool admit(Patient *p) override {
    if (admittedPatients.size() < (size_t)capacity && p->isCritical()) {
      admittedPatients.push_back(p);
      p->setWard(this);
      return true;
    }
    return false;
  }
};

class SurgicalWard : public Ward {
public:
  SurgicalWard(string n, int cap, double rate = 3000) : Ward(n, cap, rate) {}
  bool admit(Patient *p) override {
    if (admittedPatients.size() < (size_t)capacity) {
      admittedPatients.push_back(p);
      p->setWard(this);
      return true;
    }
    return false;
  }
};

inline void Patient::display() const {
  Person::display();
  cout << " | Diagnosis: " << diagnosis << " | Admitted: " << admissionDate
       << " | Critical: " << (critical ? "Yes" : "No")
       << " | Ward: " << (assignedWard ? assignedWard->getName() : "None")
       << endl;
}

inline Bill Patient::generateBill(int daysStayed) const {
  double treatmentsCost = 0;
  string detailLog = "Treatments:\n";
  for (const auto &t : treatments) {
    treatmentsCost += t.getCost();
    detailLog +=
        " - " + t.getName() + ": " + std::to_string(t.getCost()) + "\n";
  }
  double wardFee = 0;
  if (assignedWard) {
    wardFee = daysStayed * assignedWard->getDailyRate();
    detailLog += "Ward Stay (" + std::to_string(daysStayed) +
                 " days): " + std::to_string(wardFee) + "\n";
  }
  double total = treatmentsCost + wardFee + 500.0;
  detailLog += "Administrative Fee: 500.0\n";
  Bill b(total);
  b.addDetail(detailLog);
  return b;
}

#endif
