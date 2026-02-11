#include <iostream>
#include <string>

using std::string, std::cout, std::endl, std::cin;

class Stack {
private:
  char *data{nullptr};
  int capacity{0};
  int topIdx{-1};

public:
  void resize(int nCap) {
    char *nData = new char[nCap];
    for (int i = 0; i <= topIdx; i++) {
      nData[i] = data[i];
    }
    delete[] data;
    data = nData;
    capacity = nCap;
  }

  void push(char val) {
    if (topIdx + 1 >= capacity) {
      resize(capacity == 0 ? 10 : capacity * 2);
    }
    data[++topIdx] = val;
  }

  char pop() {
    if (isEmpty())
      return '\0';
    return data[topIdx--];
  }

  bool isEmpty() const { return topIdx == -1; }
};

bool checkBalance(string input) {
  Stack s;

  for (char c : input) {
    if (c == '(' || c == '[' || c == '{') {
      s.push(c);
    } else {
      if (s.isEmpty())
        return false;

      char top = s.pop();
      if ((c == ')' && top != '(') || (c == ']' && top != '[') ||
          (c == '}' && top != '{')) {
        return false;
      }
    }
  }
  return s.isEmpty();
}

int main() {
  string input;
  if (!(cin >> input))
    return 0;

  if (checkBalance(input)) {
    cout << "true" << endl;
  } else {
    cout << "false" << endl;
  }

  return 0;
}
