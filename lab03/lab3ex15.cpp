#include <iostream>
#include <string>
using std::string, std::cout, std::endl;

class Node {
public:
  string action;
  Node *next;
  Node(string action) : action(action), next(nullptr) {}
};

class Stack {
private:
  Node *top;

public:
  Stack() : top(nullptr) {}

  void push(string action) {
    Node *newNode = new Node(action);
    newNode->next = top;
    top = newNode;
  }

  string pop() {
    if (isEmpty())
      return "";
    string action = top->action;
    Node *temp = top;
    top = top->next;
    delete temp;
    return action;
  }

  bool isEmpty() { return top == nullptr; }

  void clear() {
    while (!isEmpty()) {
      pop();
    }
  }

  ~Stack() { clear(); }
};

class TextEditor {
private:
  Stack undoStack;
  Stack redoStack;

public:
  void doAction(string action) {
    undoStack.push(action);
    redoStack.clear();
  }

  void undo() {
    if (!canUndo())
      return;
    string action = undoStack.pop();
    redoStack.push(action);
  }

  void redo() {
    if (!canRedo())
      return;
    string action = redoStack.pop();
    undoStack.push(action);
  }

  bool canUndo() { return !undoStack.isEmpty(); }

  bool canRedo() { return !redoStack.isEmpty(); }

  void clearAll() {
    undoStack.clear();
    redoStack.clear();
  }
};

int main() {
  TextEditor editor;

  editor.doAction("Type: Hello");
  editor.doAction("Type: World");
  editor.doAction("Delete: d");

  cout << "Can undo: " << (editor.canUndo() ? "Yes" : "No") << endl;

  editor.undo();
  cout << "After undo, can redo: " << (editor.canRedo() ? "Yes" : "No") << endl;

  editor.redo();
  cout << "After redo, can undo: " << (editor.canUndo() ? "Yes" : "No") << endl;

  editor.clearAll();
  cout << "After clear, can undo: " << (editor.canUndo() ? "Yes" : "No")
       << endl;

  return 0;
}
