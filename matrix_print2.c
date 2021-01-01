#include <stdio.h>

const int row_num = 2;
const int col_num = 4;

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

int main(){
    int first_row[col_num] = {25, 14, 1, 0};
    int secode_row[col_num] = {2, 7, 1, 2};
    int *matrix[row_num] = {first_row, secode_row}; 
    print_matrix(matrix, row_num, col_num);
}