#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <iostream>
#include <vector>

using namespace std;

class Matrix {
private:
    vector<vector<double>> m_data;
    size_t m_rows;
    size_t m_cols;

public:
    // Constructor
    Matrix(const std::vector<std::vector<double>>& d);

    // Accessors
    size_t numRows() const;
    size_t numCols() const;

    // Element access
    const double& at(size_t r, size_t c) const;

    // Arithmetic operations
    Matrix operator+(const Matrix& other) const;
    Matrix operator*(double scalar) const;
    Matrix operator*(const Matrix& other) const;
    Matrix transpose() const;

    // Friend for scalar * Matrix
    friend Matrix operator*(double scalar, const Matrix& mat);

    // Print
    void print() const;
};

#endif // MATRIX_HPP
