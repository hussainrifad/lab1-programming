#ifndef MATRIX_H
#define MATRIX_H

void freeMatrix(float **m);
float** allocateIdentityMatrix(int n);
float **allocateMatrix(int row, int col);
void printMatrix(float **A, int r, int c, FILE *output_file);
int determinantOfMatrix(float **matrix, int n);
void inputElements(float **matrix, int r, int c, FILE *input_file);
void matrixAddition(float **A, float **B, int r, int c, FILE *output_file);
void matrixsubtraction(float **A, float **B, int r, int c, FILE *output_file);
float **matrixMultiplication(float **A, float **B, int r1, int c1, int r2, int c2);
void matrixPower(float **A, int n, int power, FILE *output_file);
void cofactor(float **matrix, float **temp, int R, int C, int n);

#endif