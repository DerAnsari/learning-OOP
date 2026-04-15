#ifndef APPOINTMENT_H
#define APPOINTMENT_H

#include "CustomUtils.h"
#include "People.h"
#include <string>
#include <vector>

using std::string;
using std::vector;

class Appointment {
  Patient *patient;
  HospitalStaff *staff;
  string date;
  string timeSlot;

public:
  Appointment() : patient(nullptr), staff(nullptr), date(""), timeSlot("") {}
  Appointment(Patient *p, HospitalStaff *s, string d, string t)
      : patient(p), staff(s), date(d), timeSlot(t) {}

  Patient *getPatient() const { return patient; }
  HospitalStaff *getStaff() const { return staff; }
  string getDate() const { return date; }
  string getTimeSlot() const { return timeSlot; }
};

class AppointmentBook {
  vector<Appointment> appointments;

public:
  bool add(const Appointment &app) {
    for (const auto &existing : appointments) {
      if (existing.getStaff() == app.getStaff() &&
          existing.getDate() == app.getDate() &&
          existing.getTimeSlot() == app.getTimeSlot()) {
        return false;
      }
    }
    appointments.push_back(app);
    return true;
  }

  void cancel(Patient *p, HospitalStaff *s, string date) {
    for (auto it = appointments.begin(); it != appointments.end();) {
      if (it->getPatient() == p && it->getStaff() == s &&
          it->getDate() == date) {
        it = appointments.erase(it);
      } else {
        ++it;
      }
    }
  }

  vector<Appointment> getAppointmentsForStaff(HospitalStaff *s,
                                              string date) const {
    return custom_filter(appointments, [s, date](const Appointment &a) {
      return a.getStaff() == s && a.getDate() == date;
    });
  }

  vector<Appointment> getAppointmentsForPatient(Patient *p) const {
    return custom_filter(appointments, [p](const Appointment &a) {
      return a.getPatient() == p;
    });
  }

  bool hasScheduledOperation(Patient *p) const {
    for (const auto &app : appointments) {
      if (app.getPatient() == p) {
        if (app.getStaff()->calculateBillingRate() > 1000) {
          return true;
        }
      }
    }
    return false;
  }
};

#endif
