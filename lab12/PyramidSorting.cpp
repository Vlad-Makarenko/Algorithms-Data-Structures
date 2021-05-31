#include <iostream>

#define P 10
#define D 3  // Не более з-х разрядов в числах набора

using namespace std;

void ShowArray(int arr[], int size); // показ массива

void HeapSort(int a[], int size);

void downHeap(int a[], int k, int n);

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
    HeapSort(A, size);
    clock_t End1= clock();

    cout << "Массив отсортированый: \n";
    ShowArray(A, size);

    clock_t Start3 = clock();
    HeapSort(A, size);
    clock_t End3= clock();

    ReverseSort(A, size);

    clock_t Start2 = clock();
    HeapSort(A, size);
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


// Процедура просеивания следующего элемента
void downHeap(int a[], int k, int n){
    // До процедуры: a[k+1]...a[n]  - пирамида
    // После:  a[k]...a[n]  - пирамида
    int new_elem;
    int child;
    new_elem = a[k];

    while(k <= n/2)  		// пока у a[k] есть дети
    { child = 2*k;
        // выбираем большего сына
        if( child < n && a[child] < a[child+1] )
            child++;
        if( new_elem >= a[child] ) break;
        // иначе
        a[k] = a[child]; 	// переносим сына наверх
        k = child;
    }
    a[k] = new_elem;
}

// Пирамидальная сортировка
void HeapSort(int a[], int size){
    int i;
    // строим пирамиду
    for(i=size/2-1; i >= 0; i--) {
        downHeap(a, i, size-1);
    }
    // теперь a[0]...a[size-1] пирамида
    for(i=size-1; i > 0; i--)
    { // меняем первый с последним
        swap(a[i], a[0]);
        // восстанавливаем пирамидальность a[0]...a[i-1]
        downHeap(a, 0, i-1);
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