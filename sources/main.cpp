#include "s21_matrix_oop.h"

int main(void){
    S21Matrix obj_1{3, 3};
    S21Matrix obj_2{3, 3};

    const double* fill{new double[]{1, 2, 3, 4, 5, 6, 7, 8, 9}};

    obj_1.MatrixFill(9, fill);
    // obj_2.MatrixFill(9, fill);

    return 0;
}