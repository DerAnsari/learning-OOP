#include <iostream>
#include <stdexcept>
#include <vector>

template <typename T> class SparseMatrix {
private:
  struct Element {
    int r, c;
    T val;
  };
  int rows, cols;
  std::vector<Element> data;

  T get(int r, int c) const {
    for (const auto &e : data) {
      if (e.r == r && e.c == c)
        return e.val;
    }
    return T(0);
  }

public:
  SparseMatrix(int r, int c) : rows(r), cols(c) {}

  void set(int r, int c, T val) {
    if (r >= rows || c >= cols)
      throw std::out_of_range("Index out of bounds");
    if (val != T(0))
      data.push_back({r, c, val});
  }

  SparseMatrix operator+(const SparseMatrix &other) const {
    if (rows != other.rows || cols != other.cols)
      throw std::logic_error("Dimension mismatch for addition");

    SparseMatrix result(rows, cols);
    for (int i = 0; i < rows; ++i) {
      for (int j = 0; j < cols; ++j) {
        T sum = this->get(i, j) + other.get(i, j);
        if (sum != T(0))
          result.set(i, j, sum);
      }
    }
    return result;
  }

  SparseMatrix operator*(const SparseMatrix &other) const {
    if (cols != other.rows)
      throw std::logic_error("Incompatible dimensions for multiplication");

    SparseMatrix result(this->rows, other.cols);
    for (int i = 0; i < this->rows; ++i) {
      for (int j = 0; j < other.cols; ++j) {
        T dotProduct = T(0);
        for (int k = 0; k < this->cols; ++k) {
          dotProduct += this->get(i, k) * other.get(k, j);
        }
        if (dotProduct != T(0))
          result.set(i, j, dotProduct);
      }
    }
    return result;
  }

  void display() const {
    for (int i = 0; i < rows; ++i) {
      for (int j = 0; j < cols; ++j) {
        std::cout << get(i, j) << " ";
      }
      std::cout << "\n";
    }
  }
};

int main() {
  SparseMatrix<int> m1(2, 2);
  m1.set(0, 0, 5);
  m1.set(1, 1, 8);

  SparseMatrix<int> m2(2, 2);
  m2.set(0, 0, 1);
  m2.set(1, 1, 2);

  std::cout << "Matrix 1 + Matrix 2:\n";
  (m1 + m2).display();

  std::cout << "\nMatrix 1 * Matrix 2:\n";
  (m1 * m2).display();

  return 0;
}
