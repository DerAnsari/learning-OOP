#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>
using std::vector, std::endl, std::cout;

template <typename F> auto compose(F f) {
  return [f](auto x) { return f(x); };
}

template <typename F, typename... Args> auto compose(F f, Args... args) {
  return [f, rest = compose(args...)](auto x) { return f(rest(x)); };
}

int main() {
  auto negate = [](int x) { return x * -1; };
  auto addTen = [](int x) { return x + 10; };
  auto square = [](int x) { return x * x; };

  auto pipeline = compose(negate, addTen, square);

  vector<int> inputs = {1, 2, 3, 4, 5};
  vector<int> results;

  std::transform(inputs.begin(), inputs.end(), std::back_inserter(results),
                 pipeline);

  cout << "Composition Pipeline Results:\n";
  for (size_t i = 0; i < inputs.size(); ++i) {
    cout << inputs[i] << " -> " << results[i] << "\n";
  }

  std::function<long long(int)> fib;
  fib = [&fib](int n) -> long long {
    if (n <= 1)
      return n;
    return fib(n - 1) + fib(n - 2);
  };

  cout << "\nFibonacci(10): " << fib(10) << endl;

  return 0;
}
