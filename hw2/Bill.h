#ifndef BILL_H
#define BILL_H

#include "CustomUtils.h"
#include <iostream>
#include <string>

using std::string, std::cout, std::endl;

class HospitalStaff;

class Treatment {
  string name;
  double cost;
  HospitalStaff *staffPerformed;

public:
  Treatment() : name(""), cost(0), staffPerformed(nullptr) {}
  Treatment(string name, double cost, HospitalStaff *staff)
      : name(name), cost(cost), staffPerformed(staff) {}

  double getCost() const { return cost; }
  string getName() const { return name; }
};

class Bill {
  double total;
  string details;

public:
  Bill(double t = 0) : total(t), details("") {}

  void addDetail(const string &d) { details += d + "\n"; }
  double getTotal() const { return total; }

  Bill operator+(const Bill &other) const {
    Bill combined(this->total + other.total);
    combined.details = this->details + other.details;
    return combined;
  }

  bool operator==(const Bill &other) const {
    return this->total == other.total;
  }

  friend std::ostream &operator<<(std::ostream &os, const Bill &bill) {
    os << "----- MediCore Bill -----\n"
       << bill.details << "TOTAL: PKR " << bill.total << "\n"
       << "-------------------------";
    return os;
  }
};

#endif
