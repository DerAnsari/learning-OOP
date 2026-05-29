class glass {
  int liquidLevel;

public:
  glass() : liquidLevel(200) {}

  void drink(int milimeter) {
    liquidLevel -= milimeter;
    if (liquidLevel <= 100) {
      refill();
    }
  }

  void refill() { liquidLevel = 200; }
};

int main() { return 0; }
