#include <cmath>
#include <iostream>
using std::pow, std::cout, std::endl;

class calculator {
private:
  int len;
  const double pi = 3.142;

public:
  calculator(int len) { this->len = len; }

  int getFootball() { return pow(len, 2); }
  int getcricket() { return len * (2 * len); }
  int getRobo() { return pi * pow(len, 2); }

  void giveAreas() {
    getFootball();
    getcricket();
    getRobo();

    cout << "Football field area: " << getFootball() << endl;
    cout << "Cricket groung area: " << getcricket() << endl;
    cout << "robot arena: " << getRobo() << endl;
  }
};

int main() {
  int sideInput;
  cout << "Enter the side length for the football ground: ";
  std::cin >> sideInput;

  calculator sportsDay(sideInput);
  sportsDay.giveAreas();

  return 0;
}
