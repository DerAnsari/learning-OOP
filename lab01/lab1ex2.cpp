#include <iostream>
#include <vector>

using std::cout, std::vector, std::endl;

class WareHouse {
  vector<int> productCode;
  vector<int> qualities;

public:
  void stock(int c, int q) {
    bool found{false};
    int size = productCode.size();

    for (int count{0}; count < size; count++) {
      if (productCode[count] == c) {
        qualities[count] += q;
        found = true;
      };
    };

    if (found == false) {
      productCode.push_back(c);
      qualities.push_back(q);
    }

    cout << q << "items with code " << c << "added" << endl;
  };

  void order(int c, int q) {
    bool order{false}, exist{false};
    int size = productCode.size();

    for (int count{0}; count < size; count++) {
      if (productCode[count] == c) {
        exist = true;
        if (qualities[count] >= q) {
          qualities[count] -= q;
          order = true;
        }
      };
    };

    if (order == true) {
      cout << q << "items delivered with code " << c << endl;
    } else {
      if (exist == true) {
        cout << "Cannot deliver, not enough stock" << endl;
      } else {
        cout << "code " << c << " not found" << endl;
      }
    }
  };

  void show(int c) {

    bool found{false};
    int size = productCode.size();

    for (int count{0}; count < size; count++) {
      if (productCode[count] == c) {
        cout << qualities[count] << "items are stored with code"
             << productCode[count] << endl;
        found = true;
      };
    };
    if (found == false) {
      cout << "code " << c << " not found" << endl;
    }
  };
};

int main() {
  WareHouse w;
  w.stock(1, 10); // print "10 items with code 1 added"
  w.stock(2, 20); // print "20 items with code 2 added"
  w.stock(3, 30); // print "30 items with code 3 added"
  w.stock(1, 5);  // print "5 more items with code 1 added, total 15"
  w.order(1, 3);  // print "3 items delivered with code 1"
  w.order(2, 25); // print "the requested quantity is not available"
  w.order(2, 11); // print "11 items delivered with code 2"
  w.order(4, 5);  // print "Code 4 not found"
  w.show(1);      // print "12 items are stored with code 1"
  w.show(2);      // print "9 items are stored with code 2"
  w.show(3);      // print "30 items are stored with code 3"
  w.show(4);      // print "Code 4 not found"
  return 0;
}
