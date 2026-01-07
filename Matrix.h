#pragma once
#include <iostream>
#include <initializer_list>

template<typename T, size_t Rows, size_t Cols>
class Matrix{
private:
    T data[Rows * Cols];

public:
    // Constructor default
    Matrix() {
        for(size_t i=0; i<Rows*Cols; i++) {
            data[i] = T{};
        }
    }

    // Constructor din listă de inițializare
    Matrix(std::initializer_list<T> list) { 
        // In main.cpp avem Matrix<int,2,2> A{1,2,3};
        // list = {1,2,3}, initializer_list = asa se numeste, T=tipul valorilor, list = un nume
        size_t i = 0;
        for(auto value : list) {
            if(i < Rows*Cols) {
                data[i++] = value;
            }
        }
    }

    // Copy constructor
    Matrix(const Matrix& other) {
        for(size_t i=0; i<Rows*Cols; i++) {
            data[i] = other.data[i];
        }
    }

    // ---- Operator '()' ----
    T& operator()(size_t row, size_t col) { return data[row*Cols+col]; };
    const T& operator()(size_t row, size_t col) const { return data[row*Cols+col]; };

    // ---- Operator '+' ----
    Matrix operator+(const Matrix& other) const {
        Matrix<T, Rows, Cols> result;
        for(size_t i=0; i<Rows*Cols; i++) {
            result.data[i] = data[i] + other.data[i];
            // result.data[i] = C.matrix
            // data[i] = A.matrix
            // other.data[i] = B.matrix
        }
        return result;
    }

    // ---- Operator '-' ----
    Matrix operator-(const Matrix& other) const {
        Matrix<T, Rows, Cols> result;
        for(size_t i=0; i<Rows*Cols; i++) {
            result.data[i] = data[i] - other.data[i];
        }
        return result;
    }

    // ---- Operator '*' -----
    template<size_t OtherCols>
    Matrix<T, Rows, OtherCols> operator*(const Matrix<T, Cols, OtherCols>& other) const {
        Matrix<T, Rows, OtherCols> result;
        for(size_t i=0; i<Rows; i++) 
            for(size_t j=0; j<OtherCols; j++) 
                for(size_t k=0; k<Cols; k++) 
                    result(i,j) += (*this)(i,k) * other(k,j);
        return result;
    }

    // ---- functia transpose() ----
    Matrix<T, Cols, Rows> transpose() const {
        Matrix<T, Cols, Rows> result;
        for(size_t i=0; i<Rows; i++) 
            for(size_t j=0; j<Cols; j++) 
                result(j, i) = (*this)(i, j);
        return result;
    }

    // ---- functia determinant - doar pt (2x2) ----
    T determinant() const {
        static_assert(Rows == Cols, "Determinant doar pentru matrice patratica!");
        static_assert(Rows == 2, "Determinant implementat doar pentru 2x2!");
        T a = (*this)(0, 0); T b = (*this)(0, 1);
        T c = (*this)(1, 0); T d = (*this)(1, 1);
        return a*d - b*c;
    }

    // ---- functia inversa() ----
    Matrix<T, Rows, Cols> inversa() const {
        static_assert(Rows == Cols, "Inversa doar pentru matrice patratice");
        static_assert(Rows == 2, "Inversa implementata doar pentru 2x2");

        T det = determinant();
        if (det == T{})
            throw std::runtime_error("Matrice singulara - nu are inversa!");
        
        Matrix<T, Rows, Cols> result;

        T a = (*this)(0, 0); T b = (*this)(0, 1);
        T c = (*this)(1, 0); T d = (*this)(1, 1);

        result(0, 0) = d/det; result(0, 1) = -b/det;
        result(1, 0) = -c/det; result(1, 1) = a/det;

        return result;
    }

    // ---- operatorul '<<' ----
    friend std::ostream& operator<<(std::ostream& os, const Matrix& m) {
        for (size_t i = 0; i < Rows; i++) {
            for (size_t j = 0; j < Cols; j++) {
                os << m(i, j) << " ";
            }
            os << "\n";
        }
        return os;
    }
};