class crystalPair {
  int *players;

public:
  crystalPair(int p1, int p2) {
    this->players = new int[2];

    this->players[0] = p1;
    this->players[1] = p2;
  }

  crystalPair(crystalPair &other) {
    this->players = new int[2];

    other.players[0] = this->players[0];
    other.players[1] = this->players[1];
  }

  int sum() const { return players[0] + players[1]; }

  ~crystalPair() { delete[] players; }
};

int main() { return 0; }