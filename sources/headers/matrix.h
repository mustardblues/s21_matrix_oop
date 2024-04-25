#ifndef _MATRIX_H_
#define _MATRIX_H_

class S21Matrix {
  friend std::ostream& operator<<(std::ostream& stream,
                                  const S21Matrix& object);

 private:
  int rows_{0}, cols_{0};
  double** matrix{nullptr};

  void MatrixCopy(const S21Matrix& other);
  void MatrixDelete();

  bool is_TriangleMatrix();
  void TriangleMatrix();
  void MatrixSwap(int swappable, int swapper);

  void MatrixSplit(int row, int column, S21Matrix& other);

 public:
  S21Matrix();
  S21Matrix(int rows, int cols);
  S21Matrix(const S21Matrix& other);
  S21Matrix(S21Matrix&& other) noexcept;
  S21Matrix(int order);
  ~S21Matrix();

  int GetRows() const;
  int GetCols() const;

  void SetRows(int rows);
  void SetCols(int cols);

  S21Matrix Transpose() noexcept;
  S21Matrix CalcComplements();
  S21Matrix InverseMatrix();

  bool EqMatrix(const S21Matrix& other) const;
  double Determinant();

  void SumMatrix(const S21Matrix& other);
  void SubMatrix(const S21Matrix& other);
  void MulNumber(const double num) noexcept;
  void MulMatrix(const S21Matrix& other);

  S21Matrix operator+(const S21Matrix& other);
  S21Matrix operator-(const S21Matrix& other);
  S21Matrix operator*(const S21Matrix& other);
  S21Matrix operator*(const double num);
  bool operator==(const S21Matrix& other) const noexcept;
  S21Matrix& operator=(const S21Matrix& other);
  S21Matrix& operator=(S21Matrix&& other);
  S21Matrix& operator+=(const S21Matrix& other);
  S21Matrix& operator-=(const S21Matrix& other);
  S21Matrix& operator*=(const S21Matrix& other);
  S21Matrix& operator*=(const double num);
  double& operator()(int row, int column);
  const double& operator()(int row, int column) const;

  bool MatrixFill(const int index_count, const double* fill)
};

#endif  // _MATRIX_H_
