#include <stdio.h>

const int row_num = 2;
const int col_num = 4;

void matrix_addition(int *a, int *b, int row, int col, int *c){
    for(int px = 0; px < row; px++){
        for(int py = 0; py < col; py++){
            int pp = px * col + py;
            *(c + pp) = *(a + pp) + *(b + pp);
        }
    }
}

void print_matrix(int *matrix_name, int row, int col){
    printf("The sum of two matrix is:\n");
    for(int px = 0; px < row; px++){
        for(int py = 0; py < col; py++){
            printf("%d  ", matrix_name[px * col + py]);
        }
        printf("\n");
    }
    printf("\n");
}

int main(){
    int zhao[row_num][col_num] = {{25, 14, 1, 0}, {2, 7, 1, 2}};
    int yu[row_num][col_num] = {{1, 5, 3, 2}, {5, 6, 3, 3}};
    int jian[row_num][col_num];
    matrix_addition(zhao, yu, row_num, col_num, jian);
    print_matrix(jian, row_num, col_num);
}