#include <cmath>
#include <iostream>

class Shapes {
public:
  virtual float getArea() = 0;

  virtual ~Shapes() {}
};

class Circle : public Shapes {
  float radius{0};

public:
  Circle(float r) : radius(r) {}

  float getArea() override { return M_PI * std::pow(radius, 2); }
};

class Triangle : public Shapes {
  float height{0}, base{0};

public:
  Triangle(float h, float b) : height(h), base(b) {}
  float getArea() override { return 0.5 * (base * height); }
};

class Rectangle : public Shapes {
  float length{0}, width{0};

public:
  Rectangle(float l, float w) : length(l), width(w) {}
  float getArea() override { return length * width; }
};

int main() {
  Shapes *circPtr = new Circle(5.5);
  Shapes *trigPtr = new Triangle(6, 3.5);
  Shapes *recPtr = new Rectangle(8, 4.2);

  std::cout << "Circle Area: " << circPtr->getArea() << std::endl;
  std::cout << "Triangle Area: " << trigPtr->getArea() << std::endl;
  std::cout << "Rectangle Area: " << recPtr->getArea() << std::endl;
  return 0;
}
