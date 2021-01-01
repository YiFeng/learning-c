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

void create_matrix2(int ***matrix_address, int row, int col){
    *matrix_address = (int **)calloc(row, sizeof(int*));
    for(int i = 0; i < row; i++){
        int *row_address = (int *)calloc(col, sizeof(int));
        (*matrix_address)[i] = row_address;
        for(int p = 0; p < col; p++){
            (*matrix_address)[i][p] = i * col + p + 1;
        }
    }
}

void print_matrix(int **matrix, int row, int col){
    printf("The matrix is:\n");
    for(int px = 0; px < row; px++){
        for(int py = 0; py < col; py++){
            printf("%d  ", matrix[px][py]);
        }
        printf("\n");
    }
    printf("\n");
}

void free_matrix(int **matrix_address, int row){
    for(int i = 0; i < row; i++){
        free(matrix_address[i]);
    }
    free(matrix_address);
}

int main(){
    int row, col;
    int **my_matrix_address = NULL;
    read_input(&row, &col);
    create_matrix2(&my_matrix_address, row, col);
    print_matrix(my_matrix_address, row, col);
    free_matrix(my_matrix_address, row);
}