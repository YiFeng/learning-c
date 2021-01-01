#include <stdio.h>

void vector_addition(int *a, int *b, int n, int *c){
    for(int p = 0; p < n; p++){
        c[p] = a[p] + b[p];
    }

}

void print_vector(int *a, int n){
    int p = 0;
    printf("The sum of two vectors is:");
    while(p < n){
        printf("%d, ", a[p]);
        p++;
    }
    printf("\n");
}

int main(){
    int zhao[4] = {25, 14, 1, 0};
    int yu[4] = {1, 5, 3, 2};
    int jian[4];
    vector_addition(zhao, yu, 4, jian);
    print_vector(jian, 4);
}