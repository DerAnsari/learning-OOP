#include <iostream>
#include <vector>
using std::cout, std::endl, std::vector;

struct Record {
  int timestamp;
  int price;
};

class StockPrice {
private:
  vector<Record> records;
  int latestTimestamp = 0;

public:
  void update(int timestamp, int price) {
    for (auto &r : records) {
      if (r.timestamp == timestamp) {
        r.price = price;
        if (timestamp >= latestTimestamp)
          latestTimestamp = timestamp;
        return;
      }
    }
    records.push_back({timestamp, price});
    if (timestamp > latestTimestamp)
      latestTimestamp = timestamp;
  }

  int current() {
    for (auto &r : records)
      if (r.timestamp == latestTimestamp)
        return r.price;
    return -1;
  }

  int maximum() {
    int max = records[0].price;
    for (auto &r : records)
      if (r.price > max)
        max = r.price;
    return max;
  }

  int minimum() {
    int min = records[0].price;
    for (auto &r : records)
      if (r.price < min)
        min = r.price;
    return min;
  }
};

int main() {
  StockPrice sp;
  sp.update(1, 10);
  sp.update(2, 5);
  cout << sp.current() << endl; // 5
  cout << sp.maximum() << endl; // 10
  sp.update(1, 3);
  cout << sp.maximum() << endl; // 5
  sp.update(4, 2);
  cout << sp.minimum() << endl; // 2
  return 0;
}
