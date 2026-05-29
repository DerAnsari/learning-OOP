#include <numeric>
#include <string>
using std::string;

class Rational {
  int num, den;

public:
  Rational(int n = 0, int d = 1) : num{n}, den{d} {}

  Rational(string frac) {
    size_t slashPos = frac.find('/');
    if (slashPos != string::npos) {
      num = std::stoi(frac.substr(0, slashPos));
      den = std::stoi(frac.substr(slashPos + 1));
    } else {
      num = std::stoi(frac);
      den = 1;
    }
  }

  Rational(double decimal) {
    const int PRECISSION = 1000000000;

    int tempNum = static_cast<int>(decimal * PRECISSION);
    int tempDen = PRECISSION;
    int common = std::gcd(tempNum, tempDen);

    this->num = tempNum / common;
    this->den = tempDen / common;
  }

  int getNum() const { return num; }

  int getDen() const { return den; }

  void setNum(int n) { this->num = n; }

  void setDen(int d) { this->den = d; }

  string toString() const {
    return (std::to_string(num) + "/" + std::to_string(den));
  }

  void reduce() {
    int common = std::gcd(num, den);

    num /= common;
    den /= common;

    if (den < 0) {
      num = -num;
      den = -den;
    }
  }

  Rational operator+(const Rational &r) const {
    int reDen = den * r.den;
    int reNum = (num * r.den) + (r.num * den);
    Rational result = Rational(reNum, reDen);
    result.reduce();
    return result;
  }

  Rational operator-(const Rational &r) const {
    int reDen = den * r.den;
    int reNum = (num * r.den) - (r.num * den);
    Rational result = Rational(reNum, reDen);
    result.reduce();
    return result;
  }

  Rational operator*(const Rational &r) const {
    int reNum = num * r.num;
    int reDen = den * r.den;
    Rational result = Rational(reNum, reDen);
    result.reduce();
    return result;
  }

  Rational operator/(const Rational &r) const {
    int reNum = num * r.den;
    int reDen = den * r.num;
    Rational result = Rational(reNum, reDen);
    result.reduce();
    return result;
  }

  bool operator==(const Rational &r) const {
    if (num == r.num && den == r.den)
      return true;
    return false;
  }

  bool operator!=(const Rational &r) const {
    if (num == r.num && den == r.den)
      return false;
    return true;
  }
};
