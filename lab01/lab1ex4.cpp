#include <cstdlib>
#include <iostream>
#include <string>

using std::cout, std::endl, std::string, std::exit, std::to_string;

class Polynomial {
  int A{0}, B{0}, C{0};

public:
  Polynomial() {
    A = 1;
    B = 1;
    C = 1;
  };

  Polynomial(int a, int b, int c) {
    A = a;
    B = b;
    C = c;
  };

  string format() {
    return to_string(A) + "x^2 + " + to_string(B) + "x + " + to_string(C);
  };

  int eval(int x) { return (A * x * x) + (B * x) + C; };

  Polynomial operator+(Polynomial &quad) {
    return Polynomial(A + quad.A, B + quad.B, C + quad.C);
  };

  int &operator[](int index) {

    switch (index) {
    case 0:
      return A;
    case 1:
      return B;
    case 2:
      return C;
    default:
      exit(1);
    }
  };

  bool operator==(Polynomial other) {
    return (A == other.A && B == other.B && C == other.C);
  };
};

int main() {
  Polynomial p1;
  Polynomial p2(3, -2, 5);

  cout << "--- Constructor & Format Test ---" << endl;
  cout << "P1 (Default): " << p1.format() << endl;
  cout << "P2 (Params) : " << p2.format() << endl;

  cout << "\n--- Evaluation Test ---" << endl;
  cout << "P2 evaluated at x=2: " << p2.eval(2) << " (Expected: 13)" << endl;

  Polynomial p3 = p1 + p2;
  cout << "\n--- Operator + Test ---" << endl;
  cout << "P1 + P2 = " << p3.format() << " (Expected: 4x^2 + -1x + 6)" << endl;

  cout << "\n--- Operator == Test ---" << endl;
  Polynomial p4(3, -2, 5);
  cout << "Is P2 == P4? " << (p2 == p4 ? "Yes" : "No") << " (Expected: Yes)"
       << endl;
  cout << "Is P1 == P2? " << (p1 == p2 ? "Yes" : "No") << " (Expected: No)"
       << endl;

  cout << "\n--- Operator [] Test ---" << endl;
  cout << "Changing P1 coefficients using []..." << endl;
  p1[0] = 10;
  p1[1] = 20;
  p1[2] = 30;
  cout << "P1 now: " << p1.format() << " (Expected: 10x^2 + 20x + 30)" << endl;

  return 0;
}
