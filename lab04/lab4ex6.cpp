#include <iostream>
#include <string>
using std::cout, std::endl, std::string, std::to_string;

class Stack {
private:
  int *data;
  int size;
  int capacity;

  void resize() {
    capacity *= 2;
    int *newData = new int[capacity];
    for (int i = 0; i < size; i++)
      newData[i] = data[i];
    delete[] data;
    data = newData;
  }

public:
  Stack(int capacity = 10) : size(0), capacity(capacity) {
    data = new int[capacity];
  }

  void push(int value) {
    if (size == capacity)
      resize();
    data[size++] = value;
  }

  int pop() {
    if (isEmpty())
      throw std::runtime_error("Stack is empty");
    return data[--size];
  }

  int peek() {
    if (isEmpty())
      throw std::runtime_error("Stack is empty");
    return data[size - 1];
  }

  bool isEmpty() { return size == 0; }

  int getSize() { return size; }

  void reverseMiddleHalf() {
    int quarter = size / 4;
    int start = quarter;
    int end = size - quarter - 1;
    while (start < end) {
      int temp = data[start];
      data[start] = data[end];
      data[end] = temp;
      start++;
      end--;
    }
  }

  string toString() {
    string result = "[";
    for (int i = 0; i < size; i++) {
      result += to_string(data[i]);
      if (i < size - 1)
        result += ", ";
    }
    result += "]";
    return result;
  }

  bool operator<(const Stack &other) const {
    if (size != other.size)
      return size > other.size;
    int sumA = 0, sumB = 0;
    for (int i = 0; i < size; i++)
      sumA += data[i];
    for (int i = 0; i < other.size; i++)
      sumB += other.data[i];
    if (sumA != sumB)
      return sumA > sumB;
    return data[size - 1] < other.data[other.size - 1];
  }
};

int main() {
  Stack s(10);
  for (int val : {10, 20, 30, 40, 50, 60, 70, 80, 90, 100})
    s.push(val);

  cout << "Before: " << s.toString() << endl;
  s.reverseMiddleHalf();
  cout << "After:  " << s.toString() << endl;

  return 0;
}
