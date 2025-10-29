#include<stdio.h>
#include<stdlib.h>
#include"matrix.h"

float **allocateMatrix(int row, int col){
    float **matrix = (float**)malloc(row*sizeof(float*));
    float *data = (float*)malloc(row*col*sizeof(float));
    for(int i = 0; i < row; i++){
        matrix[i] = &data[i*col]; 
    }
    return matrix;
}

void printMatrix(float **A, int r, int c, FILE *output_file){
    fprintf(output_file, "%d %d\n", r, c);
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            fprintf(output_file, "%g ", A[i][j]);
        }
        fprintf(output_file, "\n");
    }
}

void inputElements(float **matrix, int r, int c, FILE *input_file){
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            fscanf(input_file, "%g", &matrix[i][j]);
        }
    }
}

void matrixAddition(float **A, float **B, int r, int c, FILE *output_file){
    float **newMatrix = allocateMatrix(r, c);
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            newMatrix[i][j] = A[i][j]+B[i][j];
        }
    }
    printMatrix(newMatrix, r, c, output_file);
    freeMatrix(newMatrix);
}

void matrixsubtraction(float **A, float **B, int r, int c, FILE *output_file){
    float **newMatrix = allocateMatrix(r, c);
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            newMatrix[i][j] = A[i][j]-B[i][j];
        }
    }
    printMatrix(newMatrix, r, c, output_file);
    freeMatrix(newMatrix);
}

float **matrixMultiplication(float **A, float **B, int r1, int c1, int r2, int c2){
    float **newMatrix = allocateMatrix(r1, c2);

    for (int i = 0; i < r1; i++){
        for (int j = 0; j < c2; j++){
            newMatrix[i][j] = 0.0f;
        }
    }

    for(int i = 0; i < r1; i++){
        for(int j = 0; j < c2; j++){
            for(int k = 0; k < c1; k++){
                newMatrix[i][j] += A[i][k]*B[k][j];
            }
        }
    }
    return newMatrix;
}

float** allocateIdentityMatrix(int n){
    float **matrix = allocateMatrix(n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = (i == j) ? 1.0f : 0.0f;
        }
    }
    return matrix;
}

void matrixPower(float **A, int n, int power, FILE *output_file){
    if (power == 0) {
        float **result = allocateIdentityMatrix(n);
        printMatrix(result, n, n, output_file);
        freeMatrix(result);
        return;
    }
    
    if (power == 1) {
        printMatrix(A, n, n, output_file);
        return;
    }
    
    float **result = allocateIdentityMatrix(n);
    
    for (int i = 0; i < power; i++) {
        float **temp = matrixMultiplication(result, A, n, n, n, n);
        freeMatrix(result);
        result = temp;
    }

    printMatrix(result, n, n, output_file);
    freeMatrix(result);
}

void cofactor(float **matrix, float **temp, int R, int C, int n){
    int i = 0, j = 0;
    for(int row = 0; row < n; row++){
        for(int col = 0; col < n; col++){
            if(row != R && col != C){
                temp[i][j] = matrix[row][col];
                j++;
                if(j == n - 1){
                    j = 0;
                    i++;
                }
            }
        }
    }
}

int determinantOfMatrix(float **matrix, int n){
    int ans = 0;
    if(n == 1){
        return matrix[0][0];
    }

    float **temp = (float**)malloc(n * sizeof(float*));
    float *data = (float*)malloc(n * n * sizeof(float));
    
    for(int i = 0; i < n; i++) {
        temp[i] = &data[i * n];
    }

    int sign = 1;
    for(int i = 0; i < n; i++){
        cofactor(matrix, temp, 0, i, n);
        ans += sign*matrix[0][i]*determinantOfMatrix(temp, n - 1);
        sign *= -1;
    }

    free(temp);
    return ans;
}

void freeMatrix(float **m){
    if(m!=NULL){
        free(m[0]);
        free(m);
    }
}