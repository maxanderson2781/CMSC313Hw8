#ifndef MATRIX_H
#define MATRIX_H

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int** m_data;
    size_t m_rows;
    size_t m_cols;
} Matrix;

// Constructor & Destructor
Matrix matrix(size_t rows, size_t cols);
void freeMatrix(Matrix* m);
void setElement(Matrix* m, size_t r, size_t c, int value);
Matrix addMatrix(const Matrix* first, const Matrix* second);
Matrix multiplyScalar(const Matrix* m, int scalar);
Matrix multiplyMatrix(const Matrix* first, const Matrix* second);
Matrix transposeMatrix(const Matrix* m);

void printMatrix(const Matrix* m);

#endif // MATRIX_H
