// 1. Read matrix from file
// 2. multiply
// 3. Write result into file

#include<stdio.h>
#include <stdlib.h>

struct Matrix {
    int **data;
    int row;
    int col;
};

void create_matrix(struct Matrix *m){
    m->data = (int **)calloc(m->row, sizeof(int*));
    for(int i = 0; i < m->row; i++){
        int col = m->col;
        m->data[i] = (int *)calloc(col, sizeof(int));
    }
}

void read_matrix(char file_name[], struct Matrix *m){
	FILE *fpRead=fopen(file_name,"r");
	if(fpRead==NULL){
		printf("Open fail");
	}
    fscanf(fpRead,"%d ",&m->row);
    fscanf(fpRead,"%d ",&m->col);

    create_matrix(m);
    for(int i = 0; i < m->row; i++){
        for(int j = 0; j < m->col; j++){
            fscanf(fpRead,"%d ",(m->data)[i] + j);
        }
    }
    int fclose( FILE *fp );
}


void print_matrix(struct Matrix m){
    printf("The matrix is:\n");
    for(int i = 0; i < m.row; i++){
        for(int j = 0; j < m.col; j++){
            printf("%d  ", m.data[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int vector_multiplication(int l, int *a, int *b){
    int c = 0;
    for(int i=0; i<l; i++){
        c = c + a[i] * b[i];
    }
    return c;
}

void get_col(struct Matrix m, int n, int *c){
    for(int i = 0; i < m.row; i++){
        c[i] = m.data[i][n];
    }
}

void matrix_multiplication(struct Matrix m1, struct Matrix m2, struct Matrix *m){
    m->row = m1.row;
    m->col = m2.col;
    create_matrix(m);
    int *matrix2_col = (int *)calloc(m2.row, sizeof(int));
    for(int i = 0; i < m->row; i++){
        for(int j = 0; j < m->col; j++){
            get_col(m2, j, matrix2_col);
            (m->data)[i][j] = vector_multiplication(m1.col, m1.data[i], matrix2_col);
        }
    }
    free(matrix2_col);
}

void free_matrix(struct Matrix m){
    for(int i = 0; i < m.row; i++){
        free(m.data[i]);
    }
    free(m.data);
}

int main(){
    char file_name_matrix1[] = "matrix_1.txt";
    char file_name_matrix2[] = "matrix_2.txt";
    struct Matrix matrix1 = {NULL, 0, 0};
    struct Matrix matrix2 = {NULL, 0, 0};
    read_matrix(file_name_matrix1, &matrix1);
    print_matrix(matrix1);
    read_matrix(file_name_matrix2, &matrix2);
    print_matrix(matrix2);

    struct Matrix matrix_product = {NULL, 0, 0};
    matrix_multiplication(matrix1, matrix2, &matrix_product);
    print_matrix(matrix_product);
    free_matrix(matrix1);
    free_matrix(matrix2);
    free_matrix(matrix_product);
}
