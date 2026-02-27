#include <iostream>
#include <string>

using std::string, std::endl, std::cout, std::to_string;

class Vehicle {
protected:
  string registrationNo;
  string brand;
  double dailyRate;

public:
  Vehicle(string reg, string b, double rate)
      : registrationNo(reg), brand(b), dailyRate(rate) {}

  virtual void displayVehicle() {
    cout << "Registration Num: " + registrationNo + " | Brand: " + brand +
                " | Daily Rate: " + to_string(dailyRate);
  }

  virtual double calculateRentalCost(int days) { return dailyRate * days; }
};

class Car : public Vehicle {
private:
  int numDoors;

public:
  Car(string reg, string b, double rate, int doors)
      : Vehicle(reg, b, rate), numDoors(doors) {}

  void displayVehicle() override {
    Vehicle::displayVehicle();
    cout << " | Number of Doors: " + to_string(numDoors) << endl;
  }
};

class ElectricCar : public Car {
private:
  double batteryCapacity;

public:
  ElectricCar(string reg, string b, double rate, int doors, double battery)
      : Car(reg, b, rate, doors), batteryCapacity(battery) {}

  void displayVehicle() override {
    // Calling base to avoid re-writing the whole string
    Vehicle::displayVehicle();
    cout << " | Battery Capacity: " + to_string(batteryCapacity) + " kWh"
         << endl;
  }

  double calculateRentalCost(int days) override {
    return (dailyRate * days) * 0.85;
  }
};

class Truck : private Vehicle {
private:
  double payloadCapacity;

public:
  Truck(string reg, string b, double rate, double payload)
      : Vehicle(reg, b, rate), payloadCapacity(payload) {}

  void displayTruck() {
    /* Comment: registrationNo is accessible here because it is protected in
       Vehicle. However, private inheritance means main() cannot call
       displayVehicle() directly on a Truck object.
    */
    displayVehicle();
    cout << " | Payload Capacity: " + to_string(payloadCapacity) + " tonnes"
         << endl;
  }
};

int main() {
  Car c("C123", "Toyota", 50.0, 4);
  ElectricCar ec("E999", "Tesla", 100.0, 4, 75.0);
  Truck t("T555", "Volvo", 200.0, 15.0);

  cout << "--- Car Info ---" << endl;
  c.displayVehicle();

  cout << "\n--- Electric Car Info ---" << endl;
  ec.displayVehicle();
  cout << "7-Day Cost: " << ec.calculateRentalCost(7) << endl;

  cout << "\n--- Truck Info ---" << endl;
  t.displayTruck();

  return 0;
}
