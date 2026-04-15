#ifndef HOSPITAL_H
#define HOSPITAL_H

#include "Appointment.h"
#include "CustomUtils.h"
#include "People.h"
#include "Ward.h"
#include <string>
#include <vector>

using std::string;
using std::vector;

struct PatientBillRecord {
  int patientId;
  string wardName;
  double amount;
};

class Hospital {
  vector<Ward *> wards;
  vector<HospitalStaff *> staff;
  vector<Patient *> archivedPatients;
  vector<PatientBillRecord> dischargedBillingHistory;
  AppointmentBook appointmentBook;

public:
  Hospital() {}
  ~Hospital() {
    for (auto w : wards)
      delete w;
    for (auto s : staff)
      delete s;
    for (auto p : archivedPatients)
      delete p;
  }

  void addWard(Ward *w) { wards.push_back(w); }
  void addStaff(HospitalStaff *s) { staff.push_back(s); }

  void discharge(Patient *p, int daysStayed) {
    Bill b = p->generateBill(daysStayed);

    string wName = "None";
    if (p->getWard()) {
      wName = p->getWard()->getName();
      p->setLastWardName(wName);
      p->getWard()->removePatient(p);
      p->setWard(nullptr);
    }

    dischargedBillingHistory.push_back({p->getId(), wName, b.getTotal()});

    archivedPatients.push_back(new Patient(std::move(*p)));
    delete p;
  }

  double wardRevenue(const string &wardName) const {
    double total = 0;
    for (const auto &record : dischargedBillingHistory) {
      if (record.wardName == wardName) {
        total += record.amount;
      }
    }
    return total;
  }

  bool isArchived(int id) const {
    for (auto p : archivedPatients)
      if (p->getId() == id)
        return true;
    return false;
  }

  template <typename Predicate>
  vector<Patient *> filterPatients(const vector<Patient *> &source,
                                   Predicate pred) {
    return custom_filter(source, pred);
  }
};

#endif
