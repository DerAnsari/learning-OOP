#include <iostream>
using namespace std;

// base ^ exp : multiply base by itself exp times
double power(double base, int exp) {
  if (exp < 0) {
    return 1.0 / power(base, -exp);
  }

  if (exp == 0)
    return 1.0;                       // base case : anything ^0 = 1
  return base * power(base, exp - 1); // recursive case
}

int main() {
  cout << " 2^0 = " << power(2, 0) << " \n ";
  cout << " 2^5 = " << power(2, 5) << " \n ";
  cout << " 3^10 = " << power(3, 10) << " \n ";
  cout << " 10^4 = " << power(10, 4) << " \n ";
  cout << " 2^-3 = " << power(2, -3) << " \n ";
}
