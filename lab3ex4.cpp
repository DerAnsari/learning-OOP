#include <iostream>
#include <string>

using std::string, std::cout, std::endl;

class Device {
private:
  static int numDevices;
  const int serialNum;

public:
  Device(const int serialNum) : serialNum(serialNum) { numDevices++; }

  static void printNumber() {
    cout << "Total Ammount of Devices: " << numDevices << endl;
  }
};

int Device::numDevices = 0;

int main() {
  Device d1(1001);
  Device d2(1002);
  Device d3(1003);

  d1.printNumber();
  Device::printNumber();

  // This would cause error if uncommented (demonstrates const safety):
  // d1.serialNum = 9999;  // ERROR: cannot modify const member

  return 0;
}
