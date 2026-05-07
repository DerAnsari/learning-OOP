#include <iostream>
using namespace std;

class Number {
private:
  float value;

public:
  Number(float v) : value(v) {}

  Number &operator--() {
    value *= 4;
    return *this;
  }

  Number operator--(int) {
    Number temp = *this;
    value /= 4;
    return temp;
  }

  void display() const { cout << "Current Value: " << value << endl; }
};

int main() {
  Number num(10);

  cout << "Initial value: ";
  num.display();

  --num;
  cout << "After prefix -- (multiplied by 4): ";
  num.display();

  num--;
  cout << "After postfix -- (divided by 4): ";
  num.display();

  return 0;
}
