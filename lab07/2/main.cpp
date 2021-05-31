#include <iostream>
#include <new>
#include <ctime>
#include <cstdlib>
using namespace std;

// класс, реализующий стек в виде динамического массива
template <typename T>
class STACK
{
private:
    T* stack; // Динамический масив-указатель на стек
    int count; // Вершина стека - количество элементов типа T в стеке
public:
    STACK() // конструктор по умолчанию
    {
        count = 0; // количество элементов в стеке определяется по значению count
    }
    void push(T item)  // помістити елемент в стек
    {
        T* tmp; // временный указатель
        tmp = stack;  // указатель указывает на stack
        stack = new T[count + 1];  // выделить память на 1 элемент больше, чем было выделено до этого
        count++; // увеличить количество элементов в стеке на 1
        for (int i = 0; i < count - 1; i++)  // скопировать данные из памяти, на которую указывает tmp в память, на которую указывает stack
            stack[i] = tmp[i];
        stack[count - 1] = item; // добавить последний элемент
        // освободить память, выделенную перед этим для stack, на эту память указывает tmp
        if (count > 1)
            delete[] tmp;
    }
    // Вытягнуть элемент из стека
    // При вытягивании элемента из стека память не переопределяется
    T pop()
    {
        if (count == 0)
            return 0; // стек пуст
        count--;
        return stack[count];
    }
    // Просмотр элемента в вершине стека
    T Head()
    {
        if (count == 0)
            return 0;
        return stack[count - 1];
    }
    // Количество элементов в стеке
    int Count()
    {
        return count;
    }
    // Функция, которая определяет пуст ли стек
    bool IsEmpty()
    {
        return count == 0;
    }
    // Функция, выводящая стек
    void Print()
    {
        T* p; // временный указатель, двигается по элементах стека
        // 1. Установить указатель p на вершину стека
        p = stack;
        // 2. Вивід
        cout << "Стек: " << endl;
        if (count == 0)
            cout << "Пусто" << endl;
        for (int i = 0; i < count; i++)
        {
            cout << "Елемент[" << i << "] = " << *p << endl;
            p++; // прокрутить указатель на следующий элемент
        }
        cout << endl;
    }
};

int main()
{
    clock_t start = clock();
    srand(time(NULL));
    setlocale(LC_ALL,"Russian");
    STACK <int> st1;  // объявить стек из целых чисел
    st1.Print(); // st1 = { }
    // заполняем стек
    cout << "Заполним стек рандомными елементами: " << endl;
    cout << endl;
    st1.push(rand()%10);
    st1.push(rand()%10);
    st1.push(rand()%10);
    st1.push(rand()%10);
    st1.Print();
    cout << "Количество елементов: " << st1.Count() << endl;
    cout << endl;
    int t;
    t = st1.pop(); // t = 7
    cout << "Удалим елемент: " << t << endl;
    cout << endl;
    st1.Print(); // 5, 9, 13
    cout << "Прочитаем последний элемент: " << st1.Head() << endl;
    int k;
    t = st1.pop(); // st1 = { 5, 9 }
    k = st1.pop(); // st1 = { 5 }
    cout << "Удалим елементы: " << t << " и " <<  k << endl;
    cout << endl;
    st1.Print();
    cout << "Очистим стек: " << endl;
    st1.pop();
    if (st1.IsEmpty())
        cout << "Стек пустой." << endl;
    else
        cout << "Стек не пустой" << endl;
    clock_t end = clock();
    double time = (double )(end - start) / CLOCKS_PER_SEC;
    printf("%.10f", time);
}
