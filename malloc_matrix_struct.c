#include <stdio.h>
#include <stdlib.h>

struct Matrix {
    int **data;
    int row;
    int col;
};

void read_input(struct Matrix *m){
    printf("Please input the row number of a matrix =");
    scanf("%d", &m->row);
    printf("Recieved number = %d\n", m->row);
    printf("Please input the column number of a matrix =");
    scanf("%d", &m->col);
    printf("Recieved number = %d\n", m->col);
}

void create_matrix2(struct Matrix *m){
    m->data = (int **)calloc(m->row, sizeof(int*));
    for(int i = 0; i < m->row; i++){
        int col = m->col;
        m->data[i] = (int *)calloc(col, sizeof(int));
        for(int j = 0; j < col; j++){
            m->data[i][j] = i * col + j + 1;
        }
    }
}

void print_matrix(struct Matrix m){
    printf("The matrix is:\n");
    for(int i = 0; i < m.row; i++){
        for(int j = 0; j < m.col; j++){
            printf("%d  ", m.data[i][j]);
        }
        printf("\n");
    }
}

void free_matrix(struct Matrix m){
    for(int i = 0; i < m.row; i++){
        free(m.data[i]);
    }
    free(m.data);
}

int main(){
    struct Matrix my_matrix = {NULL, 0, 0};
    read_input(&my_matrix);
    create_matrix2(&my_matrix);
    print_matrix(my_matrix);
    free_matrix(my_matrix);
}