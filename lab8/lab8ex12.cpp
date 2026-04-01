#include <iostream>

template <typename T> void sort_array(T arr[], int size) {
  for (int i = 0; i < size - 1; i++) {
    for (int j = 0; j < size - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        T temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
}

template <typename T> void reverse_array(T arr[], int size) {
  int start = 0;
  int end = size - 1;
  while (start < end) {
    T temp = arr[start];
    arr[start] = arr[end];
    arr[end] = temp;
    start++;
    end--;
  }
}

template <typename T> int binary_search(T arr[], int size, T target) {
  if (size <= 0)
    return -1;

  int mid = size / 2;

  if (arr[mid] == target)
    return mid;

  if (arr[mid] > target) {
    return binary_search(arr, mid, target);
  } else {
    int result = binary_search(arr + mid + 1, size - mid - 1, target);
    return (result == -1) ? -1 : mid + 1 + result;
  }
}

int main() {
  int data[] = {45, 12, 85, 32, 7};
  int n = sizeof(data) / sizeof(data[0]);

  std::cout << "Original: ";
  for (int i : data)
    std::cout << i << " ";

  sort_array(data, n);
  std::cout << "\nSorted:   ";
  for (int i : data)
    std::cout << i << " ";

  reverse_array(data, n);
  std::cout << "\nReversed: ";
  for (int i : data)
    std::cout << i << " ";

  sort_array(data, n);
  int target = 32;
  int index = binary_search(data, n, target);
  std::cout << "\nBinary Search for " << target << ": Found at index " << index
            << std::endl;

  return 0;
}
