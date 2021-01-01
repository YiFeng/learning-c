#include <stdio.h>
#include <stdlib.h>

int read_input(){
    int end_d;
    printf("Please input the length of array =");
    scanf("%d", &end_d);
    printf("Recieved number = %d\n", end_d);
    return end_d;
}

int *creat_vector(int l){
    int *eru = (int *)calloc(l, sizeof(int));
    for(int i = 0; i < l; i++){
        eru[i] = i + 1;
    }
    return eru;
}

void creat_vector2(int **a, int l){
    *a = (int *)calloc(l, sizeof(int));
    for(int i = 0; i < l; i++){
        (*a)[i] = i + 1;
    }
}

void print_vector(int *a, int n){
    int p = 0;
    printf("The output is:");
    while(p < n){
        printf("%d, ", a[p]);
        p++;
    }
    printf("\n");
}

int main(){
    int length_vector = read_input();
    int *vector_address = NULL;
    // vector_address = creat_vector(length_vector);
    creat_vector2(&vector_address, length_vector);
    print_vector(vector_address, length_vector);
    free(vector_address);    
}