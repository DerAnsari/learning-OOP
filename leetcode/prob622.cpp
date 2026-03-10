class MyCircularQueue {
private:
  struct Node {
    int val;
    Node *next;
    Node(int v) : val(v), next(nullptr) {}
  };

  Node *head;
  Node *tail;
  int capacity;
  int size;

public:
  MyCircularQueue(int k) : head(nullptr), tail(nullptr), capacity(k), size(0) {}

  bool enQueue(int value) {
    if (isFull())
      return false;

    Node *newNode = new Node(value);
    if (isEmpty()) {
      head = tail = newNode;
      tail->next = head;
    } else {
      tail->next = newNode;
      tail = newNode;
      tail->next = head;
    }
    size++;
    return true;
  }

  bool deQueue() {
    if (isEmpty())
      return false;

    if (head == tail) {
      delete head;
      head = tail = nullptr;
    } else {
      Node *temp = head;
      head = head->next;
      tail->next = head;
      delete temp;
    }
    size--;
    return true;
  }

  int Front() { return isEmpty() ? -1 : head->val; }

  int Rear() { return isEmpty() ? -1 : tail->val; }

  bool isEmpty() { return size == 0; }

  bool isFull() { return size == capacity; }

  ~MyCircularQueue() {
    while (!isEmpty())
      deQueue();
  }
};
