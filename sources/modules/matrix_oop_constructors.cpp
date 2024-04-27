#include "./../s21_matrix_oop.h"

S21Matrix::S21Matrix(int order) : S21Matrix(order, order) {}

S21Matrix::S21Matrix(int rows, int cols) {
  bool is_correct_order{rows > 0 && cols > 0};

  if (!is_correct_order) {
    throw std::logic_error(
        "Incorrect matrix order in S21Matrix class constructor.");
  }

  this->MatrixCreate(rows, cols);
}

S21Matrix::S21Matrix(const S21Matrix& other){
  this->MatrixCopy(other);
}

S21Matrix::S21Matrix(S21Matrix&& other) noexcept {
  rows_ = other.rows_;
  cols_ = other.cols_;

  matrix_ = other.matrix_;

  other.rows_ = 0;
  other.cols_ = 0;

  other.matrix_ = nullptr;
}

S21Matrix::S21Matrix() : S21Matrix(DEFAULT_MATRIX_ORDER) {}

S21Matrix::~S21Matrix() { this->MatrixDelete(); }