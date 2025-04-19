#include "matrix.h"

Matrix matrix(size_t rows, size_t cols){
    Matrix new_matrix;
    new_matrix.m_rows = rows;
    new_matrix.m_cols = cols;
    //makes the rows
    new_matrix.m_data = (int**)malloc(rows * sizeof(int*));
    //allocates each row
    for (size_t i = 0; i < rows; i++){
        new_matrix.m_data[i] = (int*)malloc(cols * sizeof(int));
    }
    return new_matrix;
}

void setElement(Matrix* m, size_t r, size_t c, int value) {
    m->m_data[r][c] = value;
}

Matrix add(const Matrix* first, const Matrix* second){
    Matrix result = matrix(first->m_rows, first->m_cols);
    if (first->m_rows == second->m_rows && first->m_cols == second->m_cols){
        for (size_t i = 0; i < first->m_rows; i++){
            for (size_t j = 0; j < first->m_cols; j++){
                result.m_data[i][j] = first->m_data[i][j] + second->m_data[i][j];
            }
        }
    }
    return result;
}

Matrix multiplyScalar(const Matrix* m, int scalar){
    Matrix result = matrix(m->m_rows, m->m_cols);
    for (size_t i = 0; i < m->m_rows; i++){
        for (size_t j = 0; j < m->m_cols; j++){
            result.m_data[i][j] = m->m_data[i][j] * scalar;
        }
    }
    return result;
}

Matrix multiplyMatrix(const Matrix* first, const Matrix* second){
    Matrix result = matrix(first->m_rows, second->m_cols);
    if (first->m_cols == second->m_rows){
        for (size_t i = 0; i < first->m_rows; i++){
            for (size_t j = 0; j < second->m_cols; j++){
                result.m_data[i][j] = 0;
                for (size_t k = 0; k < first->m_cols; k++){
                    result.m_data[i][j] += first->m_data[i][k] * second->m_data[k][j];
                }
            }
        }
    }    
    return result;
}

Matrix transpose(const Matrix* m){
    Matrix result = matrix(m->m_cols, m->m_rows);
    for (size_t i = 0; i < m->m_rows; i++){
        for (size_t j = 0; j < m->m_cols; j++){
            result.m_data[j][i] = m->m_data[i][j];
        }
    }
    return result;
}

void printMatrix(const Matrix* m){
    for (size_t i = 0; i < m->m_rows; i++){
        for (size_t j = 0; j < m->m_cols; j++){
            printf("%i ", m->m_data[i][j]);
        }
        printf("\n");
    }
}

void freeMatrix(Matrix* m){
    for (size_t i = 0; i < m->m_rows; i++){
        free(m->m_data[i]);
    }
    free(m->m_data);
    m->m_data = NULL;
    m->m_rows = 0;
    m->m_cols = 0;
}

int main() {
    //{{6, 4}, {8, 3}}
    Matrix A = matrix(2, 2);
    setElement(&A, 0, 0, 6);
    setElement(&A, 0, 1, 4);
    setElement(&A, 1, 0, 8);
    setElement(&A, 1, 1, 3);

    //{{1, 2, 3}, {4, 5, 6}}
    Matrix B = matrix(2, 3);
    setElement(&B, 0, 0, 1);
    setElement(&B, 0, 1, 2);
    setElement(&B, 0, 2, 3);
    setElement(&B, 1, 0, 4);
    setElement(&B, 1, 1, 5);
    setElement(&B, 1, 2, 6);

    //{{2, 4, 6}, {1, 3, 5}}
    Matrix C = matrix(2, 3);
    setElement(&C, 0, 0, 2);
    setElement(&C, 0, 1, 4);
    setElement(&C, 0, 2, 6);
    setElement(&C, 1, 0, 1);
    setElement(&C, 1, 1, 3);
    setElement(&C, 1, 2, 5);

    //does the test
    Matrix B_scaled = multiplyScalar(&B, 3);
    Matrix C_transposed = transpose(&C);
    Matrix BxC = multiplyMatrix(&B_scaled, &C_transposed);
    Matrix D = add(&A, &BxC);

    //print
    printMatrix(&D);

    freeMatrix(&A);
    freeMatrix(&B);
    freeMatrix(&C);
    freeMatrix(&B_scaled);
    freeMatrix(&C_transposed);
    freeMatrix(&BxC);
    freeMatrix(&D);

    return 0;
}
