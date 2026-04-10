#include <iostream>
#include <numeric>
#include <vector>
using std::vector, std::cout, std::endl;

// T result = std :: accumulate ( first , last , init , binary_op ) ;

vector<double> data = {4, 8, 15, 16, 23, 42, 7, 3, 19, 11};

int main() {

  double sumData = std::accumulate(data.begin(), data.end(), 0.0);

  double meanData = sumData / data.size();

  double minimum = std::accumulate(
      data.begin(), data.end(), data[0], [](double currentMin, double nextVal) {
        return (nextVal < currentMin) ? nextVal : currentMin;
      });

  double maximum = std::accumulate(
      data.begin(), data.end(), data[0], [](double currentMin, double nextVal) {
        return (nextVal > currentMin) ? nextVal : currentMin;
      });

  double sumSquares = std::accumulate(
      data.begin(), data.end(), 0.0,
      [](double total, double nextVal) { return total + (nextVal * nextVal); });

  double variance = std::accumulate(data.begin(), data.end(), 0.0,
                                    [meanData](double total, double x) {
                                      double diff = x - meanData;
                                      return total + (diff * diff);
                                    }) /
                    data.size();

  cout << "--- Statistics (std::accumulate) ---" << endl;
  cout << "Sum:            " << sumData << endl;
  cout << "Mean:           " << meanData << endl;
  cout << "Minimum:        " << minimum << endl;
  cout << "Maximum:        " << maximum << endl;
  cout << "Sum of Squares: " << sumSquares << endl;
  cout << "Variance:       " << variance << endl;

  // --- C++17 std::reduce Verification ---
  // std::reduce is similar but allows for parallel execution out-of-order
  double reduceSum = std::reduce(data.begin(), data.end(), 0.0);
  double reduceMean = reduceSum / data.size();

  cout << "\n--- Verification (std::reduce) ---" << endl;
  cout << "Reduce Sum:     " << reduceSum
       << " (Match: " << (sumData == reduceSum ? "Yes" : "No") << ")" << endl;
  cout << "Reduce Mean:    " << reduceMean
       << " (Match: " << (meanData == reduceMean ? "Yes" : "No") << ")" << endl;

  return 0;
}
