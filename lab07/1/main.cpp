#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

template <class T>
struct node{
    T data;
    node* prev;
    node* next;
};

template <class T>
class myStack{
    node<T> *last;
public:
    myStack(){last=NULL;};
    int push(T data);//добавить
    T pop();//извлечь
    T read();//прочитать последний
    int empty(){if(last==NULL) return 1;return 0; };
};

int main(){
    srand(time(NULL));
    setlocale(LC_ALL,"Russian");
    clock_t start = clock();
    cout<<"Проверим стек:"<<endl;
    myStack<int> test;
    if(!test.empty())
        cout<<test.read()<<endl;
    else
        cout<<"Стек пуст"<<endl;
    cout << endl;
    cout<<"Заполним стек;"<<endl;
    for(int i=0;i<7;i++)
        test.push(rand()%10);
    cout << endl;
    cout<<"Прочитаем последний элемент: ";
    if(!test.empty())
        cout<<test.read()<<endl;
    else
        cout<<"Стек пуст"<<endl;
    cout << endl;
    cout<<"Выведем и очистим стек:"<<endl;
    int k = 0;
    while(!test.empty()) {
        cout << "Елемент[" << k << "] = " << test.pop() << endl;
        k++;
    }
    clock_t end = clock();
    double time_spent1 = (double) (end - start) / CLOCKS_PER_SEC;
    printf("\n\nЧас затрачений на виконання программи: %.10f second(s)\n\n", time_spent1);
    return 0;

}
template <class T>
int myStack<T>::push(T data){
    node<T> *add = new node<T>;
    add->data=data;
    add->next=NULL;
    add->prev=NULL;
    if(last==NULL)//стек пуст
        this->last=add;
    else{
        last->next=add;
        last->next->prev=last;
        last=add;
    }
    return 0;
}
template <class T>
T myStack<T>::pop(){
    T copy = this->last->data;
    node<T> *del = last;
    last=last->prev;
    delete del;
    return copy;
}
template <class T>
T myStack<T>::read(){
    T copy = this->last->data;
    return copy;
}