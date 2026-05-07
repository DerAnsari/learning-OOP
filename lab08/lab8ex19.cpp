#include <iostream>

class Singleton {
private:
  Singleton() { std::cout << "Created once!\n"; }

  Singleton(const Singleton &) = delete;

public:
  static Singleton &getInstance() {
    static Singleton instance;
    return instance;
  }

  void doSomething() { std::cout << "Working...\n"; }
};

int main() {
  Singleton &s1 = Singleton::getInstance();
  Singleton &s2 = Singleton::getInstance();

  s1.doSomething();

  std::cout << &s1 << " == " << &s2 << std::endl;

  return 0;
}
