#include <stdio.h>

void print_while(){
    int shabi[5] = {1,2,5,6,0};
    int p = 0;
    while(p < sizeof(shabi)/sizeof(int)){
        printf("%d, ", shabi[p]);
        p++;
    }
    printf("\n");
}

void print_for(){
    int shabi[5] = {1,2,5,6,0};
    int p;
    for(p = 0; p < sizeof(shabi)/sizeof(int); p++){
        printf("%d, ", shabi[p]);
    }
    printf("\n");
}

void print_pointer(){
    int shabi[5] = {1,2,5,6,0};
    int p = 0;
    while(p < sizeof(shabi)/sizeof(int)){
        printf("%d, ", *(shabi + p));
        p++;
    }
    printf("\n");
}

int find_min_of_array(int *eru, int n){
    printf("address=%p\n", eru);
    int min_result = eru[0];
    for(int p = 1; p < n; p++){
        if (min_result > eru[p]) {
            min_result = eru[p];
        }
        /*if (eru[p] < eru[p+1]){
            min_result = eru[p];
        }
        else{
            min_result = eru[p+1];
        }*/
    }
    return min_result;
}

void print_min() {
    int eru[4] = {5,7,9,2};
    printf("address=%p\n", eru);
    int result = find_min_of_array(eru, sizeof(eru)/sizeof(int));
    printf("The min of eru is: %d\n", result);
}

int* find_min_of_array_address(int *eru, int n){
    int *min_result_address = eru;
    for(int p = 1; p < n; p++){
        if (*min_result_address > eru[p]) {
            min_result_address = eru + p;
        }
    }
    return min_result_address;
}

int find_min_of_array_index(int *eru, int n){
    int min_result_index = 0;
    for(int p = 1; p < n; p++){
        if (eru[min_result_index] > eru[p]) {
            min_result_index = p;
        }
    }
    return min_result_index;
}

void print_min2() {
    int eru[4] = {5,7,9,2};
    int result = find_min_of_array_index(eru, sizeof(eru)/sizeof(int));
    printf("The min of eru is: %d\n", result);
}

void find_min_of_array_index_noreturn(int *eru, int n, int *x){
    int min_result_index = 0;
    for(int p = 1; p < n; p++){
        if (eru[min_result_index] > eru[p]) {
            min_result_index = p;
        }
    }
    *x = min_result_index;
}

void print_min3() {
    int eru[4] = {5,7,9,2};
    int index_of_array;
    find_min_of_array_index_noreturn(eru, sizeof(eru)/sizeof(int), &index_of_array);
    printf("The index of min in eru is: %d\n", index_of_array);
}

int main() {
    // print_while();
    // print_for();
    // print_pointer();
    print_min3();
}

