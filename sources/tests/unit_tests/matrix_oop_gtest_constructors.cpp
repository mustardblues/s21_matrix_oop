#include "matrix_oop_gtest.h"

TEST(test_suite_MatrixConstructors, test_Constructor) {
  {
    S21Matrix obj_1{};

    EXPECT_EQ(obj_1.GetRows(), DEFAULT_MATRIX_ORDER);
    EXPECT_EQ(obj_1.GetCols(), DEFAULT_MATRIX_ORDER);
  }
}

TEST(test_suite_MatrixConstructors, test_MoveConstructor) {
  {
    S21Matrix obj_1{3, 3};
    S21Matrix obj_2{3, 3};

    const double* fill{new double[]{1, 2, 3, 4, 5, 6, 7, 8, 9}};

    obj_1.MatrixFill(9, fill);
    obj_2.MatrixFill(9, fill);

    S21Matrix obj_3{std::move(obj_1)};

    EXPECT_EQ(obj_2, obj_3);
    EXPECT_EQ(obj_1.GetRows(), 0);
    EXPECT_EQ(obj_1.GetCols(), 0);
  }
}