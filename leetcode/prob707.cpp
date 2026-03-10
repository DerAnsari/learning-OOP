class MyLinkedList {
  struct Node {
    int val;
    Node *next;
    Node(int v) : val(v), next(nullptr) {}
  };

  Node *head;

public:
  MyLinkedList() : head(nullptr) {}

  int get(int index) {
    if (index < 0)
      return -1;
    Node *currptr = head;
    int count = 0;

    while (currptr != nullptr) {
      if (count == index) {
        return currptr->val;
      }
      count++;
      currptr = currptr->next;
    }
    return -1;
  }

  void addAtHead(int val) {
    Node *temp = new Node(val);
    temp->next = head;
    head = temp;
  }

  void addAtTail(int val) {
    if (head == nullptr) {
      addAtHead(val);
      return;
    }
    Node *temp = new Node(val);
    Node *currptr = head;
    while (currptr->next != nullptr) {
      currptr = currptr->next;
    }
    currptr->next = temp;
  }

  void addAtIndex(int index, int val) {
    if (index <= 0) {
      addAtHead(val);
      return;
    }
    Node *currptr = head;
    int count = 0;
    while (currptr != nullptr) {
      if (count == index - 1) {
        Node *temp = new Node(val);
        temp->next = currptr->next;
        currptr->next = temp;
        return;
      }
      count++;
      currptr = currptr->next;
    }
  }

  void deleteAtIndex(int index) {
    if (head == nullptr || index < 0)
      return;

    if (index == 0) {
      Node *toDelete = head;
      head = head->next;
      delete toDelete;
      return;
    }

    Node *currptr = head;
    int count = 0;
    while (currptr != nullptr && currptr->next != nullptr) {
      if (count == index - 1) {
        Node *toDelete = currptr->next;
        currptr->next = toDelete->next;
        delete toDelete;
        return;
      }
      count++;
      currptr = currptr->next;
    }
  }
};

// int main() {
//   MyLinkedList *obj = new MyLinkedList();
//   int param_1 = obj->get(index);
//   obj->addAtHead(val);
//   obj->addAtTail(val);
//   obj->addAtIndex(index, val);
//   obj->deleteAtIndex(index);
// }
