#include <iostream>

using namespace std;

void ShowArray(int arr[], int size); // показ массива

void BubbleSort(int a[], int size); //сортировка масива

void ReverseSort(int a[], int size);

int main()
{
    setlocale(LC_ALL, "rus");
    srand(time(NULL));
    int size = 0;
    cout << "Размер массива: ";
    cin >> size;
    int *A = new int[size];
    int B[size];

    cout << "Массив случайных чисел: \n";
    for (int i = 0; i < size; i++)
    {
        A[i] = 1 + rand() % 444;
        B[i] = A[i];
    }
    ShowArray(A, size);

    clock_t Start1 = clock();
    BubbleSort(A, size);
    clock_t End1= clock();

    clock_t Start4 = clock();
    BubbleSort(B, size);
    clock_t End4= clock();

    cout << "Массив отсортированый пузырьком: \n";
    ShowArray(A, size);

    clock_t Start3 = clock();
    BubbleSort(A, size);
    clock_t End3= clock();

    clock_t Start6 = clock();
    BubbleSort(B, size);
    clock_t End6= clock();

    ReverseSort(A, size);
    ReverseSort(B, size);

    clock_t Start2 = clock();
    BubbleSort(A, size);
    clock_t End2= clock();

    clock_t Start5 = clock();
    BubbleSort(B, size);
    clock_t End5= clock();

    double Res1 = (double)(End1 - Start1)/ CLOCKS_PER_SEC;
    printf("Время сортировки динамического массива пузырьком(случайный набор данных): %.10f сек\n\n", Res1);

    double Res2 = (double)(End2 - Start2)/ CLOCKS_PER_SEC;
    printf("Время сортировки динамического массива пузырьком(обратно отсортированный набор данных): %.10f сек\n\n", Res2);

    double Res3 = (double)(End3 - Start3)/ CLOCKS_PER_SEC;
    printf("Время сортировки динамического массива пузырьком(отсортированный набор данных): %.10f сек\n\n\n", Res3);

    double Res4 = (double)(End4 - Start4)/ CLOCKS_PER_SEC;
    printf("Время сортировки статического массива пузырьком(случайный набор данных): %.10f сек\n\n", Res4);

    double Res5 = (double)(End5 - Start5)/ CLOCKS_PER_SEC;
    printf("Время сортировки статического массива пузырьком(обратно отсортированный набор данных): %.10f сек\n\n", Res5);

    double Res6 = (double)(End6 - Start6)/ CLOCKS_PER_SEC;
    printf("Время сортировки статического массива пузырьком(отсортированный набор данных): %.10f сек\n\n", Res6);

    return 0;
}

//вывод массива на экран
void ShowArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout.width(5);
        cout << arr[i];
        if ((i + 1) % 10 == 0)
        {
            cout << endl;
        }
    }
    cout << endl << endl;
}

void BubbleSort(int a[], int size)
{
    int counter = 0;
    int per = 0;
    for (int i=0; i<size; i++){
        for (int j=0; j<size-1-i; j++){
            counter++;
            if (a[j]>a[j+1]){
                per++;
                swap(a[j],a[j+1]);
            }
        }
    }
    cout << "Количество сравнений: " << counter << endl;
    cout << "Количество перессылок: " << per<< endl;
}

void ReverseSort(int a[], int size)
{
    int counter = 0;
    for (int i=0; i<size; i++){
        for (int j=0; j<size-1-i; j++){
            counter++;
            if (a[j] < a[j + 1]){
                swap(a[j],a[j + 1]);
            }
        }
    }
}