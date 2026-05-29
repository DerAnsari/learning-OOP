struct node {
  int data;
  node *next;
};

class LinkedList {
  node *head;

public:
  LinkedList(int val) {
    head = new node();
    head->data = val;
    head->next = nullptr;
  }

  LinkedList() : head(nullptr) {}

  void append(int val) {
    node *newNode = new node();
    newNode->data = val;
    newNode->next = nullptr;

    node *temp = head;
    while (temp->next != nullptr) {
      temp = temp->next;
    }
    temp->next = newNode;
  }

  // Don't forget to clean up the heap!
  ~LinkedList() {
    node *current = head;
    while (current != nullptr) {
      node *nextNode = current->next;
      delete current;
      current = nextNode;
    }
  }
};

node *reverseList(node *first) {
  node *reverse{nullptr};
  node *second{nullptr};

  while (first != nullptr) {
    second = first->next;

    first->next = reverse;

    reverse = first;

    first = second;
  }

  return reverse;
}

int main() { return 0; }