#include <iostream>
#include <ostream>
#include <vector>

const int precision = 100;
class decimal {
  std::vector<int> digits;

public:
  // converts an unsigned value to a decimal
  decimal(unsigned value) : digits(precision) {
    for (int i = 0; i != precision; ++i) {
      digits[i] = value % 10;
      value /= 10;
    }
  }

  // prints decimal value
  void print(std::ostream &os) const {
    int i = precision - 1;
    // find first non-zero digit
    while (!digits[i] && i)
      --i;
    // print in reversed order
    do
      os << digits[i];
    while (i--);
  }

  // adds value of other decimal ignoring overflow
  decimal &operator+=(const decimal &other) {
    int carry{0};
    for (int i{0}; i < precision; i++) {
      int sum = this->digits[i] + other.digits[i];
      this->digits[i] = sum % 10;
      carry = sum / 10;
    }
    return *this;
  }
};

std::ostream &operator<<(std::ostream &os, const decimal &value) {
  value.print(os);
  return os;
}
int main() {
  decimal x = 123;
  x += 1056;
  std::cout << x << "\n";
}
