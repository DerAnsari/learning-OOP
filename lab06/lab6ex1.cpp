#include <iostream>
#include <string>

class shape {
protected:
  std::string color; // protected: accessible in this class and in derived class
                     // (circle)

public:
  void
  displaycolor() // public: accessible anywhere through object or derived class
  {
    std::cout << "The Color of the shape is: " << color << std::endl;
  }

  shape(std::string c) { color = c; }
};

class circle : public shape // public inheritance: protected and public members
                            // stay accessible
{
private:
  double radius; // private: accessible only inside circle class

public:
  circle(std::string c, double r) : shape(c) { radius = r; }

  double area() { return 3.14159 * radius * radius; }

  void display() {
    std::cout << "The area of the circle is: " << area() << std::endl;
    displaycolor();
  }
};

int main() {
  circle c1("Red", 5.0);
  c1.display();
  return 0;
}
