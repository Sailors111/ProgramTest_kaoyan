#include <iostream>
#include <vector>
using namespace std;


/* 6.6 矩阵与矩阵快速幂 */

// 矩阵的定义
struct Matrix {
    int row;
    int col;
    vector<vector<long long>> matrix;
    Matrix() : row(0), col(0) {
        matrix = vector<vector<long long>>(0, vector<long long>(0, 0));
    }
    Matrix(int r, int c) : row(r), col(c) {
        matrix = vector<vector<long long>>(r, vector<long long>(c, 0));
    }

    friend Matrix operator+(const Matrix& A, const Matrix& B) {
        if (A.row != B.row || A.col != B.col) {
            return Matrix();
        }
        int row = A.row, col = A.col;
        Matrix C(row, col);
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                C.matrix[i][j] = A.matrix[i][j] + B.matrix[i][j];
            }
        }
        return C;
    }

    friend Matrix operator-(const Matrix& A, const Matrix& B) {
        if (A.row != B.row || A.col != B.col) {
            return Matrix();
        }
        int row = A.row, col = A.col;
        Matrix C(row, col);
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                C.matrix[i][j] = A.matrix[i][j] - B.matrix[i][j];
            }
        }
        return C;
    }

    friend Matrix operator*(const Matrix& A, const Matrix& B) {
        if (A.col != B.row) {
            return Matrix();
        }
        int row = A.row, col = B.col, len = A.col;
        Matrix C(row, col);
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                for (int k = 0; k < len; k++) {
                    C.matrix[i][j] += A.matrix[i][k] * B.matrix[k][j];
                }
            }
        }
        return C;
    }

    Matrix operator=(const Matrix& A){
        this->row = A.row;
        this->col = A.col;
        int row = A.row, col = A.col;
        this->matrix = vector<vector<long long>>(row, vector<long long>(col, 0));
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                this->matrix[i][j] = A.matrix[i][j];
            }
        }
        return *this;
    }

    friend istream& operator>>(istream& in, Matrix& A){
        for(int i = 0; i < A.row; i++){
            for(int j = 0; j < A.col; j++){
                in >> A.matrix[i][j];
            }
        }
        return in;
    }

    friend ostream& operator<<(ostream& out, const Matrix& A){
        for(int i = 0; i < A.row; i++){
            for(int j = 0; j < A.col; j++){
                out << A.matrix[i][j] << " ";
            }
            out << endl;
        }
        return out;
    }
};


// 求单位矩阵
Matrix unitMatrix(int n){
    Matrix E(n, n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == j){
                E.matrix[i][j] = 1;
            }
        }
    }
    return E;
}

// 矩阵快速幂
Matrix matrixQuickPow(Matrix A, int k){
    if(A.row != A.col){
        return Matrix();
    }
    int len = A.row;
    Matrix res = unitMatrix(len);
    while(k != 0){
        if(k % 2 == 1){
            res = res * A;
        }
        A = A * A;
        k /= 2;
    }
    return res;
}


// 矩阵快速幂取模操作
Matrix matrixMultiply_mod(const Matrix& A, const Matrix& B, int mod) {  // 取模矩阵乘法
    if (A.col != B.row) {
        return Matrix(0, 0);
    }
    int row = A.row, col = B.col;
    Matrix C(row, col);
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            for (int k = 0; k < A.col; k++) {
                C.matrix[i][j] = (C.matrix[i][j] % mod + A.matrix[i][k] % mod * B.matrix[k][j] % mod) % mod;
            }
        }
    }
    return C;
}

Matrix matrixQuickPow_mod(Matrix A, int n, int mod) {  // 取模矩阵快速幂
    if (A.row != A.col) {
        return Matrix(0, 0);
    }
    int len = A.row;
    Matrix result = unitMatrix(len);
    while (n != 0) {
        if (n % 2 == 1) {
            result = matrixMultiply_mod(result, A, mod);
        }
        n /= 2;
        A = matrixMultiply_mod(A, A, mod);
    }
    return result;
}

