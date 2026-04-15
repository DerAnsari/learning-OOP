#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Stats {
  long long comparisons = 0;
  long long movements = 0;
};

// swap helper function
void manualSwap(int &a, int &b) {
  int temp = a;
  a = b;
  b = temp;
}

Stats selectionSort(vector<int> v) {
  Stats stats;
  int n = v.size();
  for (int i = 0; i < n - 1; ++i) {
    int minIndex = i;
    for (int j = i + 1; j < n; ++j) {
      stats.comparisons++;
      if (v[j] < v[minIndex]) {
        minIndex = j;
      }
    }
    if (minIndex != i) {
      manualSwap(v[i], v[minIndex]);
      stats.movements++;
    }
  }
  return stats;
}

Stats insertionSort(vector<int> v) {
  Stats stats;
  int n = v.size();
  for (int i = 1; i < n; ++i) {
    int key = v[i];
    int j = i - 1;
    while (j >= 0) {
      stats.comparisons++;
      if (v[j] > key) {
        v[j + 1] = v[j];
        stats.movements++;
        j--;
      } else {
        break;
      }
    }
    v[j + 1] = key;
  }
  return stats;
}

void printStats(const string &label, Stats sel, Stats ins) {
  cout << label << ":" << endl;
  cout << "  Selection -> Comp: " << sel.comparisons
       << " Swaps: " << sel.movements << endl;
  cout << "  Insertion -> Comp: " << ins.comparisons
       << " Shifts: " << ins.movements << endl
       << endl;
}

int main() {
  int n = 15;

  // i. Already sorted (replacing iota)
  vector<int> sorted;
  for (int i = 1; i <= n; ++i) {
    sorted.push_back(i);
  }

  // ii. Reverse sorted (replacing iota with reverse logic)
  vector<int> reverseSorted;
  for (int i = n; i >= 1; --i) {
    reverseSorted.push_back(i);
  }

  // iii. Random (Standard initialization is fine)
  vector<int> randomInput = {7, 12, 1, 15, 3, 8, 4, 10, 2, 14, 6, 11, 5, 9, 13};

  printStats("ALREADY SORTED", selectionSort(sorted), insertionSort(sorted));
  printStats("REVERSE SORTED", selectionSort(reverseSorted),
             insertionSort(reverseSorted));
  printStats("RANDOM INPUT", selectionSort(randomInput),
             insertionSort(randomInput));

  return 0;
}
