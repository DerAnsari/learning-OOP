#include <iostream>
#include <string>
using std::cout, std::cin, std::endl, std::string;

class Node {
public:
  string data;
  Node *next;
  Node(string data) : data(data), next(nullptr) {}
};

class Queue {
private:
  Node *front;
  Node *rear;

public:
  Queue() : front(nullptr), rear(nullptr) {}

  void enqueue(string order) {
    Node *newNode = new Node(order);
    if (rear == nullptr) {
      front = rear = newNode;
    } else {
      rear->next = newNode;
      rear = newNode;
    }
  }

  string dequeue() {
    string order = front->data;
    Node *temp = front;
    front = front->next;
    if (front == nullptr)
      rear = nullptr;
    delete temp;
    return order;
  }

  string getFront() {
    if (front == nullptr)
      return "";
    return front->data;
  }
};

class Stack {
private:
  Node *top;

public:
  Stack() : top(nullptr) {}

  void push(string order) {
    Node *newNode = new Node(order);
    newNode->next = top;
    top = newNode;
  }

  string pop() {
    if (top == nullptr)
      return "";
    string order = top->data;
    Node *temp = top;
    top = top->next;
    delete temp;
    return order;
  }

  string getTop() {
    if (top == nullptr)
      return "";
    return top->data;
  }
};

class Solution {
private:
  Stack s;
  Queue q;

public:
  void placeOrder(string order) { q.enqueue(order); }

  void processOrder() {
    string tempOrder = q.dequeue();
    if (tempOrder != "")
      s.push(tempOrder);
  }

  string deliverOrder() { return s.pop(); }

  string getNextKitchenOrder() { return q.getFront(); }

  string getNextDelivery() { return s.getTop(); }
};

int main() {
  Solution restaurant;

  restaurant.placeOrder("Pizza");
  restaurant.placeOrder("Burger");
  restaurant.placeOrder("Pasta");

  cout << "Next in kitchen: " << restaurant.getNextKitchenOrder() << endl;

  restaurant.processOrder();
  restaurant.processOrder();

  cout << "Next delivery: " << restaurant.getNextDelivery() << endl;
  cout << "Delivering: " << restaurant.deliverOrder() << endl;

  return 0;
}
