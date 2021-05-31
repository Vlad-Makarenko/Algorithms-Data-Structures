#include <stdlib.h>
#include <stdio.h>
#include <time.h>


int power( int x, int n); //  Повертає х у ступені n (n>=0)

int main()
{
    int n; //степінь
    int a; //число
    clock_t begin = clock();
    printf("Введіть число: ");
    scanf("%i", &a);
    printf("Введіть степінь: ");
    scanf("%i", &n);
    if (n < 0){
        printf("Неприпустимий аргумент функції");
    }else{
        int result = power(a, n);
        printf("%i в степені %i дорівнює %i \n", a, n, result);
    }
    clock_t end = clock();
    double time_spent = (double)(end - begin)/ CLOCKS_PER_SEC;
    printf("Час, затрачений на виконання функції: %.10f", time_spent);
    return 0;
}

int power( int x, int n)
{
    if (n > 0 ){
        return power(x, n-1) * x;
    }else{
        return 1 ;// n == 0
    }
}