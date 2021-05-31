#include <iostream>

#define MAXINT 32767
#define N 10000

using namespace std;

void ShowArray(int arr[], int size); // показ массива

void TournSort (int a[], int sizeArr);

void ReverseSort(int a[], int size);


int main()
{
    setlocale(LC_ALL, "rus");
    srand(time(NULL));
//    int size = 0;
//    cout << "Размер массива: ";
//    cin >> size;
    int *A = new int[N];

    cout << "Массив случайных чисел: \n";
    for (int i = 0; i < N; i++)
    {
        A[i] = 1 + rand() % 4444;
    }
    //ShowArray(A, N);

    clock_t Start1 = clock();
    TournSort(A, N);
    clock_t End1= clock();

    cout << "Массив отсортированый: \n";
    ShowArray(A, N);

    clock_t Start3 = clock();
    TournSort(A, N);
    clock_t End3= clock();

    ReverseSort(A, N);

    clock_t Start2 = clock();
    TournSort(A, N);
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




void Initialize(int a[], int tree[], const int size)
// Инициализиpуются листья деpева, соответствующие
//               элементам массива.
{
    int j, k;
    for (j =0; j<N; j++)
        tree[size+j] = a[j];
    // Инициализация оставшихся листьев.
    for (j=size + N; j<=2*size-1; j++)   tree[j] = - MAXINT;
    // Вычисление веpхних уpовней деpева.
    // Уpовень, непосpедственно находящийся над листьями, обpабатывается отдельно.
    for ( j=size;  j<=2*size-1;  j += 2)
    {  if ( tree[j]>=tree[j+1] )  tree[j / 2] = j;
        else  tree[j / 2] = j + 1;
    }
    // Вычисление оставшихся уpовней.
    for (k = size / 2;  k > 1; k /= 2)
    {   for (j = k;  j <= 2*k-1;  j += 2)
        {     if ( tree[tree[j]] >= tree[tree[j+1]] )  tree[j / 2] = tree[j];
            else  tree[j / 2] = tree[j+1];
        }
    }
}

// Пеpеупоpядочивание пpедков узла tree[i].
void Readjust (int tree[], unsigned short &i){
    unsigned short j;
    if  ((i % 2)!=0)  tree[i / 2] = i - 1;
    else  tree[i / 2] = i + 1;
    for ( i /= 2; i>1; i /= 2)		// Пpодвижение к коpню.
    {  if  ((i % 2)!=0)  j = i - 1;	//j - бpат i.
        else  j = i + 1;
        if  (tree[tree[i]]>tree[tree[j]])  tree[i / 2] = tree[i];
        else  tree[i / 2] = tree[j];
    }
}

void TournSort (int a[], int sizeArr){
    const int size = 16384; ;      // Число листьев, необходимых в п о л н о м  бинаpном деpеве.
    // Значение пеpеменной size есть наименьшая степень 2, большая или == N. 64, 128, 1024, 16384
    int tree[N * 10];
    int k;
    unsigned short i;
    Initialize(a, tree, size);
    // После того, как деpево постpоено, повтоpяем опеpацию пеpемещения элемента,
    // пpедставленного коpнем, в следующуюпозицию с меньшим индексом в массиве x и пеpеупоpядочивание  деpева.
    for(k=sizeArr-1;k>=0;k--){
        i = tree[1];			      // i - индекс узла с листом, соответствующим коpню.
        a[k] = tree[i];		         // Поместить элемент, на котоpый ссылается коpень в позицию k.
        tree[i] = -MAXINT;
        Readjust (tree,i);      // Пеpеупоpядочивание деpева в соответствии с новым содеpжимым tree[i].
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