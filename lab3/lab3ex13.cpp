#include <iostream>
#include <string>
using std::cout, std::endl, std::string;

class Node {
public:
  string data;
  Node *next;
  Node(string data) : data(data), next(nullptr) {}
};

class Stack {
private:
  Node *top;

public:
  Stack() : top(nullptr) {}

  void push(string url) {
    Node *newNode = new Node(url);
    newNode->next = top;
    top = newNode;
  }

  string pop() {
    if (isEmpty())
      return "";
    string url = top->data;
    Node *temp = top;
    top = top->next;
    delete temp;
    return url;
  }

  string peek() {
    if (isEmpty())
      return "";
    return top->data;
  }

  bool isEmpty() { return top == nullptr; }

  void clear() {
    while (!isEmpty()) {
      pop();
    }
  }
};

int main() {
  Stack browser;

  browser.push("google.com");
  browser.push("youtube.com");
  browser.push("github.com");

  cout << "Current page: " << browser.peek() << endl;

  cout << "Going back to: " << browser.pop() << endl;
  cout << "Current page: " << browser.peek() << endl;

  browser.clear();
  cout << "History cleared. Empty: " << (browser.isEmpty() ? "Yes" : "No")
       << endl;

  return 0;
}
