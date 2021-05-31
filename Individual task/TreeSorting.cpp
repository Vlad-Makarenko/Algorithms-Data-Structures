#include <iostream>

using namespace std;

void ShowArray(int arr[], int size); // показ массива

void TreeSort(int a[], int size);

void Surface(int a[], int i, int k);

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
    TreeSort(A, size);
    clock_t End1= clock();

    cout << "Массив отсортированый: \n";
    ShowArray(A, size);

    clock_t Start3 = clock();
    TreeSort(A, size);
    clock_t End3= clock();

    ReverseSort(A, size);

    clock_t Start2 = clock();
    TreeSort(A, size);
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


void Surface(int a[], int i, int k){
    int j, m = 2*i, temp = a[i];
    while(m <= k)
    {   if( m == k) j = m;
        else if (a[m] > a[m+1]) j = m;
        else j = m+1;
        if(a[j] > temp)
        {  a[i] = a[j];
            i = j;
            m = 2*i;
        }
        else break;
    }
    a[i]=temp;
}

void TreeSort(int a[], int size)
{   int i, k, w;
    for(i = size/2; i >=0; i--)
        Surface (a, i, size);
    for(k = size-1; k >=0; k--)
    {   Surface (a, 0, k);
        swap(a[k],a[0]);
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