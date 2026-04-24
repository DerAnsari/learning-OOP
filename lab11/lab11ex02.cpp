#include <iostream>

int counterGlobal{0};

int fib(int n) {
  counterGlobal++;

  if (n == 0)
    return 0;

  if (n == 1)
    return 1;

  return fib(n - 1) + fib(n - 2);
}

int main() {
  int nums[] = {1, 5, 10, 15, 20};

  std::cout << "n | fib(n) | total calls to fib" << std::endl;

  for (int i : nums) {
    counterGlobal = 0;
    int results = fib(i);
    std::cout << i << " | " << results << " | "
              << counterGlobal << std::endl;
  }

  return 0;
}
