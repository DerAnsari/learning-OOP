#include <iostream>

int factorial(int n) {
  std::cout << "Entering factorial(" << n << ")" << std::endl;

  if (n == 0) {
    std::cout << "Returning factorial(0) = 1" << std::endl;
    return 1;
  }

  int result = n * factorial(n - 1);
  std::cout << "Returning factorial(" << n << ") = " << result << std::endl;
  return result;
}

int main() {
  int n{5};

  std::cout << factorial(5) << std::endl;
}
