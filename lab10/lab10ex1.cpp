#include <algorithm>
#include <iostream>

void selectionsort(int a[], int size) {
  for (int i = 0; i < size - 1; i++) {
    int minIdx = i;
    for (int j = i + 1; j < size; j++) {
      if (a[j] < a[minIdx]) {
        minIdx = j;
      }
    }
    if (minIdx != i) {
      std::swap(a[i], a[minIdx]);
    }
  }
}

int main() {
  int a[] = {29, 10, 14, 37, 13};
  int size = sizeof(a) / sizeof(a[0]);
  selectionsort(a, size);
  std::cout << "sorted array: ";
  for (int i = 0; i < size; i++) {
    std::cout << a[i] << " ";
  }
}

// i  j  minIdx  a[i]  a[j]  a[minIdx]  swap  [29,10,14,37,13]
// 0  1    0      29    10      29      yes   [10,29,14,37,13]
// 1  4    1      29    13      29      yes   [10,13,14,37,29]
// 2  3    2      14    37      14      no    [10,13,14,37,29]
// 3  4    3      37    13      29      yes   [10,13,14,29,37]
// 4  5    4      37    37      37      no    [10,13,14,29,37]
