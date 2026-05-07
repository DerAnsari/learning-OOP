#include <iostream>
#include <string>

template <typename T> int element_frequency(T arr[], int n, T val) {
  int count = 0;
  for (int i = 0; i < n; i++) {
    if (arr[i] == val) {
      count++;
    }
  }
  return count;
}

int main() {
  int intArr[] = {1, 2, 3, 2, 4, 2, 5};
  int iSize = sizeof(intArr) / sizeof(intArr[0]);
  int iTarget = 2;
  std::cout << "Frequency of " << iTarget
            << " in int array: " << element_frequency(intArr, iSize, iTarget)
            << std::endl;

  char charArr[] = {'a', 'b', 'a', 'c', 'a', 'd'};
  int cSize = sizeof(charArr) / sizeof(charArr[0]);
  char cTarget = 'a';
  std::cout << "Frequency of '" << cTarget
            << "' in char array: " << element_frequency(charArr, cSize, cTarget)
            << std::endl;

  std::string strArr[] = {"apple", "orange", "apple", "banana"};
  int sSize = sizeof(strArr) / sizeof(strArr[0]);
  std::string sTarget = "apple";
  std::cout << "Frequency of \"" << sTarget << "\" in string array: "
            << element_frequency(strArr, sSize, sTarget) << std::endl;

  return 0;
}
