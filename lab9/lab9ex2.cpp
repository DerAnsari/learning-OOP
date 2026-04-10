#include <functional>
#include <iostream>
#include <vector>

using std::endl, std::cout, std::vector;

// making the functor (class that acts like a function)
class Multiplier {
private:
  double factor;
  int callCount; // Private member

public:
  // Constructor
  Multiplier(double f) : factor(f), callCount(0) {}

  // Overload operator()
  double operator()(double x) {
    callCount++;
    return x * factor;
  }

  // Accessor
  int getCount() const { return callCount; }
};

// 2. Standalone event dispatcher
void dispatch(double val, vector<std::function<double(double)>> &handlers) {
  for (auto &handler : handlers) {
    cout << "Result: " << handler(val) << endl;
  }
}

int main() {
  Multiplier m2(2.0);
  Multiplier m3(3.0);
  Multiplier m5(5.0);

  vector<std::function<double(double)>> handlers;

  // Use ref()
  handlers.push_back(std::ref(m2));
  handlers.push_back(std::ref(m3));
  handlers.push_back(std::ref(m5));

  // Dispatch the value 6.0
  cout << "Dispatching value 6.0..." << endl;
  dispatch(6.0, handlers);

  cout << "\nCall Counts:" << endl;
  cout << "Multiplier (x2) count: " << m2.getCount() << endl;
  cout << "Multiplier (x3) count: " << m3.getCount() << endl;
  cout << "Multiplier (x5) count: " << m5.getCount() << endl;

  return 0;
}
