#include <iostream>

using std::cout, std::endl, std::cin;

class OxygenTank {
public:
  int oxygenLevel{200};

  void refill() { oxygenLevel = 200; }

  void consume(int units) {
    oxygenLevel -= units;
    if (oxygenLevel < 100) {
      refill();
    }
  }
};

int main() {
  OxygenTank tank;
  int amount;

  cout << "--- Orbital Life Support System Active ---" << endl;
  cout << "Initial Oxygen: " << tank.oxygenLevel << endl;

  while (true) {
    cout << "\nEnter oxygen units used (or -1 to exit): ";
    cin >> amount;

    if (amount == -1)
      break;

    tank.consume(amount);
  }

  cout << "System Shutting Down. Goodbye, Astronaut." << endl;
  return 0;
}
