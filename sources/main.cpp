#include "s21_matrix_oop.h"

int main(void){
    using namespace std;

    S21Matrix obj_1{3};

    obj_1.MatrixFill();

    S21Matrix obj_2{3};

    obj_2 += obj_1;

    obj_2 += obj_1;

    cout << obj_1 << endl;

    cout << obj_2 << endl;

    cout << obj_2(0, 0) << endl;

    return 0;
}   