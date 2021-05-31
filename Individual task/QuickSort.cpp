#include <iostream>

using namespace std;

void ShowArray(int arr[], int size); // показ массива

void HoaraSort(int a[], int b, int e);

void ReverseSort(int a[], int size);


int main()
{
    setlocale(LC_ALL, "rus");
    srand(time(NULL));
    int size = 0;
    cout << "Размер массива: ";
    cin >> size;
    int *A = new int[size];

    cout << "Массив случайных чисел: \n";
    for (int i = 0; i < size; i++)
    {
        A[i] = 1 + rand() % 444;
    }
    ShowArray(A, size);

    clock_t Start1 = clock();
    HoaraSort(A, 0, size);
    clock_t End1= clock();

    cout << "Массив отсортированый: \n";
    ShowArray(A, size);

    clock_t Start3 = clock();
    HoaraSort(A, 0, size);
    clock_t End3= clock();

    ReverseSort(A, size);

    clock_t Start2 = clock();
    HoaraSort(A, 0, size);
    clock_t End2= clock();

    double Res1 = (double)(End1 - Start1)/ CLOCKS_PER_SEC;
    printf("Время сортировки (случайный набор данных): %.10f сек\n\n", Res1);

    double Res2 = (double)(End2 - Start2)/ CLOCKS_PER_SEC;
    printf("Время сортировки (обратно отсортированный набор данных): %.10f сек\n\n", Res2);

    double Res3 = (double)(End3 - Start3)/ CLOCKS_PER_SEC;
    printf("Время сортировки (отсортированный набор данных): %.10f сек\n\n", Res3);

    delete [] A;
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


void HoaraSort(int a[], int b, int e)
{
    int i = b;
    int j = e;
    int tmp = 0;
    int x = a[(i+j)/2];
    do {
        while (a[i] < x) i++;
        while (a[j] > x) j--;
        if (i <= j)
        {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    } while (i <= j);
    if (i<e)  HoaraSort(a, i, e);
    if (b<j)  HoaraSort(a, b, j);
}

void ReverseSort(int a[], int size) {
    int counter = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - 1 - i; j++) {
            counter++;
            if (a[j] < a[j + 1]) {
                swap(a[j], a[j + 1]);
            }
        }
    }
}