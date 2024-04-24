#include "s21_matrix_oop.h"

int main(void){
    using namespace std;

    S21Matrix obj_1{3};

    obj_1.MatrixFill();

    S21Matrix obj_2{4};

    obj_2 = obj_1.Transpose();

    cout << obj_1 << "\n" << endl;

    cout << obj_2 << "\n" << endl;

    return 0;
}   