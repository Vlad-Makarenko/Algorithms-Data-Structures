#include <iostream>

#define P 10
#define D 3  // Не более з-х разрядов в числах набора

using namespace std;

void ShowArray(int arr[], int size); // показ массива

// Поразрядная сортировка
void RadixSort( int a[], int size);

// Возвращает n-ю цифру считая с нуля в числе v
int digit(int v, int r);

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
    RadixSort(A, size);
    clock_t End1= clock();

    cout << "Массив отсортированый: \n";
    ShowArray(A, size);

    clock_t Start3 = clock();
    RadixSort(A, size);
    clock_t End3= clock();

    ReverseSort(A, size);

    clock_t Start2 = clock();
    RadixSort(A, size);
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


// Возвращает n-ю цифру считая с нуля в числе v
int digit(int v, int r)
{
    for (; r > 0; r--) {
        v /= P;
    }
    return v % P;
}

// Поразрядная сортировка
void RadixSort( int a[], int size)
{
    int b[P];			// Индекс элемента, расположенного за последним в i-й группе
    int i, j, k, m, x;

    for (m=0; m < D; m++)		// Перебираем все числа, начиная с младшего разряда
    {
        for (i=0; i < P; i++) b[i]=0;	// Обнуляем индексы
        for (i=0; i < size; i++){	// Проходим массив
            k=digit(a[i],m);		// Определяем m-ю цифру
            x=a[i];			// Сохраняем элемент
            for (j=i; j > b[k]; j--) {    // И затираем его сдвигая массив вправо
                a[j] = a[j - 1];
            }
            a[b[k]]=x;		// Записываем его в конец k-й группы
            for (j=k; j < P; j++) {    // Модифицируем все индексы не меньшие k
                b[j] = b[j] + 1;
            }
        }
    }
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