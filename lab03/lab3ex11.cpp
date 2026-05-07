#include <iostream>
using std::cout, std::endl;

class Node {
public:
  int data;
  Node *next;

  Node(int data) {
    this->data = data;
    next = nullptr;
  }
};

class linkedList {
private:
  Node *head;

public:
  linkedList() { head = nullptr; }

  void addNode(int data) {
    Node *newNode = new Node(data);
    if (head == nullptr) {
      head = newNode;
    } else {
      Node *temp = head;
      while (temp->next != nullptr) {
        temp = temp->next;
      }
      temp->next = newNode;
    }
  }

  void reverseList() { head = reverse(head); }

  // used a helper function because the head is private variable;
  Node *reverse(Node *node) {
    if (node == nullptr || node->next == nullptr)
      return node;
    Node *newHead = reverse(node->next);
    node->next->next = node;
    node->next = nullptr;
    return newHead;
  }

  void display() {
    Node *temp = head;
    while (temp != nullptr) {
      cout << temp->data << " -> ";
      temp = temp->next;
    }
    cout << "null" << endl;
  }
};

int main() {
  linkedList list;
  list.addNode(1);
  list.addNode(2);
  list.addNode(3);
  list.addNode(4);
  list.addNode(5);

  cout << "Original: ";
  list.display();

  list.reverseList();

  cout << "Reversed: ";
  list.display();

  return 0;
}
