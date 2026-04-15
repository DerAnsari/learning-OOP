#include <algorithm>
#include <iostream>
#include <vector>

void selectionsort(std::vector<int> &v) {
  for (int i = 0; i < v.size() - 1; i++) {
    int minIdx = i;
    for (int j = i + 1; j < v.size(); j++) {
      if (v[j] > v[minIdx]) {
        minIdx = j;
      }
    }
    if (minIdx != i) {
      std::swap(v[i], v[minIdx]);
    }
  }
}

int main() {
  std::vector<int> v = {3, 6, 1, 8, 2, 9, 4};
  selectionsort(v);
  std::cout << "sorted array: ";
  for (int i = 0; i < v.size(); i++) {
    std::cout << v[i] << " ";
  }
}

// i  j  maxIdx  v[i]  v[j]  v[maxIdx]  swap [3,6,1,8,2,9,4]
// 0  5    5      3     9      9       yes   [9,6,1,8,2,3,4]
// 1  3    3      6     8      8       yes   [9,8,1,6,2,3,4]
// 2  3    3      1     6      6       yes   [9,8,6,1,2,3,4]
// 3  6    6      1     4      4       yes   [9,8,6,4,2,3,1]
// 4  5    5      2     3      3       yes   [9,8,6,4,3,2,1]
// 5  5    5      2     2      2       no    [9,8,6,4,3,2,1]
