#include <iostream>
using std::cout, std::endl;

class CrystalPair {
private:
  int *crystalPower;

public:
  CrystalPair(int power1, int power2) {
    crystalPower = new int[2];
    crystalPower[0] = power1;
    crystalPower[1] = power2;
  }

  // Shallow copy would make both players share the same crystal array.
  // If one player modifies their crystals, it would affect the other player's
  // crystals too, which breaks the game rules in battle mode.
  CrystalPair(const CrystalPair &other) {
    crystalPower = new int[2];
    crystalPower[0] = other.crystalPower[0];
    crystalPower[1] = other.crystalPower[1];
  }

  int sum() const { return crystalPower[0] + crystalPower[1]; }

  void setCrystal(int index, int power) {
    if (index >= 0 && index < 2) {
      crystalPower[index] = power;
    }
  }
};

int main() {
  CrystalPair player1(10, 15);
  CrystalPair player2 = player1;
  player1.setCrystal(0, 50);
  cout << "Player 1 total: " << player1.sum() << endl;
  cout << "Player 2 total: " << player2.sum() << endl;
  return 0;
}
