#include <iostream>
#include <vector>
using namespace std;

void printArray(const string &label, const vector<int> &arr) {
  cout << label;
  for (int x : arr)
    cout << x << " ";
  cout << " \n ";
}

void insertionSort(vector<int> &arr) {
  int n = arr.size();

  for (int i = 1; i < n; i++) {
    int key = arr[i]; // element to be inserted
    int j = i - 1;    // start of the shifting scan

    // Shift elements greater than ’ key ’ one position to the right
    while (j >= 0 && arr[j] < key) {
      arr[j + 1] = arr[j];
      j--;
    }

    arr[j + 1] = key; // insert key into the correct gap

    cout << " Pass " << i << " ( key = " << key << " ) : ";
    printArray(" ", arr);
  }
}

int main() {
  vector<int> data = {12, 11, 13, 5, 6};

  printArray(" Before : ", data);
  cout << " \n ";
  insertionSort(data);
  cout << " \n ";
  printArray(" After : ", data);
}
