#include <iostream>
#include <random>
#include <vector>

using namespace std;

struct Stats {
  long long comparisons = 0;
};

long long selectionSortCount(vector<int> arr) {
  long long comparisons = 0;
  int n = arr.size();
  for (int i = 0; i < n - 1; i++) {
    int minIdx = i;
    for (int j = i + 1; j < n; j++) {
      comparisons++;
      if (arr[j] < arr[minIdx]) {
        minIdx = j;
      }
    }
    if (minIdx != i) {
      int temp = arr[i];
      arr[i] = arr[minIdx];
      arr[minIdx] = temp;
    }
  }
  return comparisons;
}

long long insertionSortCount(vector<int> arr) {
  long long comparisons = 0;
  int n = arr.size();
  for (int i = 1; i < n; i++) {
    int key = arr[i];
    int j = i - 1;
    while (j >= 0) {
      comparisons++;
      if (arr[j] > key) {
        arr[j + 1] = arr[j];
        j--;
      } else {
        break;
      }
    }
    arr[j + 1] = key;
  }
  return comparisons;
}

int main() {
  int n = 1000;
  int k_values[] = {0, 5, 10, 50, 100, 500};
  int num_k = 6;

  mt19937 rng(42);
  uniform_int_distribution<int> dist(0, n - 1);

  cout << "k\tSelection Comp\tInsertion Comp\n";
  cout << "--------------------------------------------\n";

  for (int idx = 0; idx < num_k; idx++) {
    int k = k_values[idx];

    vector<int> testVec;
    for (int i = 1; i <= n; i++) {
      testVec.push_back(i);
    }

    for (int i = 0; i < k; i++) {
      int idx1 = dist(rng);
      int idx2 = dist(rng);

      int temp = testVec[idx1];
      testVec[idx1] = testVec[idx2];
      testVec[idx2] = temp;
    }

    long long selResult = selectionSortCount(testVec);
    long long insResult = insertionSortCount(testVec);

    cout << k << "\t" << selResult << "\t\t" << insResult << endl;
  }

  return 0;
}
