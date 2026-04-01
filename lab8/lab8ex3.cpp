#include <cmath>
#include <iostream>
#include <stdexcept>
using namespace std;

class DivisionByZeroException : public runtime_error {
public:
  DivisionByZeroException()
      : runtime_error("Division by zero is not allowed.") {}
};

double safeDivide(double num, double den) {
  if (den == 0)
    throw DivisionByZeroException();
  if (den < 0) {
    cout << "Warning: Converting negative denominator to positive.\n";
    den = abs(den);
  }
  return num / den;
}

int main() {
  double num, den;
  char again = 'y';

  while (again == 'y' || again == 'Y') {
    cout << "Enter numerator and denominator: ";

    if (!(cin >> num >> den)) {
      cout << "Invalid input! Please enter numerical values.\n";
      cin.clear();
      cin.ignore(1000, '\n');
    } else {
      try {
        cout << "Result: " << safeDivide(num, den) << "\n";
      } catch (const DivisionByZeroException &e) {
        cout << "Error: " << e.what() << "\n";
      }
    }

    cout << "Try again? (y/n): ";
    cin >> again;

    cin.ignore(1000, '\n');
  }
  return 0;
}
