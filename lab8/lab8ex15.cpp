#include <iostream>

template <typename T> class LinkedList {
  struct Node {
    T data;
    Node *next;
    Node(T val) : data(val), next(nullptr) {}
  };
  Node *head = nullptr;

public:
  void insert(T val) {
    Node *newNode = new Node(val);
    newNode->next = head;
    head = newNode;
  }

  void deleteVal(T val) {
    Node **curr = &head;
    while (*curr && (*curr)->data != val)
      curr = &((*curr)->next);
    if (*curr) {
      Node *temp = *curr;
      *curr = (*curr)->next;
      delete temp;
    }
  }

  void traverse() {
    Node *temp = head;
    while (temp) {
      std::cout << temp->data << " -> ";
      temp = temp->next;
    }
    std::cout << "NULL" << std::endl;
  }

  ~LinkedList() { // Cleanup memory
    while (head) {
      Node *temp = head;
      head = head->next;
      delete temp;
    }
  }
};

int main() {
  std::cout << "\n--- Testing LinkedList ---" << std::endl;
  LinkedList<double> list;
  list.insert(1.1);
  list.insert(2.2);
  list.insert(3.3);

  std::cout << "Initial List: ";
  list.traverse(); // Should show 3.3 -> 2.2 -> 1.1 -> NULL

  std::cout << "Deleting 2.2..." << std::endl;
  list.deleteVal(2.2);

  std::cout << "Final List: ";
  list.traverse(); // Should show 3.3 -> 1.1 -> NULL
  return 0;
}
