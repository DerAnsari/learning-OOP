#include <iostream>
#include <queue>

template <typename T, typename PriorityFunc = std::less<T>>
class PriorityQueue {
  std::priority_queue<T, std::vector<T>, PriorityFunc> pq;

public:
  void insert(const T &element) { pq.push(element); };

  T getHighestPriority() {
    T topElement = pq.top();
    pq.pop();
    return topElement;
  };
};

struct MinPriority {
  bool operator()(const int &a, const int &b) { return a > b; }
};

int main() {
  std::cout << "\n--- Custom Priority ---" << std::endl;
  PriorityQueue<int, MinPriority> minPQ;
  minPQ.insert(10);
  minPQ.insert(50);
  minPQ.insert(30);
  std::cout << "Highest (Smallest value): " << minPQ.getHighestPriority()
            << std::endl;
}
