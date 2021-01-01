#include <stdio.h>

int end_d = 0;

void read_input(){
    // int a = 0;
    printf("Please input a number=");
    scanf("%d", &end_d);
    printf("Recieved number = %d\n", end_d);
    // return end_d;
}

int main() {
    int sum_a = 0;
    //int end_d = read_input();
    read_input();
    for(int a = 1; a < end_d + 1; a++) {
        sum_a  = sum_a + a;
    }
    printf("The sum of 1 to %d is: %d\n", end_d, sum_a);
    return 0;
}