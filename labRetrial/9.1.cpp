#include <iostream>
#include <string>

using MathOp = double (*)(double, double);

double add(double a, double b) { return a + b; }
double sub(double a, double b) { return a - b; }
double mul(double a, double b) { return a * b; }
double dvd(double a, double b) {
  if (b == 0)
    return 0; // Basic safety
  return a / b;
}

double compute(double a, double b, MathOp op) {
  return op(a, b); // No loop needed! Just invoke the pointer.
}

int main() {
  double a = 15.0, b = 4.0;

  // STEP 4: Store functions in the array using our alias
  MathOp ops[4] = {add, sub, mul, dvd};
  std::string names[4] = {"Addition", "Subtraction", "Multiplication",
                          "Division"};

  // STEP 5: Loop over the operations
  for (int i = 0; i < 4; i++) {
    double result = compute(a, b, ops[i]);
    std::cout << names[i] << ": " << result << std::endl;
  }

  return 0;
}