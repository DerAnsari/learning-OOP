#include <iostream>
#include <string>
#include <vector>

using std::vector, std::string;

class IntegerSet {
private:
  vector<bool> setInt;

public:
  IntegerSet() { setInt.assign(101, false); }

  IntegerSet unionofSet(const IntegerSet &otherSet) const {
    IntegerSet resultSet;
    for (int i = 0; i <= 100; i++) {
      if (this->setInt[i] || otherSet.setInt[i])
        resultSet.setInt[i] = true;
    }
    return resultSet;
  }

  IntegerSet intersectionofSet(const IntegerSet &otherSet) const {
    IntegerSet resultSet;
    for (int i = 0; i <= 100; i++) {
      if (this->setInt[i] && otherSet.setInt[i])
        resultSet.setInt[i] = true;
    }
    return resultSet;
  }

  void insertElement(int val) {
    if (val >= 0 && val <= 100)
      setInt[val] = true;
  }

  void deleteElement(int val) {
    if (val >= 0 && val <= 100)
      setInt[val] = false;
  }

  string to_string() const {
    string result = "";
    bool first = true;
    for (int i = 0; i <= 100; i++) {
      if (setInt[i]) {
        if (!first)
          result += " ";
        result += std::to_string(i);
        first = false;
      }
    }
    return result;
  }

  bool isEqualTo(const IntegerSet &otherSet) const {
    for (int i = 0; i <= 100; i++) {

      if (this->setInt[i] != otherSet.setInt[i]) {
        return false;
      }
    }
    return true;
  }

  IntegerSet(int ListofElements[]) {
    setInt.assign(101, false);

    for (int i = 0; i < 101; i++) {
      insertElement(ListofElements[i]);
    }
  }
};

int main() {
  // 1. Test Default Constructor
  IntegerSet setA;
  std::cout << "Initial setA (empty): \"" << setA.to_string() << "\""
            << std::endl;

  // 2. Test insertElement
  setA.insertElement(10);
  setA.insertElement(25);
  setA.insertElement(100);
  setA.insertElement(101); // Should be ignored (out of range)
  std::cout << "setA after inserts: " << setA.to_string() << std::endl;

  // 3. Test deleteElement
  setA.deleteElement(25);
  std::cout << "setA after deleting 25: " << setA.to_string() << std::endl;

  // 4. Test Array Constructor
  // Note: Since we are using the loop-to-101 version, we provide a 101-size
  // array
  int myArr[101] = {0};
  myArr[0] = 5;
  myArr[1] = 10;
  myArr[2] = 15;
  // The rest of the array is 0s due to initialization, but we only care about
  // 5, 10, 15
  IntegerSet setB(myArr);
  std::cout << "setB (from array): " << setB.to_string() << std::endl;

  // 5. Test Union (setA OR setB)
  // setA has {10, 100}, setB has {0, 5, 10, 15}
  // Union should be {0, 5, 10, 15, 100}
  IntegerSet unionSet = setA.unionofSet(setB);
  std::cout << "Union of A and B: " << unionSet.to_string() << std::endl;

  // 6. Test Intersection (setA AND setB)
  // Both have {10}
  IntegerSet intersectSet = setA.intersectionofSet(setB);
  std::cout << "Intersection of A and B: " << intersectSet.to_string()
            << std::endl;

  // 7. Test isEqualTo
  IntegerSet setC;
  setC.insertElement(10);
  setC.insertElement(100);

  std::cout << "Is setA equal to setC? "
            << (setA.isEqualTo(setC) ? "Yes" : "No") << " (Expected: Yes)"
            << std::endl;
  std::cout << "Is setA equal to setB? "
            << (setA.isEqualTo(setB) ? "Yes" : "No") << " (Expected: No)"
            << std::endl;

  return 0;
}
