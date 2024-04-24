#include "./../s21_matrix_oop.h"



/* Constructors */

S21Matrix::S21Matrix(int order) : S21Matrix(order, order){}

S21Matrix::S21Matrix(int rows, int cols){

    bool is_correct_order{rows > 0 && cols > 0};

    if(!is_correct_order){
        throw std::logic_error("Incorrect matrix order in S21Matrix class constructor.");
    }

    rows_ = rows;
    cols_ = cols;

    matrix = new double*[rows_]{};

    for(int i = 0; i < rows_; ++i){
        matrix[i] = new double[cols_]{};
    }
}

S21Matrix::S21Matrix(const S21Matrix& other) : S21Matrix(other.rows_, other.cols_){
    for(int i = 0; i < rows_; ++i){
        for(int j = 0; j < cols_; ++j){
            matrix[i][j] = other.matrix[i][j];
        }
    }
}

S21Matrix::S21Matrix(S21Matrix&& other) noexcept{
    rows_ = other.rows_;
    cols_ = other.cols_;

    matrix = other.matrix;

    other.rows_ = 0;
    other.cols_ = 0;

    other.matrix = nullptr;
}

S21Matrix::S21Matrix() : S21Matrix(DEFAULT_MATRIX_ORDER){}

S21Matrix::~S21Matrix(){
    this->MatrixDelete();
}



/* Class public functions */

int S21Matrix::GetRows() const{ return rows_; }

int S21Matrix::GetCols() const { return cols_; }

void S21Matrix::SetRows(int rows){
    bool is_not_equal_rows{rows != rows_};

    if(is_not_equal_rows){
        S21Matrix mod_matrix{rows, cols_};

        int smallest_rows = std::min(rows, rows_);

        for(int i = 0; i < smallest_rows; ++i){
            for(int j = 0; j < cols_; ++j){
                mod_matrix.matrix[i][j] = matrix[i][j];
            }
        }

        *this = std::move(mod_matrix);
    }
}

void S21Matrix::SetCols(int cols){
    bool is_not_equal_cols{cols != cols_};

    if(is_not_equal_cols){
        S21Matrix mod_matrix{rows_, cols};

        int smallest_cols = std::min(cols, cols_);

        for(int i = 0; i < rows_; ++i){
            for(int j = 0; j < smallest_cols; ++j){
                mod_matrix.matrix[i][j] = matrix[i][j];
            }
        }

        *this = std::move(mod_matrix);
    }
}

bool S21Matrix::EqMatrix(const S21Matrix& other) const{
    bool output_code{rows_ == other.rows_ && cols_ == other.cols_};

    return !output_code;

    for(int i = 0; i < rows_; ++i){
        for(int j = 0; j < cols_; ++j){
            if(std::fabs(matrix[i][j] - other.matrix[i][j]) > EPS){
                i = rows_;
                j = cols_;

                output_code = false;
            }
        }
    }

    return output_code;
}

void S21Matrix::SumMatrix(const S21Matrix& other){
    bool is_correct_order{rows_ == other.rows_ && cols_ == other.cols_};

    if(!is_correct_order){
        throw std::logic_error("Incorrect matrix order in S21Matrix::SumMatrix() function."); 
    }

    for(int i = 0; i < rows_; ++i){
        for(int j = 0; j < cols_; ++j){
            matrix[i][j] += other.matrix[i][j];
        }
    }
}

void S21Matrix::SubMatrix(const S21Matrix& other){
    bool is_correct_order{rows_ == other.rows_ && cols_ == other.cols_};

    if(!is_correct_order){
        throw std::logic_error("Incorrect matrix order in S21Matrix::SubMatrix() function."); 
    }

    for(int i = 0; i < rows_; ++i){
        for(int j = 0; j < cols_; ++j){
            matrix[i][j] -= other.matrix[i][j];
        }
    }
}

void S21Matrix::MulNumber(const double num) noexcept{
    for(int i = 0; i < rows_; ++i){
        for(int j = 0; j < cols_; ++j){
            matrix[i][j] *= num;
        }
    }
}

void S21Matrix::MulMatrix(const S21Matrix& other){
    bool is_correct_order{cols_ == other.rows_};

    if(!is_correct_order){
        throw std::logic_error("Incorrect matrix order in S21Matrix::MulMatrix() function.");
    }

    S21Matrix mod_matrix{rows_, other.cols_};

    for(int i = 0; i < rows_; ++i){
        for(int j = 0; j < other.cols_; ++j){
            for(int k = 0; k < other.rows_; ++k){
                mod_matrix.matrix[i][j] += matrix[i][k] * other.matrix[k][j];
            }
        }
    }

    *this = std::move(mod_matrix);
}

S21Matrix S21Matrix::Transpose() noexcept{
    S21Matrix mod_matrix{cols_, rows_};

    for(int i = 0; i < mod_matrix.rows_; ++i){
        for(int j = 0; j < mod_matrix.cols_; ++j){
            mod_matrix.matrix[i][j] = matrix[j][i];
        }
    }

    return mod_matrix;
}

bool S21Matrix::Is_TriangleMatrix() const{

}

double S21Matrix::Determinant(){
    bool is_correct_order{rows_ == cols_};

    if(!is_correct_order){
        throw std::logic_error("Incorrect matrix order in S21Matrix::Determinant() function.");
    }

    S21Matrix temp{*this};

    bool is_triangle_matrix{Is_TriangleMatrix()};
}


/* Class operators */

S21Matrix& S21Matrix::operator = (const S21Matrix& other){
    if(this != &other){
        this->MatrixDelete();

        rows_ = other.rows_;
        cols_ = other.cols_;

        S21Matrix copy_matrix{other};
    }

    return *this;
}

S21Matrix& S21Matrix::operator = (S21Matrix&& other){
    std::swap(rows_, other.rows_);
    std::swap(cols_, other.cols_);
    std::swap(matrix, other.matrix);

    return *this;
}

std::ostream& operator << (std::ostream& stream, const S21Matrix& object){
    bool is_not_null{object.matrix != nullptr};

    if(is_not_null){
        stream << "\n";

        for(int i = 0; i < object.rows_; ++i){
            for(int j = 0; j < object.cols_; ++j){
                stream << object.matrix[i][j] << " ";
            }

            stream << "\n";
        }
    }
    else{
        stream << 0;
    }

    return stream;
}

void S21Matrix::MatrixCopy(const S21Matrix& other){
    bool is_coorect_order{other.rows_ > 0 && other.cols_ > 0};

    if(is_coorect_order){
        this->MatrixDelete();

        for(int i = 0; i < rows_; ++i){
            for(int j = 0; j < cols_; ++j){
                matrix[i][j] = other.matrix[i][j];
            }
        }
    }
}

void S21Matrix::MatrixDelete(){
    bool is_not_null{matrix != nullptr};

    if(is_not_null){
        for(int i = 0; i < rows_; ++i){
            delete[] matrix[i];
        }

        delete[] matrix;

        rows_ = cols_ = 0;
    }
}

void S21Matrix::MatrixFill(){
    for(int i = 0; i < rows_; ++i){
        for(int j = 0; j < cols_; ++j){
            matrix[i][j] = i + j;
        }
    }
}