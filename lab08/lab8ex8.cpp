#include <iostream>
#include <string>

class PoweredSystem {
protected:
  int powerID;

public:
  PoweredSystem(int id) : powerID(id) {
    std::cout << "PoweredSystem Constructor (ID: " << powerID << ")"
              << std::endl;
  }
  virtual ~PoweredSystem() {}
};

class Vehicle : public virtual PoweredSystem {
protected:
  std::string model;

public:
  Vehicle(int id, std::string m) : PoweredSystem(id), model(m) {
    std::cout << "Vehicle Constructor (" << model << ")" << std::endl;
  }
};

class Engine : public virtual PoweredSystem {
protected:
  float horsepower;

public:
  Engine(int id, float hp) : PoweredSystem(id), horsepower(hp) {
    std::cout << "Engine Constructor (" << horsepower << " HP)" << std::endl;
  }
};

class Car : public Vehicle, public Engine {
public:
  Car(int id, std::string m, float hp)
      : PoweredSystem(id), Vehicle(id, m), Engine(id, hp) {
    std::cout << "Car Constructor Complete." << std::endl;
  }

  void displaySpecs() {
    std::cout << "\n--- Car Specifications ---" << std::endl;
    std::cout << "System ID: " << powerID << std::endl; // No ambiguity!
    std::cout << "Model:     " << model << std::endl;
    std::cout << "Power:     " << horsepower << " HP" << std::endl;
  }
};

int main() {
  std::cout << "Initializing Car object..." << std::endl;
  Car myCar(999, "Tesla Model S", 1020.0f);

  myCar.displaySpecs();

  return 0;
}
