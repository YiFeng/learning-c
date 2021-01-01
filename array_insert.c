#include <stdio.h>

void insert_int(int *array, int array_len, int insert_num, int insert_pos){
    int previous_value = 0;
    int f;
    for(int i = insert_pos + 1; i < array_len; i++){
        f = previous_value;
        previous_value = array[i];
        array[i] = f;
    }
    array[insert_pos + 1] = insert_num; 

}

void insert_reverse(int *array, int array_len, int insert_num, int insert_pos){
    for(int i = array_len-1; i > insert_pos; i--){
        array[i] = array[i-1];
    }
    array[insert_pos + 1] = insert_num; 
}

void print_array(int *a, int n){
    for(int i = 0; i < n; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main() {
    const int array_len = 10;
    const int insert_pos = 2;
    int current_len = 5;
    int array[array_len] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    print_array(array, array_len);
    insert_int(array, array_len, 100, insert_pos);
    print_array(array, array_len);

}