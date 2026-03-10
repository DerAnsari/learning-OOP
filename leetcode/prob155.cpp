class MinStack {
private:
  struct Node {
    int val;
    int min;
    Node *next;
    Node(int v, int mn, Node *n) : val(v), min(mn), next(n) {}
  };

  Node *head;

public:
  MinStack() : head(nullptr) {}

  void push(int val) {
    if (head == nullptr) {
      head = new Node(val, val, nullptr);
    } else {
      int newMin = (val < head->min) ? val : head->min;
      head = new Node(val, newMin, head);
    }
  }

  void pop() {
    if (head != nullptr) {
      Node *temp = head;
      head = head->next;
      delete temp;
    }
  }

  int top() { return head->val; }

  int getMin() { return head->min; }

  ~MinStack() {
    while (head) {
      pop();
    }
  }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
