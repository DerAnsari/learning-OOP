#include <functional>
#include <iostream>
using std::function, std::cout;

function<int()> makeCounter(int start, int step) {
  return [start, step]() mutable -> int {
    start += step;
    return start;
  };
}

int main() {
  auto byOne = makeCounter(0, 1);
  auto byFive = makeCounter(0, 5);
  auto countdown = makeCounter(20, -3);

  cout << "Call | byOne | byFive | countdown" << "\n";
  cout << "------------------------------------" << "\n";

  for (int i = 1; i <= 5; ++i) {
    cout << i << "    |   " << byOne() << "   |   " << byFive() << "    |   "
         << countdown() << "\n";
  }

  cout << "\nAdvancing byOne again: " << byOne() << "\n";
  cout << "Checking byFive (should be unchanged from 25): " << byFive() << "\n";

  return 0;
}
