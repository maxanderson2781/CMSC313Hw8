#include "matrix.hpp"
#include <iostream>
using namespace std;

Matrix::Matrix(const vector<vector<double>>& data){
    m_data = data;
    m_rows = data.size();
    m_cols = data[0].size();
}

size_t Matrix::numRows() const{
    return m_rows;
}

size_t Matrix::numCols() const{
    return m_cols;
}

const double& Matrix::at(size_t r, size_t c) const{
    return m_data[r][c];
}

Matrix Matrix::operator+(const Matrix& other) const{
    if (m_rows != other.m_rows || m_cols != other.m_cols){
        throw invalid_argument("Invalid sizes for addition.");
    }

    vector<vector<double>> new_data(m_rows, vector<double>(m_cols));
    for (size_t i = 0; i < m_rows; i++){
        for (size_t j = 0; j < m_cols; j++){
            new_data[i][j] = m_data[i][j] + other.m_data[i][j];
        }
    }
    return Matrix(new_data);
}

Matrix Matrix::operator*(double scalar) const{
    vector<vector<double>> new_data(m_rows, vector<double>(m_cols));
    for (size_t i = 0; i < m_rows; i++){
        for (size_t j = 0; j < m_cols; j++){
            new_data[i][j] = m_data[i][j] * scalar;
        }
    }
    return Matrix(new_data);
}

Matrix operator*(double scalar, const Matrix& mat){
    return mat * scalar;
}

Matrix Matrix::operator*(const Matrix& other) const{
    if (m_cols != other.m_rows){
        throw invalid_argument("Invalid sizes for multiplication.");
    }

    vector<vector<double>> new_data(m_rows, vector<double>(other.m_cols));
    for (size_t i = 0; i < m_rows; i++){
        for (size_t j = 0; j < other.m_cols; j++){
            double total = 0;
            for (size_t k = 0; k < m_cols; k++){
                total += m_data[i][k] * other.m_data[k][j];
            }
            new_data[i][j] = total;
        }
    }
    return Matrix(new_data);
}

Matrix Matrix::transpose() const{
    vector<vector<double>> new_data(m_cols, vector<double>(m_rows));
    for (size_t i = 0; i < m_rows; i++){
        for (size_t j = 0; j < m_cols; j++){
            new_data[j][i] = m_data[i][j];
        }
    }
    return Matrix(new_data);
}

void Matrix::print() const{
    for (size_t i = 0; i < m_rows; i++){
        for (size_t j = 0; j < m_cols; j++){
            cout << m_data[i][j] << ' ';
        }
        cout << endl;
    }
}

int main(){
    Matrix A({{6, 4}, {8, 3}});
    Matrix B({{1, 2, 3}, {4, 5, 6}});
    Matrix C({{2, 4, 6}, {1, 3, 5}});

    Matrix D = A + (3 * B) * C.transpose();
    D.print();
    return 0;
}
