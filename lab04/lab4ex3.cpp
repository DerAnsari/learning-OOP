#include <iostream>
using std::cout, std::endl;

class Node {
public:
  char data;
  Node *next;
  Node(char data) : data(data), next(nullptr) {}
};

Node *removeNodes(Node *head, char chars[], int size) {
  Node *dummy = new Node('\0');
  dummy->next = head;
  Node *prev = dummy;
  Node *curr = head;

  while (curr != nullptr) {
    bool found = false;
    for (int i = 0; i < size; i++) {
      if (curr->data == chars[i]) {
        found = true;
        break;
      }
    }
    if (found) {
      prev->next = curr->next;
      delete curr;
      curr = prev->next;
    } else {
      prev = curr;
      curr = curr->next;
    }
  }

  head = dummy->next;
  delete dummy;
  return head;
}

int main() {
  Node *head = new Node('A');
  head->next = new Node('B');
  head->next->next = new Node('C');
  head->next->next->next = new Node('D');
  head->next->next->next->next = new Node('E');

  char chars[] = {'A', 'C', 'E'};
  head = removeNodes(head, chars, 3);

  for (Node *curr = head; curr != nullptr; curr = curr->next)
    cout << curr->data << " ";
  cout << endl;

  return 0;
}
