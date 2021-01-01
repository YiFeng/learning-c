// 1. Input row and column by user
// 2. Fill the matrix from 1 to row*col
// 3. Use two methods to create the matrix
//    1. 1-d array
//    2. 2-d array
// 4. Free the used memeory correctly.


#include <stdio.h>
#include <stdlib.h>

void read_input(int *row_num, int *col_num){
    printf("Please input the row number of a matrix =");
    scanf("%d", row_num);
    printf("Recieved number = %d\n", *row_num);
    printf("Please input the column number of a matrix =");
    scanf("%d", col_num);
    printf("Recieved number = %d\n", *col_num);
}

void creat_matrix1_1(int **a, int row, int col){
    int l = row * col;
    *a = (int *)calloc(l, sizeof(int));
    for(int px = 0; px < row; px++){
        for(int py = 0; py < col; py++){
            int pp = px * col + py;
            (*a)[pp] = pp + 1;
        }
    }
}

void creat_matrix1_2(int **a, int row, int col){
    int l = row * col;
    *a = (int *)calloc(l, sizeof(int));
    for(int p = 0; p < row * col; p++){
        (*a)[p] = p + 1;
    }
}

void print_matrix(int *matrix_name, int row, int col){
    printf("The matrix is:\n");
    for(int px = 0; px < row; px++){
        for(int py = 0; py < col; py++){
            printf("%d  ", matrix_name[px * col + py]);
        }
        printf("\n");
    }
    printf("\n");
}

int main(){
    int row;
    int col;
    read_input(&row, &col);
    int *matrix_address = NULL;
    creat_matrix1_1(&matrix_address, row, col);
    print_matrix(matrix_address, row, col);
    free(matrix_address);
}