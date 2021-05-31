#include <stdio.h>
#include <stdbool.h>

#include <time.h>


void BYTE(unsigned char A) // виведення вмісту байта
{
    for(int i = sizeof(A) * 8 - 1; i >= 0; --i){
        printf("%d", (A >> i) & 1);
    }
    printf("%c", ' ');
}

#pragma pack (push,1)
struct Train_transport {
    bool stops_at_all_stations;
    bool Traffic_on_the_schedule;
    union {
        struct {
            short number_of_people;
        }passenger_train;
        struct {
            short number_of_cars;
            double amount_of_cargo;
        }freight_train;
    } un1;
};
#pragma pack(pop)


#pragma pack (push,1)
struct Initial
{
    int a:4;
    int b:4;
    int c;
};
#pragma pack(pop)


int main()
{
    //srand(time(NULL));
    struct Train_transport obj1 = {true, true};
    obj1.un1.freight_train.amount_of_cargo = 121.245;
    obj1.un1.freight_train.number_of_cars = 44;
    printf("Size of structure train_transport structure: %ld\n", sizeof(struct Train_transport));
    unsigned char *p =  (unsigned char*) &obj1;
    int byte = 0;
    for( ; byte < sizeof(struct Train_transport); byte++, p++ ) {
        if(byte % 8 == 0)
            printf("\n");
        BYTE(*p);

    }
    printf("\n");
    clock_t start = clock();
    printf("\nNumber of cars: %d\n", obj1.un1.freight_train.number_of_cars);
    clock_t end = clock();
    double seconds = (double)(end - start) / CLOCKS_PER_SEC;
    printf("\nAccess time is %.10lf second(s)\n", seconds);

    struct Initial obj2 = { 4, 4, 44 };
    unsigned char* pt = (unsigned char*)&obj2;
    int byte1 = 0;
    printf("\nSize of Initial structure: %ld\n",  sizeof(struct Initial));
    for (; byte1 < sizeof(struct Initial); byte1++, pt++)
    {
        if (byte1 % 8 == 0) printf("\n");
        BYTE(*pt);
    }
    printf("\n");
    printf("\n");

    struct Train_transport array[2] = {{false, true}, {false, false} };
    array[0].un1.freight_train.amount_of_cargo = 25.34;
    array[0].un1.freight_train.number_of_cars = 44;
    array[1].un1.passenger_train.number_of_people = 111;

    p = (unsigned char*)&array;
    byte = 0;
    printf("Size of struct array: %ld\n", sizeof(array));
    for (; byte < sizeof(array); byte++, p++)
    {
        if (byte % 8 == 0) printf("\n");
        BYTE(*p);
    }
    printf("\n");
    return 0;
}
