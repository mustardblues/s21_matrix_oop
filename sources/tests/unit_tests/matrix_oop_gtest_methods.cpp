#include "matrix_oop_gtest.h"

TEST(test_suite_MatrixMethods, test_EqMatrix) {
  {
    S21Matrix obj_1{3, 3};
    S21Matrix obj_2{3, 3};

    const double* fill{new double[]{1, 2, 3, 4, 5, 6, 7, 8, 9}};

    obj_1.MatrixFill(9, fill);
    obj_2.MatrixFill(9, fill);

    EXPECT_EQ(obj_1, obj_2);
  }

  {
    S21Matrix obj_1{2, 2};
    S21Matrix obj_2{2, 2};

    const double* fill{new double[]{1, 2, 3, 4}};

    obj_1.MatrixFill(4, fill);

    EXPECT_FALSE(obj_1.EqMatrix(obj_2));
  }

  {
    S21Matrix obj_1{3, 3};
    S21Matrix obj_2{2, 2};

    EXPECT_FALSE(obj_1.EqMatrix(obj_2));
  }
}

TEST(test_suite_MatrixMethods, test_SumMatrix) {
  {
    S21Matrix obj_1{3, 3};
    S21Matrix obj_2{3, 3};
    S21Matrix obj_3{3, 3};

    const double* fill_1{new double[]{1, 2, 3, 4, 5, 6, 7, 8, 9}};
    const double* fill_2{new double[]{2, 4, 6, 8, 10, 12, 14, 16, 18}};

    obj_1.MatrixFill(9, fill_1);
    obj_2.MatrixFill(9, fill_1);
    obj_3.MatrixFill(9, fill_2);

    obj_2.SumMatrix(obj_1);

    EXPECT_EQ(obj_2, obj_3);
  }

  {
    S21Matrix obj_1{3, 3};
    S21Matrix obj_2{2, 2};

    EXPECT_THROW(obj_2.SumMatrix(obj_1), std::logic_error);
  }
}

TEST(test_suite_MatrixMethods, test_SubMatrix) {
  {
    S21Matrix obj_1{3, 3};
    S21Matrix obj_2{3, 3};
    S21Matrix obj_3{3, 3};

    const double* fill_1{new double[]{2, 4, 6, 8, 10, 12, 14, 16, 18}};
    const double* fill_2{new double[]{1, 2, 3, 4, 5, 6, 7, 8, 9}};

    obj_1.MatrixFill(9, fill_2);
    obj_2.MatrixFill(9, fill_1);
    obj_3.MatrixFill(9, fill_2);

    obj_2.SubMatrix(obj_1);

    EXPECT_EQ(obj_2, obj_3);
  }

  {
    S21Matrix obj_1{3, 3};
    S21Matrix obj_2{2, 2};

    EXPECT_THROW(obj_2.SubMatrix(obj_1), std::logic_error);
  }
}

TEST(test_suite_MatrixMethods, tets_MulNumber) {
  {
    S21Matrix obj_1{3, 3};
    S21Matrix obj_2{3, 3};

    const double* fill_1{new double[]{1, 2, 3, 4, 5, 6, 7, 8, 9}};
    const double* fill_2{new double[]{2, 4, 6, 8, 10, 12, 14, 16, 18}};

    obj_1.MatrixFill(9, fill_1);
    obj_2.MatrixFill(9, fill_2);

    obj_1.MulNumber(2);

    EXPECT_EQ(obj_1, obj_2);
  }
}

TEST(test_suite_MatrixMethods, test_MulMatrix) {
  {
    S21Matrix obj_1{3, 3};
    S21Matrix obj_2{3, 3};
    S21Matrix obj_3{3, 3};

    const double* fill_1{new double[]{1, 2, 3, 4, 5, 6, 7, 8, 9}};
    const double* fill_2{new double[]{30, 36, 42, 66, 81, 96, 102, 126, 150}};

    obj_1.MatrixFill(9, fill_1);
    obj_2.MatrixFill(9, fill_1);
    obj_3.MatrixFill(9, fill_2);

    obj_2.MulMatrix(obj_1);

    EXPECT_EQ(obj_2, obj_3);
  }

  {
    S21Matrix obj_1{3, 5};
    S21Matrix obj_2{3, 5};

    EXPECT_THROW(obj_2.MulMatrix(obj_1), std::logic_error);
  }
}

TEST(test_suite_MatrixMethods, test_Transpose) {
  {
    S21Matrix obj_1{3, 3};
    S21Matrix obj_3{3, 3};

    const double* fill_1{new double[]{1, 2, 3, 4, 5, 6, 7, 8, 9}};
    const double* fill_2{new double[]{1, 4, 7, 2, 5, 8, 3, 6, 9}};

    obj_1.MatrixFill(9, fill_1);
    obj_3.MatrixFill(9, fill_2);

    S21Matrix obj_2{obj_1.Transpose()};

    EXPECT_EQ(obj_2, obj_3);
  }
}

TEST(test_suite_MatrixMethods, test_CalcComplements) {
  {
    S21Matrix obj_1{3, 3};
    S21Matrix obj_2{3, 3};

    const double* fill_1{new double[]{1, 4, 4, 2, 0, 8, 8, 8, 9}};
    const double* fill_2{new double[]{-64, 46, 16, -4, -23, 24, 32, 0, -8}};

    obj_1.MatrixFill(9, fill_1);
    obj_2.MatrixFill(9, fill_2);

    EXPECT_EQ(obj_1.CalcComplements(), obj_2);
  }

  {
    S21Matrix obj_1{2, 5};

    EXPECT_THROW(obj_1.CalcComplements(), std::logic_error);
  }
}

TEST(test_suite_MatrixMethods, test_Determinant) {
  {
    S21Matrix obj_1{3, 3};

    const double* fill{new double[]{1, 4, 4, 2, 0, 8, 8, 8, 9}};

    obj_1.MatrixFill(9, fill);

    EXPECT_EQ(obj_1.Determinant(), 184);
  }

  {
    S21Matrix obj_1{3, 5};

    EXPECT_THROW(obj_1.Determinant(), std::logic_error);
  }
}

TEST(test_suite_MatrixMethods, test_InverseMatrix) {
  {
    S21Matrix obj_1{3, 3};
    S21Matrix obj_2{3, 3};

    const double* fill_1{new double[]{1, 4, 4, 2, 0, 8, 8, 8, 9}};
    const double* fill_2{new double[9]{-0.3478260, -0.0217391, 0.1739130, 0.25,
                                       -0.125, 0, 0.0869565, 0.1304347,
                                       -0.0434782}};

    obj_1.MatrixFill(9, fill_1);
    obj_2.MatrixFill(9, fill_2);

    EXPECT_EQ(obj_1.InverseMatrix(), obj_2);
  }

  {
    S21Matrix obj_1{2, 7};

    EXPECT_THROW(obj_1.InverseMatrix(), std::logic_error);
  }
}

TEST(test_suite_MatrixMethods, test_OrderAccessor) {
  {
    const S21Matrix obj_1{3, 3};

    EXPECT_EQ(obj_1.GetRows(), 3);
    EXPECT_EQ(obj_1.GetCols(), 3);
  }
}

TEST(test_suite_MatrixMethods, test_OrderMutator) {
  {
    S21Matrix obj_1{3, 3};
    S21Matrix obj_2{10, 3};

    obj_1.SetRows(10);

    EXPECT_EQ(obj_1, obj_2);
  }

  {
    S21Matrix obj_1{3, 3};
    S21Matrix obj_2{3, 10};

    obj_1.SetCols(10);

    EXPECT_EQ(obj_1, obj_2);
  }
}