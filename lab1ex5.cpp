#include <iostream>
#include <string>

using std::string, std::stoi, std::cin, std::cout, std::endl;

class Glass {
public:
  int liquidLevel{0};

  Glass() { liquidLevel = 200; }

  void Drink(int milimeters) {
    if (liquidLevel >= milimeters) {
      liquidLevel -= milimeters;
    } else {
      cout << "Not enough liquid left to drink that much!" << endl;
      liquidLevel = 0;
    };

    if (liquidLevel < 100) {
      cout << "...Level dropped to " << liquidLevel << "ml. Robot refilling..."
           << endl;
      refill();
    }
  }

  void refill() { liquidLevel = 200; }
};

int main() {
  Glass myGlass;
  string command{""};
  int amount{0};

  cout << "Robot Waiter Active. Enter amount to drink (or 'exit' to stop):"
       << endl;

  while (true) {
    cout << "Current Level: " << myGlass.liquidLevel << "ml. Drink how much? ";
    cin >> command;

    if (command == "exit" || command == "quit") {
      break;
    }

    amount = stoi(command);
    myGlass.Drink(amount);
  }

  return 0;
}
