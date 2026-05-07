#include <iostream>
#include <stdexcept>
using std::cout;

class Matrix {
private:
  int rows, cols;
  double **data;

  void allocateMemory() {
    data = new double *[rows];
    for (int i = 0; i < rows; ++i) {
      data[i] = new double[cols]{0};
    }
  }

  void freeMemory() {
    if (data) {
      for (int i = 0; i < rows; ++i) {
        delete[] data[i];
      }
      delete[] data;
    }
  }

public:
  Matrix(int r, int c) : rows(r), cols(c) {
    if (r <= 0 || c <= 0) {
      throw std::invalid_argument("Matrix dimensions must be positive.");
    }
    allocateMemory();
  }

  ~Matrix() { freeMemory(); }

  double &outBoundCheck(int r, int c) {
    if (r < 0 || r >= rows || c < 0 || c >= cols) {
      throw std::out_of_range("Matrix index out of bounds!");
    }
    return data[r][c];
  }

  Matrix operator+(const Matrix &other) {
    if (this->rows != other.rows || this->cols != other.cols) {
      throw std::logic_error("Incompatible dimensions for matrix addition.");
    }

    Matrix result(rows, cols);
    for (int i = 0; i < rows; ++i) {
      for (int j = 0; j < cols; ++j) {
        result.data[i][j] = this->data[i][j] + other.data[i][j];
      }
    }
    return result;
  }

  void display() {
    for (int i = 0; i < rows; ++i) {
      for (int j = 0; j < cols; ++j) {
        std::cout << data[i][j] << " ";
      }
      std::cout << "\n";
    }
  }
};

int main() {
  try {
    Matrix m1(2, 2);
    m1.outBoundCheck(0, 0) = 5;
    m1.outBoundCheck(0, 1) = 10;

    Matrix m2(2, 2);
    m2.outBoundCheck(0, 0) = 1;
    m2.outBoundCheck(0, 1) = 2;

    cout << "Matrix Sum:\n";
    Matrix sum = m1 + m2;
    sum.display();

    cout << "\nTesting Out of Bounds:\n";
    m1.outBoundCheck(5, 5) = 100;

  } catch (const std::out_of_range &e) {
    std::cerr << "OUT OF RANGE ERROR: " << e.what() << std::endl;
  } catch (const std::logic_error &e) {
    std::cerr << "LOGIC ERROR: " << e.what() << std::endl;
  } catch (const std::exception &e) {
    std::cerr << "GENERAL ERROR: " << e.what() << std::endl;
  }

  return 0;
}
