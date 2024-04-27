#include "./../s21_matrix_oop.h"

int S21Matrix::GetRows() const { return rows_; }

int S21Matrix::GetCols() const { return cols_; }

void S21Matrix::SetRows(int rows) {
  bool is_not_equal_rows{rows != rows_};

  if (is_not_equal_rows) {
    S21Matrix mod_matrix{rows, cols_};

    int smallest_rows = std::min(rows, rows_);

    for (int i = 0; i < smallest_rows; ++i) {
      for (int j = 0; j < cols_; ++j) {
        mod_matrix.matrix_[i][j] = matrix_[i][j];
      }
    }

    *this = std::move(mod_matrix);
  }
}

void S21Matrix::SetCols(int cols) {
  bool is_not_equal_cols{cols != cols_};

  if (is_not_equal_cols) {
    S21Matrix mod_matrix{rows_, cols};

    int smallest_cols = std::min(cols, cols_);

    for (int i = 0; i < rows_; ++i) {
      for (int j = 0; j < smallest_cols; ++j) {
        mod_matrix.matrix_[i][j] = matrix_[i][j];
      }
    }

    *this = std::move(mod_matrix);
  }
}

bool S21Matrix::EqMatrix(const S21Matrix& other) const {
  bool output_code{rows_ == other.rows_ && cols_ == other.cols_};

  if (!output_code) {
    return false;
  }

  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      if (std::fabs(matrix_[i][j] - other.matrix_[i][j]) > EPS) {
        i = rows_;
        j = cols_;

        output_code = false;
      }
    }
  }

  return output_code;
}

void S21Matrix::SumMatrix(const S21Matrix& other) {
  bool is_correct_order{rows_ == other.rows_ && cols_ == other.cols_};

  if (!is_correct_order) {
    throw std::logic_error(
        "Incorrect matrix order in S21Matrix::SumMatrix() function.");
  }

  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      matrix_[i][j] += other.matrix_[i][j];
    }
  }
}

void S21Matrix::SubMatrix(const S21Matrix& other) {
  bool is_correct_order{rows_ == other.rows_ && cols_ == other.cols_};

  if (!is_correct_order) {
    throw std::logic_error(
        "Incorrect matrix order in S21Matrix::SubMatrix() function.");
  }

  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      matrix_[i][j] -= other.matrix_[i][j];
    }
  }
}

void S21Matrix::MulNumber(const double num) noexcept {
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      matrix_[i][j] *= num;
    }
  }
}

void S21Matrix::MulMatrix(const S21Matrix& other) {
  bool is_correct_order{cols_ == other.rows_};

  if (!is_correct_order) {
    throw std::logic_error(
        "Incorrect matrix order in S21Matrix::MulMatrix() function.");
  }

  S21Matrix mod_matrix{rows_, other.cols_};

  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < other.cols_; ++j) {
      for (int k = 0; k < other.rows_; ++k) {
        mod_matrix.matrix_[i][j] += matrix_[i][k] * other.matrix_[k][j];
      }
    }
  }

  *this = std::move(mod_matrix);
}

S21Matrix S21Matrix::Transpose() noexcept {
  S21Matrix mod_matrix{cols_, rows_};

  for (int i = 0; i < mod_matrix.rows_; ++i) {
    for (int j = 0; j < mod_matrix.cols_; ++j) {
      mod_matrix.matrix_[i][j] = matrix_[j][i];
    }
  }

  return mod_matrix;
}

double S21Matrix::Determinant() {
  bool is_correct_order{rows_ == cols_};

  if (!is_correct_order) {
    throw std::logic_error(
        "Incorrect matrix order in S21Matrix::Determinant() function.");
  }

  S21Matrix temp{*this};

  double determinant = 0;
  bool is_triangle_matrix{temp.is_TriangleMatrix()};

  while (is_triangle_matrix != true) {
    temp.TriangleMatrix();

    is_triangle_matrix = temp.is_TriangleMatrix();
  }

  determinant = 1;

  for (int i = 0; i < temp.rows_; ++i) {
    determinant *= temp.matrix_[i][i];
  }

  return determinant;
}

bool S21Matrix::is_TriangleMatrix() {
  bool output_code = true;

  for (int i = 0; i < cols_; ++i) {
    for (int j = i + 1; j < rows_; ++j) {
      if (std::fabs(matrix_[j][i]) > EPS) {
        i = cols_;
        j = rows_;

        output_code = false;
      }
    }
  }

  return output_code;
}

void S21Matrix::TriangleMatrix() {
  int max_row = 0, swap_count = 0;

  double value = 0;

  for (int i = 0; i < rows_; ++i) {
    max_row = i;

    for (int j = i + 1; j < rows_; ++j) {
      if (std::fabs(matrix_[j][i]) > std::fabs(matrix_[max_row][i])) {
        max_row = j;
      }
    }

    if (fabs(matrix_[max_row][i]) > EPS) {
      if (max_row != i) {
        this->MatrixSwap(i, max_row);

        ++swap_count;
      }

      for (int j = i + 1; j < rows_; ++j) {
        value = matrix_[j][i] / matrix_[i][i];

        for (int k = 0; k < cols_; ++k) {
          matrix_[j][k] -= value * matrix_[i][k];
        }
      }
    }
  }

  matrix_[0][0] *= std::pow(-1, swap_count);  // the first element is not 0.
}

void S21Matrix::MatrixSwap(int swappable, int swapper) {
  for (int i = 0; i < cols_; ++i) {
    std::swap(matrix_[swappable][i], matrix_[swapper][i]);
  }
}

S21Matrix S21Matrix::CalcComplements() {
  bool is_correct_order{rows_ == cols_};

  if (!is_correct_order) {
    throw std::logic_error(
        "Incorrect matrix order in S21Matrix::Determinant() function.");
  }

  S21Matrix mod_matrix{rows_, cols_};
  S21Matrix temp{rows_ - 1, cols_ - 1};

  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      this->MatrixSplit(i, j, temp);

      mod_matrix.matrix_[i][j] = temp.Determinant() * std::pow(-1, i + j);
    }
  }

  return mod_matrix;
}

void S21Matrix::MatrixSplit(int row, int column, S21Matrix& other) {
  for (int i = 0; i < rows_; ++i) {
    if (i < row) {
      for (int j = 0; j < column; ++j) {
        other.matrix_[i][j] = matrix_[i][j];
      }

      for (int j = column + 1; j < cols_; ++j) {
        other.matrix_[i][j - 1] = matrix_[i][j];
      }
    } else if (i > row) {
      for (int j = 0; j < column; ++j) {
        other.matrix_[i - 1][j] = matrix_[i][j];
      }

      for (int j = column + 1; j < cols_; ++j) {
        other.matrix_[i - 1][j - 1] = matrix_[i][j];
      }
    }
  }
}

S21Matrix S21Matrix::InverseMatrix() {
  bool is_correct_order{rows_ == cols_};

  if (!is_correct_order) {
    throw std::logic_error(
        "Incorrect matrix order in S21Matrix:InverseMatrix() function.");
  }

  double determinant = this->Determinant();

  if (std::fabs(determinant) < EPS) {
    throw std::logic_error(
        "Determinant matrix = 0 in S21Matrix:InverseMatrix() function.");
  }

  S21Matrix mod_matrix{*this};

  mod_matrix = mod_matrix.Transpose().CalcComplements();

  mod_matrix.MulNumber(1 / determinant);

  return mod_matrix;
}

void S21Matrix::MatrixCreate(int rows, int cols) {
  rows_ = rows;
  cols_ = cols;

  matrix_ = new double* [rows_] {};

  for (int i = 0; i < rows_; ++i) {
    matrix_[i] = new double[cols]{};
  }
}

void S21Matrix::MatrixCopy(const S21Matrix& other) {
  this->MatrixDelete();
  this->MatrixCreate(other.rows_, other.cols_);

  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      matrix_[i][j] = other.matrix_[i][j];
    }
  }
}

void S21Matrix::MatrixDelete() {
  bool is_not_null{matrix_ != nullptr};

  if (is_not_null) {
    for (int i = 0; i < rows_; ++i) {
      delete[] matrix_[i];
    }

    delete[] matrix_;

    rows_ = cols_ = 0;

    matrix_ = nullptr;
  }
}

bool S21Matrix::MatrixFill(const int index_count, const double* fill) {
  bool is_correct_index_count{index_count == (rows_ * cols_)};

  if (!is_correct_index_count) {
    return false;
  }

  int index = 0;

  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      matrix_[i][j] = fill[index++];
    }
  }

  return true;
}