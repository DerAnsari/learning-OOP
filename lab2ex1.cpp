#include <cmath>
#include <iostream>
#include <numeric>
#include <string>

class Rational {
private:
  int num, den;

public:
  Rational(int n = 0, int d = 1) : num{n}, den{d} {
    if (den == 0)
      den = 1; // Basic safety to prevent division by zero
    reduce();
  }

  Rational(std::string Num) {
    size_t pos = Num.find('/');
    if (pos != std::string::npos) {
      num = std::stoi(Num.substr(0, pos));
      den = std::stoi(Num.substr(pos + 1));
      reduce();
    } else {
      num = std::stoi(Num);
      den = 1;
    }
  }

  Rational(float f) {
    std::string s = std::to_string(f);
    s.erase(s.find_last_not_of('0') + 1, std::string::npos);
    if (!s.empty() && s.back() == '.')
      s.pop_back();

    size_t dotPos = s.find('.');
    int precision = 1;
    if (dotPos != std::string::npos) {
      int digitsAfterDecimal = s.length() - dotPos - 1;
      precision = static_cast<int>(std::pow(10, digitsAfterDecimal));
    }
    num = static_cast<int>(std::round(f * precision));
    den = precision;
    reduce();
  }

  int get_num() const { return num; }
  int get_den() const { return den; }
  void set_num(int n) {
    num = n;
    reduce();
  }
  void set_den(int d) {
    if (d != 0)
      den = d;
    reduce();
  }

  std::string to_string() const {
    return (std::to_string(num) + "/" + std::to_string(den));
  }

  void reduce() {
    if (den == 0)
      return;
    int common = std::gcd(num, den);
    num /= common;
    den /= common;
    if (den < 0) {
      num = -num;
      den = -den;
    }
  }

  Rational operator+(const Rational &r) const {
    return Rational((num * r.den) + (r.num * den), den * r.den);
  }

  Rational operator-(const Rational &r) const {
    return Rational((num * r.den) - (r.num * den), den * r.den);
  }

  Rational operator*(const Rational &r) const {
    return Rational(num * r.num, den * r.den);
  }

  Rational operator/(const Rational &r) const {
    return Rational(num * r.den, den * r.num);
  }

  bool operator==(const Rational &r) const {
    return (num == r.num && den == r.den);
  }

  bool operator!=(const Rational &r) const { return !(*this == r); }
};

int main() {
  std::cout << "--- Testing Constructors ---" << std::endl;

  // Test Default and Integer Constructor
  Rational r1(1, 2);
  std::cout << "Rational(1, 2): " << r1.to_string() << " (Expected: 1/2)"
            << std::endl;

  // Test String Constructor
  Rational r2("3/4");
  std::cout << "Rational(\"3/4\"): " << r2.to_string() << " (Expected: 3/4)"
            << std::endl;

  // Test Float Constructor
  Rational r3(0.75f);
  std::cout << "Rational(0.75f): " << r3.to_string() << " (Expected: 3/4)"
            << std::endl;

  std::cout << "\n--- Testing Accessors and Mutators ---" << std::endl;
  r1.set_num(4);
  r1.set_den(6);
  std::cout << "After set_num(4) and set_den(6): " << r1.to_string()
            << " (Expected: 2/3 due to reduce)" << std::endl;
  std::cout << "get_num(): " << r1.get_num() << " | get_den(): " << r1.get_den()
            << std::endl;

  std::cout << "\n--- Testing Math Operators ---" << std::endl;
  Rational a(1, 2);
  Rational b(1, 3);

  Rational sum = a + b;
  std::cout << "1/2 + 1/3 = " << sum.to_string() << " (Expected: 5/6)"
            << std::endl;

  Rational diff = a - b;
  std::cout << "1/2 - 1/3 = " << diff.to_string() << " (Expected: 1/6)"
            << std::endl;

  Rational prod = a * b;
  std::cout << "1/2 * 1/3 = " << prod.to_string() << " (Expected: 1/6)"
            << std::endl;

  Rational quot = a / b;
  std::cout << "1/2 / 1/3 = " << quot.to_string() << " (Expected: 3/2)"
            << std::endl;

  std::cout << "\n--- Testing Comparison Operators ---" << std::endl;
  Rational c(2, 4); // Reduces to 1/2
  Rational d(1, 2);

  std::cout << "Is 2/4 == 1/2? " << (c == d ? "True" : "False")
            << " (Expected: True)" << std::endl;
  std::cout << "Is 1/2 != 1/3? " << (a != b ? "True" : "False")
            << " (Expected: True)" << std::endl;

  std::cout << "\n--- Testing Edge Cases ---" << std::endl;
  Rational neg(-1, -2);
  std::cout << "Rational(-1, -2): " << neg.to_string() << " (Expected: 1/2)"
            << std::endl;

  return 0;
}
