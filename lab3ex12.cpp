#include <iostream>
#include <string>
using std::cout, std::cin, std::endl, std::string;

class Node {
public:
  char data;
  Node *next;
  Node(char data) : data(data), next(nullptr) {}
};

class Stack {
private:
  Node *top;

public:
  Stack() : top(nullptr) {}

  void push(char ch) {
    Node *newNode = new Node(ch);
    newNode->next = top;
    top = newNode;
  }

  char pop() {
    char ch = top->data;
    Node *temp = top;
    top = top->next;
    delete temp;
    return ch;
  }
};

class Queue {
private:
  Node *front;
  Node *rear;

public:
  Queue() : front(nullptr), rear(nullptr) {}

  void enqueue(char ch) {
    Node *newNode = new Node(ch);
    if (rear == nullptr) {
      front = rear = newNode;
    } else {
      rear->next = newNode;
      rear = newNode;
    }
  }

  char dequeue() {
    char ch = front->data;
    Node *temp = front;
    front = front->next;
    if (front == nullptr)
      rear = nullptr;
    delete temp;
    return ch;
  }
};

class Solution {
private:
  Stack s;
  Queue q;

public:
  void pushCharacter(char ch) { s.push(ch); }

  void enqueueCharacter(char ch) { q.enqueue(ch); }

  char popCharacter() { return s.pop(); }

  char dequeueCharacter() { return q.dequeue(); }
};

int main() {
  string input;
  getline(cin, input);

  Solution obj;

  for (char c : input) {
    obj.pushCharacter(c);
    obj.enqueueCharacter(c);
  }

  bool isPalindrome = true;
  for (int i = 0; i < input.length() / 2; i++) {
    if (obj.popCharacter() != obj.dequeueCharacter()) {
      isPalindrome = false;
      break;
    }
  }

  cout << (isPalindrome ? "The word is a palindrome."
                        : "The word is not a palindrome.")
       << endl;

  return 0;
}
