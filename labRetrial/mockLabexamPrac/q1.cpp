#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

using std::string, std::vector, std::cout, std::function, std::endl;

template <typename T>
void insertionSort(vector<T> &v, function<bool(const T &, const T &)> comp) {
  int n = v.size();

  for (int i{1}; i < n; i++) {
    T key = v[i];
    int j = i - 1;

    while (j >= 0 && comp(v[j], key)) {
      v[j + 1] = v[j];
      j--;
    }
    v[j + 1] = key;
  }
}

int partition(vector<int> &v, int lo, int hi) {
  int pivot = v[hi];
  int i = (lo - 1);

  for (int j = lo; j <= hi - 1; j++) {
    if (v[j] <= pivot) {
      i++;
      std::swap(v[i], v[j]);
    }
  }
  std::swap(v[i + 1], v[hi]);
  return i + 1;
}

void quickSort(vector<int> &v, int lo, int hi) {
  if (lo < hi) {
    int p = partition(v, lo, hi);

    quickSort(v, lo, p - 1);
    quickSort(v, p - 1, hi);
  }
}

template <typename N> void display(vector<N> &v) {
  for (auto &i : v) {
    cout << i << " ";
  }
  cout << endl;
}

struct LengthFunc {
  bool operator()(const string &a, const string &b) const {
    return a.length() < b.length();
  }
};

bool ascen(const int &v1, const int &v2) { return (v1 < v2); }

int main() {
  vector<int> dih = {5, 3, 8, 1, 9, 2, 7};

  insertionSort<int>(dih, ascen);

  display(dih);

  auto descen = [](int v1, int v2) { return (v1 > v2); };

  insertionSort<int>(dih, descen);

  display(dih);

  vector<string> words = {"banana", "apple", "cherry", "date"};
  insertionSort<string>(words, LengthFunc());
  display(words);

  vector<int> data = {10, 3, 76, 34, 23, 1, 45};

  // Initial call: lo = 0, hi = size - 1
  quickSort(data, 0, data.size() - 1);

  cout << "Sorted: ";
  for (int i = 0; i < data.size(); i++) {
    cout << data[i] << (i == data.size() - 1 ? "" : " ");
  }
  cout << endl;

  return 0;
}