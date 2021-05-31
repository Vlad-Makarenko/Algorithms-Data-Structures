#include <iostream>


using namespace std;

void ShowArray(int arr[], int size); // показ массива

// Сортування попарним злиттям
void PairMergeSort(int a[], int size);

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
    PairMergeSort(A, size);
    clock_t End1= clock();

    cout << "Массив отсортированый: \n";
    ShowArray(A, size);

    clock_t Start3 = clock();
    PairMergeSort(A, size);
    clock_t End3= clock();

    ReverseSort(A, size);

    clock_t Start2 = clock();
    PairMergeSort(A, size);
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

void PairMergeSort(int a[], int size){
    int i0,j0,i,j,si,sj,k,ke,t,m ;
    si=1;              // начальный размер одного множества
    while (si<size)		  //цикл пока одно множество не составит весь массив}
    { i0 =0;           // нач. индекс 1-го множества пары
        while (i0<size)     // цикл пока не пересмотрим весь массив
        {   j0 = i0+si;    // нач. индекс 2-го множества пары
            i=i0; j=j0;
//размер 2-го множества пары может ограничиваться концом массива
            if (si>=size-j0)  sj=size-j0;
            else sj=si;
            if (sj>0)
            {  k = i0;        // нач. индекс слитого множества
                while ( (i < i0+si+sj) && (j < j0+sj))  // цикл пока не исчерпаются оба входные множества
                {   if (a[i]>a[j])
// если эл-т 1-го <= элемента 2-го, он остается на своем месте, но вых.множество расширяется
// иначе - освобождается место в вых.множестве и туда  заносится эл-т из 2-го множества
                    {   t=a[j];
                        for (m =j-1; m>=k; m--) a[m+1] =a[m];
                        a[k] =t; j++;  //к след. эл-ту во 2-м множестве
                    }
                    k++; // вых. множество увеличилось
                    i++; // если был перенос - за счет сдвига, если не было - за счет перехода эл-та в вых.
                }
            }
            i0 += si*2;  // начало следующей пары
        }
        si*=2;  // размер эл-тов пары увеличивается вдвое
    }
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