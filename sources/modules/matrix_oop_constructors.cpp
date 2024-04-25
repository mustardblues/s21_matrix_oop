#include "./../s21_matrix_oop.h"

S21Matrix::S21Matrix(int order) : S21Matrix(order, order) {}

S21Matrix::S21Matrix(int rows, int cols) {
  bool is_correct_order{rows > 0 && cols > 0};

  if (!is_correct_order) {
    throw std::logic_error(
        "Incorrect matrix order in S21Matrix class constructor.");
  }

  rows_ = rows;
  cols_ = cols;

  matrix = new double* [rows_] {};

  for (int i = 0; i < rows_; ++i) {
    matrix[i] = new double[cols_]{};
  }
}

S21Matrix::S21Matrix(const S21Matrix& other)
    : S21Matrix(other.rows_, other.cols_) {
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      matrix[i][j] = other.matrix[i][j];
    }
  }
}

S21Matrix::S21Matrix(S21Matrix&& other) noexcept {
  rows_ = other.rows_;
  cols_ = other.cols_;

  matrix = other.matrix;

  other.rows_ = 0;
  other.cols_ = 0;

  other.matrix = nullptr;
}

S21Matrix::S21Matrix() : S21Matrix(DEFAULT_MATRIX_ORDER) {}

S21Matrix::~S21Matrix() { this->MatrixDelete(); }