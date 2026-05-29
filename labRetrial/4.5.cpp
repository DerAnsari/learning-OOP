#include <iostream>
struct Node {
  int data;
  Node *next;
};

class circularDriveThrough {
  Node *head;
  Node *tail;
  int maxSize;
  int currSize;

public:
  circularDriveThrough(int k)
      : head(nullptr), tail(nullptr), maxSize(k), currSize(0) {}

  // push
  void parkCar(int carNum) {
    if (isFull()) {
      std::cout << "Is full";
      return;
    }

    Node *newNode = new Node{carNum, nullptr};

    if (isEmpty()) {
      head = newNode;
      tail = newNode;
      tail->next = head;
    } else {
      tail->next = newNode;
      tail = newNode;
      tail->next = head;
    }

    currSize++;
  }

  // pop
  void carLeaves() {
    if (isEmpty()) {
      std::cout << "IS EMPTY";
      return;
    }
    if (head == tail) {
      delete head;
      head = tail = nullptr;
    } else {
      Node *temp = head;
      head = head->next;
      tail->next = head;
      delete temp;
    }
    currSize--;
  }

  int frontCar() { return ((isEmpty()) ? -1 : head->data); }

  int lastCar() { return ((isEmpty()) ? -1 : tail->data); }

  bool isEmpty() { return currSize == 0; }

  bool isFull() { return maxSize == 0; }
};

int main() { return 0; }