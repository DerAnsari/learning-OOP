#include <iostream>
#include <string>

int countChar(const std::string &s, char c, int i = 0) {
  if (i == s.size())
    return 0;

  int match = (s[i] == c) ? 1 : 0;
  return match + countChar(s, c, i + 1);
}

std::string removeChar(const std::string &s, char c) {
  if (s.empty())
    return "";

  std::string rest = removeChar(s.substr(1), c);

  if (s[0] == c) {
    return rest;
  } else {
    return s[0] + rest;
  }
}

std::string toBinary(int n) {
  if (n == 0)
    return "0";
  if (n == 1)
    return "1";

  return toBinary(n / 2) + std::to_string(n % 2);
}

int main() {
  std::cout << "Count 'a' in banana: " << countChar("banana", 'a') << std::endl;

  std::cout << "Remove 'l' from hello world: " << removeChar("hello world", 'l')
            << std::endl;

  std::cout << "Binary of 10: " << toBinary(10) << std::endl;

  return 0;
}
