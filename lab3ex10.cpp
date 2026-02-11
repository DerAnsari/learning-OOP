#include <iostream>
using std::cout, std::endl;

class Node {
public:
  int data;
  Node *next;

  Node(int data) : data(data), next(nullptr) {}
};

class LLStack {
private:
  Node *first;

public:
  LLStack() : first(nullptr) {}

  LLStack(const LLStack &s) {
    if (s.first == nullptr) {
      first = nullptr;
      return;
    }

    first = new Node(s.first->data);
    Node *current = first;
    Node *sCurrent = s.first->next;

    while (sCurrent != nullptr) {
      current->next = new Node(sCurrent->data);
      current = current->next;
      sCurrent = sCurrent->next;
    }
  }

  void push(int data) {
    Node *newNode = new Node(data);
    newNode->next = first;
    first = newNode;
  }

  int pop() {
    if (first == nullptr)
      return -1;
    int data = first->data;
    Node *temp = first;
    first = first->next;
    delete temp;
    return data;
  }

  void display() {
    Node *temp = first;
    while (temp != nullptr) {
      cout << temp->data << " ";
      temp = temp->next;
    }
    cout << endl;
  }
};

int main() {
  LLStack s;
  s.push(1);
  s.push(2);
  s.push(3);

  cout << "Original stack s: ";
  s.display();

  LLStack t{s};

  cout << "Copied stack t: ";
  t.display();

  s.push(4);
  t.pop();

  cout << "After s.push(4): ";
  s.display();
  cout << "After t.pop(): ";
  t.display();

  return 0;
}
