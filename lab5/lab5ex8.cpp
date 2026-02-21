#include <iostream>
#include <string>

using namespace std;

class Vehicle {
protected:
  double rentalPricePerDay;
  string vehicleType;

public:
  Vehicle(string type, double price)
      : vehicleType(type), rentalPricePerDay(price) {}

  virtual double rent(int days) = 0;

  void processPayment(string method) {
    cout << "Payment Method: " << method << endl;
  }

  void processPayment(double amount) {
    cout << "Payment Amount Processed: $" << amount << endl;
  }

  virtual void displayInfo() {
    cout << "Vehicle Type: " << vehicleType << endl;
    cout << "Rental Price per Day: $" << rentalPricePerDay << endl;
  }

  bool operator+(Vehicle &other) { return this->rent(1) > other.rent(1); }
};

class Car : public Vehicle {
  bool airConditioning;
  int seats;

public:
  Car(double price, bool ac, int s)
      : Vehicle("Car", price), airConditioning(ac), seats(s) {}

  double rent(int days) override {
    double total = days * rentalPricePerDay;
    if (days > 7)
      total *= 0.90;
    return total;
  }

  void displayInfo() override {
    Vehicle::displayInfo();
    cout << "Air Conditioning: " << (airConditioning ? "Yes" : "No") << endl;
    cout << "Seats: " << seats << endl;
  }
};

class Bike : public Vehicle {
  bool helmetIncluded;
  string fuelType;

public:
  Bike(double price, bool helmet, string fuel)
      : Vehicle("Bike", price), helmetIncluded(helmet), fuelType(fuel) {}

  double rent(int days) override {
    double total = days * rentalPricePerDay;
    if (days > 3)
      total *= 0.95;
    return total;
  }

  void displayInfo() override {
    Vehicle::displayInfo();
    cout << "Helmet Included: " << (helmetIncluded ? "Yes" : "No") << endl;
    cout << "Fuel Type: " << fuelType << endl;
  }
};

class Truck : public Vehicle {
  double cargoCapacity;

public:
  Truck(double price, double capacity)
      : Vehicle("Truck", price), cargoCapacity(capacity) {}

  double rent(int days) override {
    double total = days * rentalPricePerDay;
    if (days > 5)
      total *= 1.20;
    return total;
  }

  void displayInfo() override {
    Vehicle::displayInfo();
    cout << "Cargo Capacity: " << cargoCapacity << " tons" << endl;
  }
};

int main() {

  Car myCar(50.0, true, 4);
  Bike myBike(20.0, true, "Gas");

  cout << "Customer 1 (Car Rental):" << endl;
  myCar.displayInfo();
  double carTotal = myCar.rent(10);
  cout << "Total Rental for 10 Days: $" << carTotal << endl;
  myCar.processPayment("Credit Card");

  cout << "\n---------------------------\n" << endl;

  cout << "Customer 2 (Bike Rental):" << endl;
  myBike.displayInfo();
  double bikeTotal = myBike.rent(4);
  cout << "Total Rental for 4 Days: $" << bikeTotal << endl;
  myBike.processPayment("Cash");

  cout << "\n---------------------------\n" << endl;

  cout << "Comparison of Rental Costs:" << endl;
  if (myCar + myBike) {
    cout << "The car rental is more expensive than the bike rental." << endl;
  } else {
    cout << "The bike rental is more expensive than the car rental." << endl;
  }

  return 0;
}
