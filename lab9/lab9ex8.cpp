#include <algorithm>
#include <functional>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>
using std::vector, std::cout, std::string;

struct Order {
  int id{0};
  string customer{""};
  double amount{0.0};
  bool isPaid{false};
};

int main() {
  vector<Order> orders = {
      {101, "Alice", 450.50, true},  {102, "Bob", 1200.00, false},
      {103, "Charlie", 85.25, true}, {104, "Diana", 1500.00, false},
      {105, "Eve", 300.00, true},    {106, "Frank", 2200.50, false},
      {107, "Grace", 45.00, true},   {108, "Hank", 950.00, false}};

  std::function<vector<Order>(const vector<Order> &)> filterStage =
      [](const vector<Order> &in) {
        vector<Order> res;
        std::copy_if(
            in.begin(), in.end(), std::back_inserter(res),
            [](const Order &x) { return x.isPaid && x.amount > 100.0; });
        return res;
      };

  std::function<vector<double>(const vector<Order> &)> mapStage =
      [](const vector<Order> &in) {
        vector<double> res;
        std::transform(in.begin(), in.end(), std::back_inserter(res),
                       [](const Order &x) { return x.amount * 0.90; });
        return res;
      };

  std::function<double(const vector<double> &)> reduceStage =
      [](const vector<double> &in) {
        return std::accumulate(in.begin(), in.end(), 0.0);
      };

  vector<Order> stage1 = filterStage(orders);
  vector<double> stage2 = mapStage(stage1);
  double totalRevenue = reduceStage(stage2);
  int qualifyingCount = static_cast<int>(stage2.size());

  cout << "--- Order Pipeline Summary ---" << std::endl;
  cout << "Qualifying Orders: " << qualifyingCount << std::endl;
  cout << "Total Discounted Revenue: $" << totalRevenue << std::endl;

  return 0;
}
