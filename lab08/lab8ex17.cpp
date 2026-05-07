#include <iostream>
#include <vector>
using std::vector;

template <typename T, typename BinaryOperation>
vector<vector<T>> matrix_operation(const vector<vector<T>> &m1,
                                   const vector<vector<T>> &m2, size_t rows,
                                   size_t cols, BinaryOperation op) {
  vector<vector<T>> result(rows, vector<T>(cols));

  for (size_t i = 0; i < rows; ++i) {
    for (size_t j = 0; j < cols; ++j) {
      result[i][j] = op(m1[i][j], m2[i][j]);
    }
  }
  return result;
};

int main() {
  size_t r = 2, c = 2;
  vector<vector<int>> mat1 = {{1, 2}, {3, 4}};
  vector<vector<int>> mat2 = {{10, 20}, {30, 40}};

  auto add = [](const int &a, const int &b) { return a + b; };

  auto sum = matrix_operation(mat1, mat2, r, c, add);

  for (const auto &row : sum) {
    for (int val : row)
      std::cout << val << " ";
    std::cout << "\n";
  }

  return 0;
}
