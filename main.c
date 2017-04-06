//Teitelbaum, Michael - CPS393 - Section 02
#include <stdio.h>
#include <stdlib.h>
void mat_multiply(int **mat_1, int **mat_2, int **mat_3, int* row_1, int* col_1, int* row_2, int* col_2, int* row_3, int* col_3);
void mat_out(int **mat, int* row, int* col);
int main() {
    FILE* infile = fopen("C:\\Users\\Mike\\CLionProjects\\W11Q2\\input.txt", "r");
    int row_1, col_1, row_2, col_2, row_3, col_3;
    int **mat_1;
    int **mat_2;
    int **mat_3;
    int x;
    fscanf(infile, "%d", &row_1);
    fscanf(infile, "%d", &col_1);
    mat_1 = (int **) calloc(row_1, sizeof(int*));
    for(int i = 0; i < row_1; i++){
        mat_1[i] = (int *) calloc(col_1, sizeof(int));
    }
    for(int i = 0; i < row_1;i++){
        for(int j = 0; j < col_1; j++){
            fscanf(infile, "%d", &x);
            mat_1[i][j] = x;
        }
    }
    fscanf(infile, "%d", &row_2);
    fscanf(infile, "%d", &col_2);
    mat_2 = (int **) calloc(row_2, sizeof(int*));
    for(int i = 0; i < row_2; i++){
        mat_2[i] = (int *) calloc(col_2, sizeof(int));
    }
    for(int i = 0; i < row_2; i++){
        for(int j = 0; j < col_2; j++){
            fscanf(infile, "%d", &x);
            mat_2[i][j] = x;
        }
    }
    row_3 = row_1;
    col_3 = col_2;
    mat_3 = (int **) calloc(row_3, sizeof(int*));
    for(int i = 0; i < row_3; i++){
        mat_3[i] = (int *) calloc(col_3, sizeof(int));
    }
    mat_multiply(mat_1, mat_2, mat_3, &row_1, &col_1, &row_2, &col_2, &row_3, &col_3);
    mat_out(mat_3, &row_3, &col_3);
}
void mat_multiply(int **mat_1, int **mat_2, int **mat_3, int* row_1, int* col_1, int* row_2, int* col_2, int* row_3, int* col_3){
    for(int i = 0; i < *row_3; i++){
        for(int k = 0; k < *col_3; k++){
            mat_3[i][k] = 0;
            for(int j = 0; j < *row_2; j++){
                mat_3[i][k] = mat_3[i][k] + (mat_1[i][j] * mat_2[j][k]);
            }
        }
    }
}
void mat_out(int **mat, int* row, int* col){
    for(int i = 0; i < *row; i++){
        for(int j = 0; j < *col; j++){
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}