#include <iostream>
#include <string>
using std::cout, std::endl, std::string;

class Node {
public:
  int data;
  Node *next;
  Node(int data) : data(data), next(nullptr) {}
};

class Queue {
private:
  Node *front;
  Node *rear;

public:
  Queue() : front(nullptr), rear(nullptr) {}

  void enqueue(int order) {
    Node *newNode = new Node(order);
    if (rear == nullptr) {
      front = rear = newNode;
    } else {
      rear->next = newNode;
      rear = newNode;
    }
  }

  int getFront() { return front->data; }

  int dequeue() {
    int order = front->data;
    Node *temp = front;
    front = front->next;
    if (front == nullptr)
      rear = nullptr;
    delete temp;
    return order;
  }

  void moveNthFront(int n) {
    if (n == 1)
      return;

    Node *prevNode = nullptr;
    Node *currentNode = front;

    for (int i = 1; i < n; i++) {
      prevNode = currentNode;
      currentNode = currentNode->next;
    }

    prevNode->next = currentNode->next;

    if (currentNode == rear) {
      rear = prevNode;
    }

    currentNode->next = front;
    front = currentNode;
  }
  bool empty() { return front == nullptr; }
};

int main() {
  Queue q;
  for (int val : {5, 11, 34, 67, 43, 55})
    q.enqueue(val);
  q.moveNthFront(3);
  while (!q.empty())
    cout << q.dequeue() << " ";
  cout << endl;
  return 0;
}
