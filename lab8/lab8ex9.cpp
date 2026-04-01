#include <iostream>
#include <string>

template <typename T> T max_value(T a, T b, T c) {
  T max = a;

  if (b > max) {
    max = b;
  }
  if (c > max) {
    max = c;
  }
  return max;
}

int main() {
  int i1 = 10, i2 = 50, i3 = 30;
  std::cout << "Max Integer: " << max_value(i1, i2, i3) << std::endl;

  double d1 = 12.5, d2 = 4.2, d3 = 12.51;
  std::cout << "Max Double: " << max_value(d1, d2, d3) << std::endl;

  std::string s1 = "Apple", s2 = "Zebra", s3 = "Berry";
  std::cout << "Max String: " << max_value(s1, s2, s3) << std::endl;

  return 0;
}
