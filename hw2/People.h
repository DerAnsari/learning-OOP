#ifndef PEOPLE_H
#define PEOPLE_H

#include <vector>
#include <string>
#include <iostream>
#include "CustomUtils.h"
#include "Bill.h"

using std::vector;
using std::string;
using std::cout;
using std::endl;

class Ward;

class Person {
protected:
    string name;
    string dob;
    int id;
    string phone;

public:
    Person(string n, string d, int i, string p) 
        : name(n), dob(d), id(i), phone(p) {}
    virtual ~Person() {}
    
    virtual void display() const {
        cout << "ID: " << id << " | Name: " << name;
    }

    string getName() const { return name; }
    int getId() const { return id; }
};

class Patient : public Person {
    string diagnosis;
    string admissionDate;
    string lastWardName; 
    Ward* assignedWard;
    vector<Treatment> treatments;
    vector<string> prescriptions; 
    bool critical;

public:
    Patient(string n, string d, int i, string p, string diag, string adm, bool crit = false)
        : Person(n, d, i, p), diagnosis(diag), admissionDate(adm), lastWardName("None"), assignedWard(nullptr), critical(crit) {}

    // Deep Copy Constructor (TC-06)
    Patient(const Patient& other) : Person(other), diagnosis(other.diagnosis), 
        admissionDate(other.admissionDate), lastWardName(other.lastWardName),
        assignedWard(other.assignedWard), treatments(other.treatments), 
        prescriptions(other.prescriptions), critical(other.critical) {}

    // Assignment Operator (Rule of Three compliance)
    Patient& operator=(const Patient& other) {
        if (this != &other) {
            Person::operator=(other);
            diagnosis = other.diagnosis;
            admissionDate = other.admissionDate;
            lastWardName = other.lastWardName;
            assignedWard = other.assignedWard;
            treatments = other.treatments;
            prescriptions = other.prescriptions;
            critical = other.critical;
        }
        return *this;
    }

    // Move Constructor (TC-07)
    Patient(Patient&& other) noexcept : Person(std::move(other)), diagnosis(std::move(other.diagnosis)),
        admissionDate(std::move(other.admissionDate)), lastWardName(std::move(other.lastWardName)),
        assignedWard(other.assignedWard), treatments(std::move(other.treatments)), 
        prescriptions(std::move(other.prescriptions)), critical(other.critical) {
        other.assignedWard = nullptr;
    }

    void addTreatment(const Treatment& t) { treatments.push_back(t); }
    void addPrescription(string p) { prescriptions.push_back(p); }
    size_t treatmentCount() const { return treatments.size(); }
    void setWard(Ward* w) { assignedWard = w; } 
    Ward* getWard() const { return assignedWard; }
    bool isCritical() const { return critical; }
    string getDiagnosis() const { return diagnosis; }
    string getAdmissionDate() const { return admissionDate; }
    string getLastWardName() const { return lastWardName; }
    void setLastWardName(string n) { lastWardName = n; }

    void display() const override;
    Bill generateBill(int daysStayed = 1) const;
};

class HospitalStaff : public Person {
protected:
    double salary;
    string department;

public:
    HospitalStaff(string n, string d, int i, string p, double s, string dep)
        : Person(n, d, i, p), salary(s), department(dep) {}

    virtual double calculateBillingRate() const = 0;
    string getDepartment() const { return department; }

    void display() const override {
        Person::display();
        cout << " | Dept: " << department << " | Salary: " << salary;
    }
};

class GeneralPractitioner : public HospitalStaff {
    double hourlyFee;
public:
    GeneralPractitioner(string n, string d, int i, string p, double s, string dep, double fee)
        : HospitalStaff(n, d, i, p, s, dep), hourlyFee(fee) {}

    double calculateBillingRate() const override { return hourlyFee; }
    void writePrescription(Patient* p, string med) { p->addPrescription(med); }
    
    void display() const override {
        HospitalStaff::display();
        cout << " | Role: GP | Hourly: " << hourlyFee << endl;
    }
};

class Surgeon : public HospitalStaff {
    string specialization;
    double perOpFee;
public:
    Surgeon(string n, string d, int i, string p, double s, string dep, string spec, double fee)
        : HospitalStaff(n, d, i, p, s, dep), specialization(spec), perOpFee(fee) {}

    double calculateBillingRate() const override { return perOpFee; }
    void performOperation(Patient* p, string op) { p->addTreatment(Treatment(op, perOpFee, this)); }

    void display() const override {
        HospitalStaff::display();
        cout << " | Role: Surgeon | Spec: " << specialization << endl;
    }
};

class Nurse : public HospitalStaff {
    double hourlyFee;
    Ward* assignedWard;
public:
    Nurse(string n, string d, int i, string p, double s, string dep, double fee)
        : HospitalStaff(n, d, i, p, s, dep), hourlyFee(fee), assignedWard(nullptr) {}

    void setWard(Ward* w) { assignedWard = w; }
    double calculateBillingRate() const override { return hourlyFee; }
    void display() const override {
        HospitalStaff::display();
        cout << " | Role: Nurse | Hourly: " << hourlyFee << endl;
    }
};

#endif
