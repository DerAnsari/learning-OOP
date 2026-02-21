#include <iostream>

using std::endl, std::cout;

class WizardlyMath {
public:
  int multiply(int a, int b) { return a * b; }

  int multiply(int a, int b, int c) { return a * b * c; }

  double multiply(double a, double b) { return a * b; }

  double multiply(double a, double b, double c) { return a * b * c; }
};

int main() {
  WizardlyMath wizard;
  cout << "--- The Multiplication Grimoire ---" << endl;

  cout << "Two Integers (5 * 4): " << wizard.multiply(5, 4) << endl;
  cout << "Three Integers (2 * 3 * 4): " << wizard.multiply(2, 3, 4) << endl;

  cout << "Two Decimals (2.5 * 4.2): " << wizard.multiply(2.5, 4.2) << endl;
  cout << "Three Decimals (1.1 * 2.2 * 3.3): " << wizard.multiply(1.1, 2.2, 3.3)
       << endl;

  return 0;
}
