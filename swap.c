#include <stdio.h>

void change(int* aa, int* bb){
    int c = *aa;
    *aa = *bb;
    *bb = c;
    printf("change: a = %d, b = %d\n", *aa, *bb);
}

int main(){
    int a = 8;
    int b = 5;
    change(&a , &b);
    printf("main: a = %d, b = %d\n", a, b);
}