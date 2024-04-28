#include "matrix_oop_gtest.h"

TEST(test_suite_MatrixOperators, test_Summation) {
  {
    S21Matrix obj_1{3, 3};
    S21Matrix obj_2{3, 3};
    S21Matrix obj_3{3, 3};

    const double* fill_1{new double[]{1, 2, 3, 4, 5, 6, 7, 8, 9}};
    const double* fill_2{new double[]{2, 4, 6, 8, 10, 12, 14, 16, 18}};

    obj_1.MatrixFill(9, fill_1);
    obj_2.MatrixFill(9, fill_1);
    obj_3.MatrixFill(9, fill_2);

    obj_2 = obj_2 + obj_1;

    EXPECT_EQ(obj_2, obj_3);

    delete[] fill_1;
    delete[] fill_2;
  }

  {
    S21Matrix obj_1{3, 3};
    S21Matrix obj_2{2, 2};

    EXPECT_THROW(obj_2 = obj_2 + obj_1, std::logic_error);
  }
}

TEST(test_suite_MatrixOperators, test_Substruction) {
  {
    S21Matrix obj_1{3, 3};
    S21Matrix obj_2{3, 3};
    S21Matrix obj_3{3, 3};

    const double* fill_1{new double[]{2, 4, 6, 8, 10, 12, 14, 16, 18}};
    const double* fill_2{new double[]{1, 2, 3, 4, 5, 6, 7, 8, 9}};

    obj_1.MatrixFill(9, fill_2);
    obj_2.MatrixFill(9, fill_1);
    obj_3.MatrixFill(9, fill_2);

    obj_2 = obj_2 - obj_1;

    EXPECT_EQ(obj_2, obj_3);

    delete[] fill_1;
    delete[] fill_2;
  }

  {
    S21Matrix obj_1{3, 3};
    S21Matrix obj_2{2, 2};

    EXPECT_THROW(obj_2 = obj_2 - obj_1, std::logic_error);
  }
}

TEST(test_suite_MatrixOperators, tets_Multuplication) {
  {
    S21Matrix obj_1{3, 3};
    S21Matrix obj_2{3, 3};

    const double* fill_1{new double[]{1, 2, 3, 4, 5, 6, 7, 8, 9}};
    const double* fill_2{new double[]{2, 4, 6, 8, 10, 12, 14, 16, 18}};

    obj_1.MatrixFill(9, fill_1);
    obj_2.MatrixFill(9, fill_2);

    obj_1 = obj_1 * 2;

    EXPECT_EQ(obj_1, obj_2);

    delete[] fill_1;
    delete[] fill_2;
  }

  {
    S21Matrix obj_1{3, 3};
    S21Matrix obj_2{3, 3};
    S21Matrix obj_3{3, 3};

    const double* fill_1{new double[]{1, 2, 3, 4, 5, 6, 7, 8, 9}};
    const double* fill_2{new double[]{30, 36, 42, 66, 81, 96, 102, 126, 150}};

    obj_1.MatrixFill(9, fill_1);
    obj_2.MatrixFill(9, fill_1);
    obj_3.MatrixFill(9, fill_2);

    obj_2 = obj_2 * obj_1;

    EXPECT_EQ(obj_2, obj_3);

    delete[] fill_1;
    delete[] fill_2;
  }

  {
    S21Matrix obj_1{3, 5};
    S21Matrix obj_2{3, 5};

    EXPECT_THROW(obj_2 = obj_2 * obj_1, std::logic_error);
  }
}

TEST(test_suite_MatrixOperators, test_Equality) {
  {
    S21Matrix obj_1{3, 3};
    S21Matrix obj_2{3, 3};

    const double* fill{new double[]{1, 2, 3, 4, 5, 6, 7, 8, 9}};

    obj_1.MatrixFill(9, fill);
    obj_2.MatrixFill(9, fill);

    EXPECT_TRUE(obj_1 == obj_2);

    delete[] fill;
  }

  {
    S21Matrix obj_1{2, 2};
    S21Matrix obj_2{2, 2};

    const double* fill{new double[]{1, 2, 3, 4}};

    obj_1.MatrixFill(4, fill);

    EXPECT_FALSE(obj_1 == obj_2);

    delete[] fill;
  }

  {
    S21Matrix obj_1{3, 3};
    S21Matrix obj_2{2, 2};

    EXPECT_FALSE(obj_1 == obj_2);
  }
}

TEST(test_suite_MatrixOperators, test_Assigment) {
  {
    S21Matrix obj_1{3, 3};
    S21Matrix obj_2{3, 3};

    const double* fill{new double[]{1, 2, 3, 4, 5, 6, 7, 8, 9}};

    obj_1.MatrixFill(9, fill);

    obj_2 = obj_1;

    EXPECT_EQ(obj_1, obj_2);

    delete[] fill;
  }
}

TEST(test_suite_MatrixOperators, test_AssigmentSummation) {
  {
    S21Matrix obj_1{3, 3};
    S21Matrix obj_2{3, 3};
    S21Matrix obj_3{3, 3};

    const double* fill_1{new double[]{1, 2, 3, 4, 5, 6, 7, 8, 9}};
    const double* fill_2{new double[]{2, 4, 6, 8, 10, 12, 14, 16, 18}};

    obj_1.MatrixFill(9, fill_1);
    obj_2.MatrixFill(9, fill_1);
    obj_3.MatrixFill(9, fill_2);

    obj_2 += obj_1;

    EXPECT_EQ(obj_2, obj_3);

    delete[] fill_1;
    delete[] fill_2;
  }

  {
    S21Matrix obj_1{3, 3};
    S21Matrix obj_2{2, 2};

    EXPECT_THROW(obj_2 += obj_1, std::logic_error);
  }
}

TEST(test_suite_MatrixOperators, test_AssigmentSubstruction) {
  {
    S21Matrix obj_1{3, 3};
    S21Matrix obj_2{3, 3};
    S21Matrix obj_3{3, 3};

    const double* fill_1{new double[]{2, 4, 6, 8, 10, 12, 14, 16, 18}};
    const double* fill_2{new double[]{1, 2, 3, 4, 5, 6, 7, 8, 9}};

    obj_1.MatrixFill(9, fill_2);
    obj_2.MatrixFill(9, fill_1);
    obj_3.MatrixFill(9, fill_2);

    obj_2 -= obj_1;

    EXPECT_EQ(obj_2, obj_3);

    delete[] fill_1;
    delete[] fill_2;
  }

  {
    S21Matrix obj_1{3, 3};
    S21Matrix obj_2{2, 2};

    EXPECT_THROW(obj_2 -= obj_1, std::logic_error);
  }
}

TEST(test_suite_MatrixOperators, tets_AssigmentMultuplication) {
  {
    S21Matrix obj_1{3, 3};
    S21Matrix obj_2{3, 3};

    const double* fill_1{new double[]{1, 2, 3, 4, 5, 6, 7, 8, 9}};
    const double* fill_2{new double[]{2, 4, 6, 8, 10, 12, 14, 16, 18}};

    obj_1.MatrixFill(9, fill_1);
    obj_2.MatrixFill(9, fill_2);

    obj_1 *= 2;

    EXPECT_EQ(obj_1, obj_2);

    delete[] fill_1;
    delete[] fill_2;
  }

  {
    S21Matrix obj_1{3, 3};
    S21Matrix obj_2{3, 3};
    S21Matrix obj_3{3, 3};

    const double* fill_1{new double[]{1, 2, 3, 4, 5, 6, 7, 8, 9}};
    const double* fill_2{new double[]{30, 36, 42, 66, 81, 96, 102, 126, 150}};

    obj_1.MatrixFill(9, fill_1);
    obj_2.MatrixFill(9, fill_1);
    obj_3.MatrixFill(9, fill_2);

    obj_2 *= obj_1;

    EXPECT_EQ(obj_2, obj_3);

    delete[] fill_1;
    delete[] fill_2;
  }

  {
    S21Matrix obj_1{3, 5};
    S21Matrix obj_2{3, 5};

    EXPECT_THROW(obj_2 *= obj_1, std::logic_error);
  }
}

TEST(test_suite_MatrixOperators, tets_Indexation) {
  {
    S21Matrix obj_1{3, 3};

    const double* fill{new double[]{1, 2, 3, 4, 5, 6, 7, 8, 9}};

    obj_1.MatrixFill(9, fill);

    EXPECT_EQ(obj_1(1, 1), 5);

    delete[] fill;
  }

  {
    const S21Matrix obj_1{3, 3};

    EXPECT_EQ(obj_1(2, 2), 0);
  }

  {
    S21Matrix obj_1{3, 3};

    const double* fill{new double[]{1, 2, 3, 4, 5, 6, 7, 8, 9}};

    obj_1.MatrixFill(9, fill);

    EXPECT_THROW(obj_1(3, 3), std::out_of_range);

    delete[] fill;
  }

  {
    const S21Matrix obj_1{3, 3};

    EXPECT_THROW(obj_1(3, 3), std::out_of_range);
  }
}