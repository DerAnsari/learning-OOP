#include <functional>
#include <iostream>
#include <vector>
using std::vector;

class Multiplier {
  double factor;
  int callcount{0};

public:
  Multiplier(double f) : factor(f) {}

  double operator()(double x) {
    callcount++;
    return x * factor;
  }

  int getCount() { return callcount; }

  void dispatch(double val, vector<std::function<double(double)>> &handlers) {
    for (auto &f : handlers) {
      std::cout << "Result: " << f(val) << std::endl;
    }
  }
};

int main() { return 0; }