#include <cmath>
#include <cstdlib>
#include <string>
using std::string, std::to_string;

class Polynomial {
  int a, b, c;

public:
  Polynomial() : a(1), b(1), c(1) {}

  Polynomial(int a, int b, int c) : a(a), b(b), c(c) {}

  string format() {
    return (to_string(a) + "x^2 + " + to_string(b) + "x + " + to_string(c));
  }

  double eval(int x) {
    return (-b + std::sqrt(std::pow(b, 2) - 4 * a * c)) / (2 * a);
  }

  Polynomial operator+(Polynomial other) {
    return Polynomial(a + other.a, b + other.b, c + other.c);
  }

  int &operator[](int index) {
    switch (index) {
    case 0:
      return a;
    case 1:
      return b;
    case 2:
      return c;
    default:
      exit(1);
    }
  }

  bool operator==(Polynomial other) {
    if (other.a == a && other.b == b && other.c == c)
      return true;
    else
      return false;
  }
};
