#include <cmath>
#include <iostream>
using std::cin, std::cout, std::endl;

class Shape {
private:
  int len;
  int width;

public:
  void virtual calculateShape() = 0;

  virtual ~Shape() {};
};

class Rectangle : public Shape {
private:
  int len;
  int width;

public:
  Rectangle(int len, int width) : len(len), width(width) {}

  void calculateShape() override { cout << len * width; }
};

class Circle : public Shape {
private:
  int radius;
  const double pi = 3.143;

public:
  Circle(int radius) : radius(radius) {}

  void calculateShape() override { cout << pi * pow(radius, 2); }
};

class Triangle : public Shape {
private:
  int a;
  int b;
  int c;

public:
  Triangle(int a, int b, int c) : a(a), b(b), c(c) {}

  void calculateShape() override {
    double s = (a + b + c) / 2.0;
    cout << std::sqrt(s * ((s - a) * (s - b) * (s - c)));
  }
};

int main() {
  int choice;
  Shape *myShape = nullptr;

  cout << "Enter number of inputs (1 for Circle, 2 for Rectangle, 3 for "
          "Triangle): ";
  cin >> choice;

  if (choice == 1) {
    double r;
    cout << "Enter radius: ";
    cin >> r;
    myShape = new Circle(r);
  } else if (choice == 2) {
    double l, w;
    cout << "Enter length and width: ";
    cin >> l >> w;
    myShape = new Rectangle(l, w);
  } else if (choice == 3) {
    double a, b, c;
    cout << "Enter three sides: ";
    cin >> a >> b >> c;
    myShape = new Triangle(a, b, c);
  }

  if (myShape) {
    myShape->calculateShape(); // Polymorphism in action!
    delete myShape;            // Freeing memory
  } else {
    cout << "Invalid input!" << endl;
  }

  return 0;
}
