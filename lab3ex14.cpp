#include <iostream>
#include <string>
using std::string, std::cout, std::endl;

class Node {
public:
  string job;
  int jobId;
  Node *next;
  Node(string job, int jobId) : job(job), jobId(jobId), next(nullptr) {}
};

class Queue {
private:
  Node *front;
  Node *rear;

public:
  Queue() : front(nullptr), rear(nullptr) {}

  void enqueue(string job, int jobId) {
    Node *newNode = new Node(job, jobId);
    if (rear == nullptr) {
      front = rear = newNode;
    } else {
      rear->next = newNode;
      rear = newNode;
    }
  }

  string dequeue() {
    if (isEmpty())
      return "";
    string job = front->job;
    Node *temp = front;
    front = front->next;
    if (front == nullptr)
      rear = nullptr;
    delete temp;
    return job;
  }

  string peek() {
    if (isEmpty())
      return "";
    return front->job;
  }

  void remove(int jobId) {
    if (isEmpty())
      return;

    if (front->jobId == jobId) {
      dequeue();
      return;
    }

    Node *temp = front;
    while (temp->next != nullptr && temp->next->jobId != jobId) {
      temp = temp->next;
    }

    if (temp->next != nullptr) {
      Node *toDelete = temp->next;
      temp->next = temp->next->next;
      if (toDelete == rear)
        rear = temp;
      delete toDelete;
    }
  }

  bool isEmpty() { return front == nullptr; }
};

int main() {
  Queue printer;

  printer.enqueue("Document1.pdf", 1);
  printer.enqueue("Image.jpg", 2);
  printer.enqueue("Report.docx", 3);

  cout << "Next job: " << printer.peek() << endl;
  cout << "Processing: " << printer.dequeue() << endl;

  printer.remove(2);
  cout << "Next job after cancel: " << printer.peek() << endl;

  return 0;
}
