#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include"matrix.h"

int main(int argc, char *argv[]){
    FILE *input_file = fopen("input.txt", "r");
    FILE *output_file = fopen("output.txt", "w");
    
    if (input_file == NULL || output_file == NULL) {
        printf("Error opening files!\n");
        return 1;
    }
    
    char c;
    fscanf(input_file, "%c", &c);

    if(c == '+'){
        int AR, AC;
        fscanf(input_file, "%d%d", &AR, &AC);
        float **mat1 = allocateMatrix(AC, AR);
        inputElements(mat1, AR, AC, input_file);
        int BR, BC;
        fscanf(input_file, "%d%d", &BR, &BC);
        float **mat2 = allocateMatrix(BC, BR);
        inputElements(mat2, BR, BC, input_file);
        matrixAddition(mat1, mat2, AR, AC, output_file);
        freeMatrix(mat1);
        freeMatrix(mat2);
    }
    else if(c == '-'){
        int AR, AC;
        fscanf(input_file, "%d%d", &AR, &AC);
        float **mat1 = allocateMatrix(AC, AR);
        inputElements(mat1, AR, AC, input_file);
        int BR, BC;
        fscanf(input_file, "%d%d", &BR, &BC);
        float **mat2 = allocateMatrix(BC, BR);
        inputElements(mat2, BR, BC, input_file);
        matrixsubtraction(mat1, mat2, AR, AC, output_file);
        freeMatrix(mat1);
        freeMatrix(mat2);
    }
    else if(c == '*'){
        int AR, AC;
        fscanf(input_file, "%d%d", &AR, &AC);
        float **mat1 = allocateMatrix(AC, AR);
        inputElements(mat1, AR, AC, input_file);
        int BR, BC;
        fscanf(input_file, "%d%d", &BR, &BC);
        float **mat2 = allocateMatrix(BC, BR);
        inputElements(mat2, BR, BC, input_file);
        float **newMat = matrixMultiplication(mat1, mat2, AR, AC, BR, BC);
        printMatrix(newMat, AR, BC, output_file);
        freeMatrix(newMat);
        freeMatrix(mat1);
        freeMatrix(mat2);
    }
    else if(c == '^'){
        int AR, AC, p;
        fscanf(input_file, "%d%d", &AR, &AC);
        float **mat1 = allocateMatrix(AC, AR);
        inputElements(mat1, AR, AC, input_file);
        fscanf(input_file, "%d", &p);
        matrixPower(mat1, AR, p, output_file);
        freeMatrix(mat1);
    }
    else if(c == '|'){
        int AR, AC;
        fscanf(input_file, "%d%d", &AR, &AC);
        float **mat1 = allocateMatrix(AC, AR);
        inputElements(mat1, AR, AC, input_file);
        int res = determinantOfMatrix(mat1, AR);
        fprintf(output_file, "%d", res);
        freeMatrix(mat1);
    }

    fclose(input_file);
    fclose(output_file);
    return 0;
}