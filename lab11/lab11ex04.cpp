#include <algorithm>
#include <iostream>
#include <vector>
int maxVal(const std::vector<int> &arr, int i = 0) {
  if (i == arr.size() - 1)
    return arr[i];

  return std::max(arr[i], maxVal(arr, i + 1));
}

bool isSorted(const std::vector<int> &arr, int i = 0) {
  if (i >= arr.size() - 1)
    return true;

  return (arr[i] <= arr[i + 1]) && isSorted(arr, i + 1);
}

void printReverse(const std::vector<int> &arr, int i = 0) {
  if (i == arr.size())
    return;

  printReverse(arr, i + 1);
  std::cout << arr[i] << " ";
}

int countEvens(const std::vector<int> &arr, int i = 0) {
  if (i == arr.size())
    return 0;

  int count = (arr[i] % 2 == 0) ? 1 : 0;
  return count + countEvens(arr, i + 1);
}

int main() {
  std::vector<int> testArr = {3, 7, 1, 9, 4, 6, 2};

  std::cout << "Max Value: " << maxVal(testArr) << std::endl;
  std::cout << "Is Sorted: " << (isSorted(testArr) ? "Yes" : "No") << std::endl;

  std::cout << "Reverse: ";
  printReverse(testArr);
  std::cout << std::endl;

  std::cout << "Count Evens: " << countEvens(testArr) << std::endl;

  return 0;
}
