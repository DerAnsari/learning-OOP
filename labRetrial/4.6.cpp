#include <iostream>
#include <string>
using std::string;

class Stack {
  int *data;
  int maxCapacity;
  int currCapacity;

public:
  Stack(int c) : maxCapacity(c), currCapacity(0) { data = new int[c]; }

  void push(int val) {
    if (currCapacity == maxCapacity) {
      maxCapacity *= 2;
      int *newData = new int[maxCapacity];
      for (int i = 0; i < currCapacity; i++) {
        newData[i] = data[i];
      }
      delete[] data;
      data = newData;
    }

    data[currCapacity++] = val;
  }

  int pop() {
    if (isEmpty()) {
      std::cout << "IS EMPTY";
      return -1;
    }

    return (data[--currCapacity]);
  }

  int peek() {
    if (isEmpty()) {
      std::cout << "IS EMPTY";
      return -1;
    }
    return (data[currCapacity - 1]);
  }

  bool isEmpty() { return ((currCapacity == 0) ? true : false); }

  int getSize() { return currCapacity; }

  void reverMiddleHalf() {
    if (currCapacity < 2)
      return; // Not enough to reverse

    int quarter = currCapacity / 4;
    int start = quarter;                  // Start of middle half
    int end = currCapacity - quarter - 1; // End of middle half

    while (start < end) {
      int temp = data[start];
      data[start] = data[end];
      data[end] = temp;
      start++;
      end--;
    }
  }

  string toString() {
    string result{"["};
    for (int i{0}; i < currCapacity; i++) {
      result += std::to_string(data[i]);
      if (i < currCapacity - 1)
        result += ", ";
    }
    result += "]";
    return result;
  }
};