#include <chrono>
#include <iostream>

class MemoryPool {
private:
  char *pool;
  size_t size;
  size_t used;

public:
  MemoryPool(size_t totalSize) : size(totalSize), used(0) {
    pool = new char[totalSize];
  }

  void *allocate(size_t objectSize) {
    if (used + objectSize > size)
      return nullptr;

    void *address = pool + used;
    used += objectSize;
    return address;
  }

  ~MemoryPool() { delete[] pool; }
};

struct SmallObject {
  int data[10];
};

int main() {
  const int iterations = 1000000;

  // --- Testing Standard 'new' ---
  auto start1 = std::chrono::high_resolution_clock::now();
  for (int i = 0; i < iterations; ++i) {
    SmallObject *obj = new SmallObject();
    delete obj;
  }
  auto end1 = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> diff1 = end1 - start1;
  std::cout << "Standard 'new/delete' time: " << diff1.count() << "s\n";

  // --- Testing Memory Pool ---
  MemoryPool myPool(iterations * sizeof(SmallObject));
  auto start2 = std::chrono::high_resolution_clock::now();
  for (int i = 0; i < iterations; ++i) {
    void *mem = myPool.allocate(sizeof(SmallObject));
    SmallObject *obj = new (mem) SmallObject(); // "Placement New"
  }
  auto end2 = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> diff2 = end2 - start2;
  std::cout << "Memory Pool time:           " << diff2.count() << "s\n";

  return 0;
}
