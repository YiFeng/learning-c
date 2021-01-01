#include <stdio.h>

char read_input(){
    char a = 0;
    printf("Please input a character=");
    scanf("%c", &a);
    printf("Recieved character = %c\n", a);
    return a;
}

int main() {
    char end_c = read_input();
    for(char zifu = 'a'; zifu <= end_c; zifu++) {
        printf("%c", zifu);
    }
    printf("\n");
    return 0;
}