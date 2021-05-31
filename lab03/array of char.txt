#include <stdio.h>

#define SIZE 4

int main() {
    char symbols[SIZE] = {'v', 'l', 'a', 'd'};
    for(int j = 0; j < SIZE; j++){
        for(int i = sizeof(symbols[SIZE]) * 8 - 1; i >= 0; --i){
            printf("%d", (symbols[j] >> i) & 1);
        }
        printf("%c", ' ');
    }
    return 0;
}