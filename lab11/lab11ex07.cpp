#include <string>
#include <vector>
using std::string, std::vector;

// was missing a basecase hence it would go into a infinite loop
//
int factorial(int n) {
  if (n <= 1)
    return 1; // Base case
  return n * factorial(n - 1);
}

// for abc will return cba
string reverse(const string &s) {
  if (s.size() == 0)
    return s;
  return reverse(s.substr(1)) + s[0];
}

// for 1,2,3 return 0 when it should retun 6
int sum(const vector<int> &arr, int i = 0) {
  if (i == (int)arr.size())
    return 0;
  return arr[i] + sum(arr, i + 1); // Add the current element
}

int main() { return 0; }
