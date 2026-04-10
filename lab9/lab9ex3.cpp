#include <iostream>
#include <vector>
using std::cout, std::vector;

int main() {
  int min{10}, max{50}, count{0};

  auto inRange = [min, max](int val) {
    return (val > min && val < max) ? true : false;
  };

  auto countInRange = [&count, inRange](int val) {
    if (inRange(val) == true) {
      count++;
    }
    return count;
  };

  auto scaleAndCheck = [inRange](auto x, auto factor) {
    auto scaledVal{x * factor};

    if (inRange(scaledVal) == true)
      return scaledVal;

    return -1.0;
  };

  vector<double> testValues = {5.0, 15.0, 25.0, 45.0, 60.0};
  double factor = 2.0;

  cout << "Range: [" << min << ", " << max << "]\n";

  for (auto val : testValues) {
    auto result = scaleAndCheck(val, factor);

    if (result != -1) {
      cout << "Value " << val << " scaled to " << result << " (In Range). ";
      cout << "Running Count: " << countInRange(static_cast<int>(result))
           << "\n";
    } else {
      cout << "Value " << val << " scaled to " << (val * factor)
           << " (Out of Range). ";
      cout << "Running Count: " << count << "\n";
    }
  }

  return 0;
}
