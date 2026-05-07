#include <iostream>
#include <string>

template <typename T> void swap_values(T &a, T &b) {
  T temp = a;
  a = b;
  b = temp;
}

int main() {
  int x = 10, y = 20;
  std::cout << "Before swap: x=" << x << ", y=" << y << std::endl;
  swap_values(x, y);
  std::cout << "After swap:  x=" << x << ", y=" << y << "\n" << std::endl;

  std::string s1 = "World", s2 = "Hello";
  std::cout << "Before swap: s1=" << s1 << ", s2=" << s2 << std::endl;
  swap_values(s1, s2);
  std::cout << "After swap:  s1=" << s1 << ", s2=" << s2 << "\n" << std::endl;

  double d1 = 1.1, d2 = 9.9;
  std::cout << "Before swap: d1=" << d1 << ", d2=" << d2 << std::endl;
  swap_values(d1, d2);
  std::cout << "After swap:  d1=" << d1 << ", d2=" << d2 << std::endl;

  return 0;
}
