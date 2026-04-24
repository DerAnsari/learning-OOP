#include <iostream>

int sumDigits(int n) {
  if (n == 0)
    return 0;

  return (n % 10) + sumDigits(n / 10);
}

int main() {
  std::cout << "sumDigits(0):    " << sumDigits(0) << std::endl;
  std::cout << "sumDigits(9):    " << sumDigits(9) << std::endl;
  std::cout << "sumDigits(123):  " << sumDigits(123) << std::endl;
  std::cout << "sumDigits(9999): " << sumDigits(9999) << std::endl;

  return 0;
}
