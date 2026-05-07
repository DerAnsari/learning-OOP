#include <iostream>
using namespace std;

double add(double a, double b) { return a + b; }

double subtract(double a, double b) { return a - b; }

double multiply(double a, double b) { return a * b; }

double divide(double a, double b) { return a / b; }

// Function pointer type : pointer to a function taking two ints , returning int
typedef double (*BinaryOp)(double, double);

double applyOp(double x, double y, BinaryOp op) { return op(x, y); }

int main() {
  BinaryOp ops[] = {add, subtract, multiply, divide};
  const char *names[] = {" add ", " subtract ", " multiply ", "divide"};

  double a{15.0}, b{4.0};
  for (int i = 0; i < 4; i++)
    cout << names[i] << " (10 , 3) = " << applyOp(a, b, ops[i]) << " \n ";
  return 0;
}
