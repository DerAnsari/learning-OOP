#include <iostream>
using std::cout, std::endl;

class CircularDriveThru {
private:
  int *spots;
  int front;
  int rear;
  int size;
  int capacity;

public:
  CircularDriveThru(int k) : front(0), rear(0), size(0), capacity(k) {
    spots = new int[k];
  }

  bool isEmpty() { return size == 0; }

  bool isFull() { return size == capacity; }

  bool parkCar(int carNumber) {
    if (isFull())
      return false;
    spots[rear] = carNumber;
    rear = (rear + 1) % capacity;
    size++;
    return true;
  }

  int carLeaves() {
    if (isEmpty())
      return -1;
    int car = spots[front];
    front = (front + 1) % capacity;
    size--;
    return car;
  }

  int frontCar() {
    if (isEmpty())
      return -1;
    return spots[front];
  }

  int lastCar() {
    if (isEmpty())
      return -1;
    return spots[(rear - 1 + capacity) % capacity];
  }
};

int main() {
  CircularDriveThru lane(3);
  cout << lane.parkCar(101) << endl;
  cout << lane.parkCar(102) << endl;
  cout << lane.parkCar(103) << endl;
  cout << lane.parkCar(104) << endl;
  cout << lane.carLeaves() << endl;
  cout << lane.parkCar(104) << endl;
  cout << lane.frontCar() << endl;
  cout << lane.lastCar() << endl;
  return 0;
}
