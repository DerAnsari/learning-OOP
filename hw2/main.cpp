#include "Appointment.h"
#include "Bill.h"
#include "CustomUtils.h"
#include "Hospital.h"
#include "People.h"
#include "Ward.h"
#include <cassert>
#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;

// Custom check function for TC reporting
void check(bool condition, const string &tc_id) {
  if (condition) {
    cout << tc_id << ": PASS" << endl;
  } else {
    cout << tc_id << ": FAIL" << endl;
  }
}

int main() {
  cout << "--- MediCore System Test Suite ---" << endl;

  // Setup for Tests
  GeneralPractitioner gp("Dr. Ali", "1980-01-01", 101, "123456", 50000,
                         "General Medicine", 500);
  Surgeon surgeon("Dr. Baig", "1975-05-12", 102, "234567", 100000, "Cardiology",
                  "Cardiothoracic", 5000);
  Nurse nurse("Sr. Khan", "1990-10-20", 103, "345678", 30000, "ICU", 300);

  Patient patient1("Hamid Raza", "2000-01-01", 201, "456789", "Cardiac arrest",
                   "2026-04-10", true);

  // TC-01: Polymorphic Display
  vector<Person *> people;
  people.push_back(&gp);
  people.push_back(&surgeon);
  people.push_back(&nurse);
  people.push_back(&patient1);

  cout << "TC-01: Polymorphic Display Output:" << endl;
  for (size_t i = 0; i < people.size(); ++i) {
    people[i]->display();
  }
  check(true, "TC-01");

  // TC-02: Billing Operator Overloading
  Treatment t1("Blood test", 500, &gp);
  patient1.addTreatment(t1);

  Bill b1 = patient1.generateBill(1); // 1 day
  Bill b2 = patient1.generateBill(1);

  check(b1 == b2, "TC-02: operator==");
  Bill combined = b1 + b2;
  check(combined.getTotal() == b1.getTotal() + b2.getTotal(),
        "TC-02: operator+");

  // TC-03: Ward Comparison Operators
  GeneralWard w1("Ward A", 20, 1000);
  ICU w2("ICU", 8, 5000);

  // Occupancy: 1/20 (5%) vs 1/8 (12.5%)
  w1.admit(&patient1);
  w2.admit(&patient1);

  check(w1 < w2, "TC-03: operator<");
  check(w2 > w1, "TC-03: operator>");

  // TC-04: ICU Admission Rule Enforcement
  Patient routine("Sara Baig", "2005-02-02", 202, "567890", "Sprained ankle",
                  "2026-04-11", false);
  Patient critPatient("Ali Khan", "1995-03-03", 203, "678901", "Cardiac arrest",
                      "2026-04-11", true);

  ICU icu_ward("ICU-1", 10, 5000);
  check(icu_ward.admit(&routine) == false, "TC-04: ICU rejects non-critical");
  check(icu_ward.admit(&critPatient) == true, "TC-04: ICU accepts critical");

  // TC-05: Double-Booking Prevention
  AppointmentBook book;
  book.add(Appointment(&patient1, &gp, "2026-04-10", "10:00"));
  bool doubleBook = book.add(Appointment(&routine, &gp, "2026-04-10", "10:00"));
  check(doubleBook == false, "TC-05: Double-booking rejected");

  // TC-06: Copy Independence
  Patient original("Hamid", "...", 201, "...", "...", "...");
  original.addTreatment(Treatment("Test", 500, &gp));
  Patient copy = original;
  copy.addTreatment(Treatment("MRI", 8000, &gp));
  check(original.treatmentCount() == 1 && copy.treatmentCount() == 2,
        "TC-06: Deep Copy Independence");

  // TC-07: Move Semantics
  Hospital hospital;
  Patient *pToDischarge =
      new Patient("MoveMe", "2000", 999, "555", "Check", "2026-04-10", false);
  hospital.discharge(pToDischarge, 1);
  check(hospital.isArchived(999), "TC-07: Patient archived via Move");

  // TC-08: Composable Filtering
  vector<Patient *> testPatients = {&patient1, &routine, &critPatient};
  auto filtered =
      custom_filter(testPatients, [](Patient *p) { return p->isCritical(); });
  check(filtered.size() == 2, "TC-08: Filtered critical patients");

  // TC-09: Billing Rate Polymorphism
  HospitalStaff *staff_arr[] = {&gp, &surgeon, &nurse};
  check(staff_arr[1]->calculateBillingRate() == 5000,
        "TC-09: Surgeon rate check");

  // TC-10: Revenue Report (Matching PDF logic)
  GeneralWard *wardA_ptr = new GeneralWard("Ward A", 10, 1000);
  hospital.addWard(wardA_ptr);

  Patient *pA = new Patient("PA", "...", 301, "...", "...", "...");
  Patient *pB = new Patient("PB", "...", 302, "...", "...", "...");
  Patient *pC = new Patient("PC", "...", 303, "...", "...", "...");

  wardA_ptr->admit(pA);
  pA->addTreatment(Treatment("T1", 8500, &gp));
  wardA_ptr->admit(pB);
  pB->addTreatment(Treatment("T2", 13500, &gp));
  wardA_ptr->admit(pC);
  pC->addTreatment(Treatment("T3", 6500, &gp));

  hospital.discharge(pA, 1);
  hospital.discharge(pB, 1);
  hospital.discharge(pC, 1);

  double revenue = hospital.wardRevenue("Ward A");
  cout << "Actual Revenue: " << revenue << endl;
  check(revenue == 33000.0, "TC-10: Revenue 33000.0 PKR verified");

  return 0;
}
