#include <iostream>
#include <string>
using std::cout, std::endl, std::string;

struct Plane {
  string flightNum;
  string type;
  int severity;
  int arrivalTime;
};

class TakeoffStack {
private:
  Plane *data;
  int size;
  int capacity;

  void resize() {
    capacity *= 2;
    Plane *newData = new Plane[capacity];
    for (int i = 0; i < size; i++)
      newData[i] = data[i];
    delete[] data;
    data = newData;
  }

public:
  TakeoffStack(int capacity = 10) : size(0), capacity(capacity) {
    data = new Plane[capacity];
  }
  ~TakeoffStack() { delete[] data; }

  void push(Plane p) {
    if (size == capacity)
      resize();
    data[size++] = p;
  }

  Plane pop() {
    if (isEmpty())
      throw std::runtime_error("Stack is empty");
    return data[--size];
  }

  bool isEmpty() { return size == 0; }
};

class LandingQueue {
private:
  Plane *data;
  int size;
  int capacity;

  void resize() {
    capacity *= 2;
    Plane *newData = new Plane[capacity];
    for (int i = 0; i < size; i++)
      newData[i] = data[i];
    delete[] data;
    data = newData;
  }

  bool higherPriority(const Plane &a, const Plane &b) {
    if (a.severity != b.severity)
      return a.severity > b.severity;
    return a.arrivalTime < b.arrivalTime;
  }

public:
  LandingQueue(int capacity = 10) : size(0), capacity(capacity) {
    data = new Plane[capacity];
  }
  ~LandingQueue() { delete[] data; }

  void add(Plane p) {
    if (size == capacity)
      resize();
    data[size++] = p;
    int i = size - 1;
    while (i > 0 && higherPriority(data[i], data[i - 1])) {
      Plane temp = data[i];
      data[i] = data[i - 1];
      data[i - 1] = temp;
      i--;
    }
  }

  Plane next() {
    if (isEmpty())
      throw std::runtime_error("Queue is empty");
    Plane p = data[0];
    for (int i = 0; i < size - 1; i++)
      data[i] = data[i + 1];
    size--;
    return p;
  }

  bool isEmpty() { return size == 0; }
};

class ControlTower {
private:
  TakeoffStack takeoffStack;
  LandingQueue landingQueue;

public:
  void addPlane(Plane p) {
    if (p.type == "takeoff")
      takeoffStack.push(p);
    else
      landingQueue.add(p);
  }

  void nextAction() {
    if (!landingQueue.isEmpty()) {
      Plane p = landingQueue.next();
      cout << "Landing:  " << p.flightNum << " (severity: " << p.severity << ")"
           << endl;
    } else if (!takeoffStack.isEmpty()) {
      Plane p = takeoffStack.pop();
      cout << "Takeoff:  " << p.flightNum << endl;
    } else {
      cout << "No planes" << endl;
    }
  }
};

int main() {
  ControlTower tower;

  tower.addPlane({"AB123", "takeoff", 0, 1000});
  tower.addPlane({"CD456", "takeoff", 0, 1005});
  tower.addPlane({"EF789", "takeoff", 0, 1010});
  tower.addPlane({"GH101", "landing", 9, 1002});
  tower.addPlane({"IJ202", "landing", 10, 1006});
  tower.addPlane({"KL303", "landing", 8, 1009});

  tower.nextAction();
  tower.nextAction();
  tower.nextAction();
  tower.nextAction();

  return 0;
};
