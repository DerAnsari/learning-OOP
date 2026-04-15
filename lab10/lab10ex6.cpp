#include <iostream>
#include <vector>

using namespace std;

struct Card {
  int value;
  char suit;
};

void printCards(const vector<Card> &cards) {
  for (const auto &card : cards) {
    cout << "(" << card.value << "," << card.suit << ") ";
  }
  cout << endl;
}

// Standard Selection Sort (Unstable due to swap)
void selectionSortUnstable(vector<Card> &cards) {
  int n = cards.size();
  for (int i = 0; i < n - 1; ++i) {
    int minIndex = i;
    for (int j = i + 1; j < n; ++j) {
      if (cards[j].value < cards[minIndex].value) {
        minIndex = j;
      }
    }
    if (minIndex != i) {
      Card temp = cards[i];
      cards[i] = cards[minIndex];
      cards[minIndex] = temp;
    }
  }
}

// Stable Selection Sort (Stable using shift)
void selectionSortStable(vector<Card> &cards) {
  int n = cards.size();
  for (int i = 0; i < n - 1; ++i) {
    int minIndex = i;
    for (int j = i + 1; j < n; ++j) {
      if (cards[j].value < cards[minIndex].value) {
        minIndex = j;
      }
    }

    Card minCard = cards[minIndex];
    // Shift all elements between current index and minIndex
    while (minIndex > i) {
      cards[minIndex] = cards[minIndex - 1];
      minIndex--;
    }
    cards[i] = minCard;
  }
}

int main() {
  vector<Card> original = {{5, 'H'}, {3, 'D'}, {5, 'D'}, {1, 'C'}};

  cout << "Original Order: ";
  printCards(original);

  vector<Card> unstableCopy = original;
  selectionSortUnstable(unstableCopy);
  cout << "Unstable Selection Sort: ";
  printCards(unstableCopy);
  cout << "Note: (5,H) and (5,D) have swapped their relative order." << endl;

  vector<Card> stableCopy = original;
  selectionSortStable(stableCopy);
  cout << "Stable Selection Sort:   ";
  printCards(stableCopy);
  cout << "Note: (5,H) still precedes (5,D)." << endl;

  return 0;
}
