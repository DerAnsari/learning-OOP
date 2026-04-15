#include <iostream>
#include <string>
#include <vector>

using namespace std;

template <typename T, typename Compare>
void insertionSort(vector<T> &arr, Compare cmp) {
  int n = arr.size();
  for (int i = 1; i < n; ++i) {
    T key = arr[i];
    int j = i - 1;
    while (j >= 0 && cmp(key, arr[j])) {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = key;
  }
}

template <typename T> void printVector(const vector<T> &v) {
  for (const auto &x : v) {
    cout << x << " ";
  }
  cout << endl;
}

void printPairVector(const vector<pair<int, string>> &v) {
  for (const auto &p : v) {
    cout << "(" << p.first << ", " << p.second << ") ";
  }
  cout << endl;
}

int main() {
  // i. vector<int> ascending
  vector<int> v1 = {5, 2, 9, 1, 5, 6};
  insertionSort(v1, [](int a, int b) { return a < b; });
  cout << "Int Ascending: ";
  printVector(v1);

  // ii. vector<string> descending
  vector<string> v2 = {"apple", "orange", "banana", "pear"};
  insertionSort(v2, [](const string &a, const string &b) { return a > b; });
  cout << "String Descending: ";
  printVector(v2);

  // iii. vector<pair<int, string>> by key ascending, then value ascending
  vector<pair<int, string>> v3 = {{3, "C"}, {1, "B"}, {3, "A"}, {2, "D"}};
  insertionSort(v3, [](const pair<int, string> &a, const pair<int, string> &b) {
    if (a.first != b.first)
      return a.first < b.first;
    return a.second < b.second;
  });
  cout << "Pair Ascending Key/Tie-break String: ";
  printPairVector(v3);

  return 0;
}
