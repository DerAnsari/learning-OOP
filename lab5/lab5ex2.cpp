#include <iostream>
using std::cout, std::endl;

class shape {
private:
  int len;
  int width;

public:
  shape(int len, int width) {
    this->len = len;
    this->width = width;
  }

  int getArea() const { return len * width; }

  int operator+(const shape &other) {
    return this->getArea() + other.getArea();
  }
};

int main() {
  shape shape1(10, 5); // Area = 50
  shape shape2(5, 4);  // Area = 20

  // Using the overloaded + operator
  int totalArea = shape1 + shape2;

  cout << "Area of Shape 1: " << shape1.getArea() << endl;
  cout << "Area of Shape 2: " << shape2.getArea() << endl;
  cout << "Combined Area: " << totalArea << endl;

  return 0;
}
