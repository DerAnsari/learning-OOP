#include <iostream>
#include <stdexcept>
#include <vector>

template <typename T> class Stack {
  std::vector<T> elements;

public:
  void push(T val) { elements.push_back(val); }

  void pop() {
    if (elements.empty())
      throw std::underflow_error("Stack Empty: Cannot pop.");
    elements.pop_back();
  }

  T top() {
    if (elements.empty())
      throw std::underflow_error("Stack Empty: No top element.");
    return elements.back();
  }
};

int main() {
  std::cout << "--- Testing Stack ---" << std::endl;
  try {
    Stack<int> s;
    s.push(10);
    s.push(20);
    std::cout << "Stack Top: " << s.top() << std::endl; // Should be 20
    s.pop();
    std::cout << "Stack Top after pop: " << s.top()
              << std::endl; // Should be 10
    s.pop();
    s.pop();
  } catch (const std::exception &e) {
    std::cerr << "Caught: " << e.what() << std::endl;
  }

  return 0;
}
