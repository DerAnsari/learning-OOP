#include <algorithm>
#include <iostream>
#include <vector>

using std::vector, std::cout;

// Standard Insertion Sort: Linear Search + Shifting
long long standardInsertionSort(vector<int> arr) {
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

// Binary Insertion Sort: Binary Search + Shifting
long long binaryInsertionSort(vector<int> arr) {
  long long comparisons = 0;
  int n = arr.size();
  for (int i = 1; i < n; i++) {
    int key = arr[i];

    auto it = std::lower_bound(arr.begin(), arr.begin() + i, key,
                               [&comparisons](int a, int b) {
                                 comparisons++;
                                 return a < b;
                               });

    int insertionPos = std::distance(arr.begin(), it);

    for (int j = i; j > insertionPos; j--) {
      arr[j] = arr[j - 1];
    }
    arr[insertionPos] = key;
  }
  return comparisons;
}

int main() {
  vector<int> data = {19, 1, 15, 7, 3, 12, 18, 2,  9, 11,
                      20, 4, 13, 8, 5, 17, 16, 10, 6, 14};

  cout << "Array Size: 20\n";
  cout << "Standard Insertion Sort Comparisons: " << standardInsertionSort(data)
       << "\n";
  cout << "Binary Insertion Sort Comparisons:   " << binaryInsertionSort(data)
       << "\n";

  return 0;
}
