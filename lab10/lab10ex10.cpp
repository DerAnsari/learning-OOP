#include <algorithm>
#include <iomanip>
#include <iostream>
#include <random>
#include <vector>

using namespace std;

long long insertionSort(vector<int> &v, int low, int high) {
  long long comparisons = 0;
  for (int i = low + 1; i <= high; ++i) {
    int key = v[i];
    int j = i - 1;
    while (j >= low) {
      comparisons++;
      if (v[j] > key) {
        v[j + 1] = v[j];
        j--;
      } else {
        break;
      }
    }
    v[j + 1] = key;
  }
  return comparisons;
}

long long hybridSort(vector<int> &v, int low, int high, int k) {
  if (high - low + 1 <= k) {
    return insertionSort(v, low, high);
  }

  long long comparisons = 0;
  // Selection sort pass: find min in [low, high] and move to v[low]
  int minIndex = low;
  for (int j = low + 1; j <= high; ++j) {
    comparisons++;
    if (v[j] < v[minIndex]) {
      minIndex = j;
    }
  }
  if (minIndex != low)
    swap(v[low], v[minIndex]);

  // Recursive call for the remaining unsorted part
  return comparisons + hybridSort(v, low + 1, high, k);
}

int main() {
  vector<int> ns = {50, 200, 1000};
  vector<int> ks = {5, 10, 20};
  mt19937 rng(42);

  cout << left << setw(10) << "n" << setw(10) << "k" << setw(15)
       << "Comparisons" << endl;
  cout << string(35, '-') << endl;

  for (int n : ns) {
    vector<int> original(n);
    for (int i = 0; i < n; ++i)
      original[i] = i;
    shuffle(original.begin(), original.end(), rng);

    for (int k : ks) {
      vector<int> testVec = original;
      long long comparisons = hybridSort(testVec, 0, n - 1, k);
      cout << left << setw(10) << n << setw(10) << k << setw(15) << comparisons
           << endl;
    }
  }

  return 0;
}
