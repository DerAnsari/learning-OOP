#include <iostream>

using std::cout, std::cin, std::endl;

int josephus(int n, int m) {
  if (n == 1)
    return 0;
  return (josephus(n - 1, m) + m) % n;
}

int main() {
  int n, m;
  cout << "Enter number of people (n): ";
  cin >> n;
  cout << "Enter elimination count (m): ";
  cin >> m;

  cout << "Safe position: " << josephus(n, m) << endl;

  return 0;
}
