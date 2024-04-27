#include "./../s21_matrix_oop.h"

S21Matrix S21Matrix::operator+(const S21Matrix& other) {
  S21Matrix mod_matrix{*this};
  mod_matrix.SumMatrix(other);

  return mod_matrix;
}

S21Matrix S21Matrix::operator-(const S21Matrix& other) {
  S21Matrix mod_matrix{*this};
  mod_matrix.SubMatrix(other);

  return mod_matrix;
}

S21Matrix S21Matrix::operator*(const S21Matrix& other) {
  S21Matrix mod_matrix{*this};
  mod_matrix.MulMatrix(other);

  return mod_matrix;
}

S21Matrix S21Matrix::operator*(const double num) {
  S21Matrix mod_matrix{*this};
  mod_matrix.MulNumber(num);

  return mod_matrix;
}

bool S21Matrix::operator==(const S21Matrix& other) const noexcept {
  return this->EqMatrix(other);
}

S21Matrix& S21Matrix::operator=(const S21Matrix& other) {
  if (this != &other) {
    this->MatrixCopy(other);
  }

  return *this;
}

S21Matrix& S21Matrix::operator=(S21Matrix&& other) {
  std::swap(rows_, other.rows_);
  std::swap(cols_, other.cols_);
  std::swap(matrix_, other.matrix_);

  return *this;
}

S21Matrix& S21Matrix::operator+=(const S21Matrix& other) {
  this->SumMatrix(other);
  return *this;
}

S21Matrix& S21Matrix::operator-=(const S21Matrix& other) {
  this->SubMatrix(other);
  return *this;
}

S21Matrix& S21Matrix::operator*=(const S21Matrix& other) {
  this->MulMatrix(other);
  return *this;
}

S21Matrix& S21Matrix::operator*=(const double num) {
  this->MulNumber(num);
  return *this;
}

const double& S21Matrix::operator()(int row, int column) const {
  bool is_correct_index{(row >= 0 && column >= 0) &&
                        (row < rows_ && column < cols_)};

  if (!is_correct_index) {
    throw std::out_of_range(
        "Incorrect index in S21Matrix:operator() operator.");
  }

  return this->matrix_[row][column];
}

double& S21Matrix::operator()(int row, int column) {
  bool is_correct_index{(row >= 0 && column >= 0) &&
                        (row < rows_ && column < cols_)};

  if (!is_correct_index) {
    throw std::out_of_range(
        "Incorrect index in S21Matrix:operator() operator.");
  }

  return this->matrix_[row][column];
}