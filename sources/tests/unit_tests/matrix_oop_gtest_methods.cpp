#include "matrix_oop_gtest.h"

TEST(test_MatrixMethods, EqMatrix){
    {
        #define OBJ_1_ROWS 3
        #define OBJ_1_COLS 3

        #define OBJ_2_ROWS 3
        #define OBJ_2_COLS 3

        #define FILL_SIZE 9

        S21Matrix obj_1{OBJ_1_ROWS, OBJ_1_ROWS};
        S21Matrix obj_2{OBJ_2_ROWS, OBJ_2_ROWS};

        const double* fill{new double[]{1, 2, 3, 4, 5, 6, 7, 8, 9}};

        obj_1.MatrixFill(FILL_SIZE, fill);
        obj_2.MatrixFill(FILL_SIZE, fill);
        
        EXPECT_EQ(obj_1, obj_2);
    }

    {
        #define OBJ_1_ROWS 2
        #define OBJ_1_COLS 2

        #define OBJ_2_ROWS 2
        #define OBJ_2_COLS 2

        #define FILL_SIZE 4

        S21Matrix obj_1{OBJ_1_ROWS, OBJ_1_ROWS};
        S21Matrix obj_2{OBJ_2_ROWS, OBJ_2_ROWS};

        const double* fill{new double[]{1, 2, 3, 4}};

        obj_1.MatrixFill(FILL_SIZE, fill);
        obj_2.MatrixFill(FILL_SIZE, fill);
        
        EXPECT_EQ(obj_1, obj_2);
    }

    {
        #define OBJ_1_ROWS 3
        #define OBJ_1_COLS 3

        #define OBJ_2_ROWS 3
        #define OBJ_2_COLS 3

        #define FILL_SIZE 4

        S21Matrix obj_1{OBJ_1_ROWS, OBJ_1_ROWS};
        S21Matrix obj_2{OBJ_2_ROWS, OBJ_2_ROWS};

        const double* fill{new double[]{1, 2, 3, 4, 5}};

        obj_1.MatrixFill(FILL_SIZE, fill);
        obj_2.MatrixFill(FILL_SIZE, fill);
        
        EXPECT_EQ(obj_1, obj_2);
    }
}