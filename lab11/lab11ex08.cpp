#include <iostream>

void countdown(int n) {
  if (n == 0) {
    std::cout << "Go!" << std::endl;
    return;
  }
  std::cout << n << std::endl; // Print BEFORE recurse
  countdown(n - 1);
}

void countup(int n) {
  if (n == 0) {
    std::cout << "Go!" << std::endl;
    return;
  }
  countup(n - 1);              // Recurse first
  std::cout << n << std::endl; // Print AFTER recurse
}

int main() {
  // Explanation: Swapping the cout position reverses the order because countdown prints
  // before the recursive call (top-down), while countup prints after the recursive 
  // call has returned (bottom-up/unwinding).
  std::cout << "--- Testing Countdown(5) ---" << std::endl;
  countdown(5);

  std::cout << "\n--- Testing Countup(5) ---" << std::endl;
  countup(5);

  return 0;
}
