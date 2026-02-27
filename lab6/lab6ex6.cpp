#include <iostream>
#include <string>

using std::string, std::cout, std::endl;

class HospitalStaff {
protected:
  int staffID;
  string name;

public:
  HospitalStaff(int id, string n) : staffID(id), name(n) {}

  string getRole() { return "Hospital Staff"; }
};

class Doctor : public HospitalStaff {
private:
  string specialization;

public:
  Doctor(int id, string n, string spec)
      : HospitalStaff(id, n), specialization(spec) {}

  string getRole() { return "Doctor"; }

  void prescribe(string patientName) {
    cout << "Dr. " + name + " prescribed medication to: " + patientName << endl;
  }
};

class Nurse : public HospitalStaff {
private:
  string ward;

public:
  Nurse(int id, string n, string w) : HospitalStaff(id, n), ward(w) {}

  string getRole() { return "Nurse"; }

  void assist(string doctorName) {
    cout << "Nurse " + name + " assisted " + doctorName << endl;
  }
};

class Administrator : protected HospitalStaff {
private:
  string officeLocation;

public:
  Administrator(int id, string n, string loc)
      : HospitalStaff(id, n), officeLocation(loc) {}

  void scheduleAppointment() {
    cout << "Appointment Booked at " << officeLocation << " by " << name
         << endl;
  }
};

int main() {
  Doctor doc(101, "Strange", "Magic");
  Nurse nrs(202, "Joy", "Ward B");
  Administrator admin(303, "Coulson", "Floor 4");

  cout << "Role: " << doc.getRole() << endl;
  doc.prescribe("Peter Parker");

  cout << "Role: " << nrs.getRole() << endl;
  nrs.assist("Dr. Strange");

  admin.scheduleAppointment();

  // COMMENT FOR EXERCISE:
  // admin.getRole();
  // The line above would cause a COMPILER ERROR.
  // Because Administrator uses 'protected' inheritance, all public members
  // of HospitalStaff become protected in Administrator, making them
  // inaccessible from main().

  return 0;
}
