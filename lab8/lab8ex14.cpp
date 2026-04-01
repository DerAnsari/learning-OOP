#include <iostream>
#include <stdexcept>
#include <vector>

template <typename T> class Queue {
  std::vector<T> elements;

public:
  void enqueue(T val) { elements.push_back(val); }

  void dequeue() {
    if (elements.empty())
      throw std::underflow_error("Queue Empty.");
    elements.erase(elements.begin()); // Removes from the front
  }

  T front() {
    if (elements.empty())
      throw std::underflow_error("Queue Empty.");
    return elements.front();
  }
};

int main() {
  std::cout << "\n--- Testing Queue ---" << std::endl;
  try {
    Queue<std::string> q;
    q.enqueue("First");
    q.enqueue("Second");
    std::cout << "Queue Front: " << q.front() << std::endl; // Should be "First"
    q.dequeue();
    std::cout << "Queue Front after dequeue: " << q.front()
              << std::endl; // Should be "Second"
  } catch (const std::exception &e) {
    std::cerr << "Caught: " << e.what() << std::endl;
  }
  return 0;
}
