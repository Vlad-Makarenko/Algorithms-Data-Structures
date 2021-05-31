#include <stdlib.h>
#include <iostream>
using namespace std;

class TreeNode{
    int key;                        //ключ
    int counter = 0;
    int info;			            //информационное поле
    TreeNode *LLink, *RLink;        //указатель на левый и правый узел
public:
    TreeNode(){ key=0;LLink= RLink=NULL;}       //конструктор по умолчанию
    TreeNode(int k, int info_c)	                //конструктор с параметр
    {   key=k;
        info=info_c;
        LLink=RLink=NULL;
    }
    ~TreeNode(){}	            	//Деструктор

    void Insert(int number, int info, TreeNode *ptr);       //функция добавления элемента в дерево
    void PrintTree(TreeNode *ptr, int n);                   //функция вывода дерева на экран
    void DeleteTree(TreeNode *ptr);                         //функция удаления дерева
    int getCounter();                                       //функция получения количества правых узлов
    void PostOrder(TreeNode *&root);
    void preOrder(TreeNode *&root);
};


int TreeNode::getCounter() {
    return this->counter;
}

void TreeNode::PostOrder(TreeNode *&root)
{
    TreeNode *current = root;
    if (!root) return;
    if (current->LLink)PostOrder(current->LLink);
    if (current->RLink)PostOrder(current->RLink);
    for (int i=0; i < current->info; i++)   // обработка узла
        printf(" ");
    printf("%d \n", current->key);
}

void TreeNode::preOrder(TreeNode *&root)
{
    TreeNode *current = root;
    if (!root) return;
    for (int i=0; i < current->info; i++)   // обработка узла
        printf(" ");
    printf("%d \n", current->key);
    if (current->LLink)preOrder(current->LLink);
    if (current->RLink)preOrder(current->RLink);
}



void TreeNode::Insert(int n, int inf, TreeNode *ptr)
{	cout<<"\n Добавляется элемент ("<<n<<";"<<inf<<")\n";
    int flag=1;
    TreeNode *p, *q;
    p=ptr;
    while(flag){
        if(n < p->key){
            q=p->LLink;	 //a3
            cout<<"Найден узел "<<p->key<<endl<<"Переход влево";
            if(q==NULL)  cout<<"NULL"<<endl;
            else cout<<q->key<<endl;
            if(q == NULL){
                flag=0;
                cout<<"Создается новый элемент ("<<n<<","<<inf<<")\n";
                q=new TreeNode(n, inf);
                cout<<"Обновление связей: "<<p->key<<"->LLink = "<<q->key<<endl;
                p->LLink=q;
            } else {
                p=q;
            }
        }
        else if(n > p->key)
        {  q=p->RLink;		 //a4
            cout<<"Найден узел "<<p->key<<endl<<"Переход вправо";
            if(q == NULL)cout<<"NULL"<<endl;
            else cout<<q->key<<endl;
            if(q == NULL){
                flag=0;
                cout<<"Создается новый элемент ("<<n<<","<<inf<<")\n ";
                q=new TreeNode(n, inf);
                cout<<"Обновление связей: "<<p->key<<"->RLink = "<<q->key<<endl;
                p->RLink=q;
                this->counter++;
            }
            else {
                p=q;
            }
        }
        else if(n == p->key){
            cout<<"Такой элемент уже существует "<<endl;
            flag=0;         //выход из цикла WHILE
        }
    }
}

void TreeNode:: PrintTree(TreeNode *ptr, int n)
{	if (ptr)
    {   PrintTree(ptr->RLink, n+3);
        for(int i=1;i<n;i++)
            cout << " ";
        cout<< ptr->key<<endl;
        PrintTree(ptr->LLink, n+3);
    }
}

void TreeNode::DeleteTree(TreeNode *ptr){
    if (ptr != NULL){
        DeleteTree(ptr->LLink);
        DeleteTree(ptr->RLink);
        delete(ptr);
    }
}

int main()		//главная программа
{
    setlocale(LC_ALL, "Rus"); // для работи з кирилицей
    int k_elem;
    cout << "  Сколько элементов добавлять?  ";
    cin >> k_elem;
    int num,inf;

    num=rand() % 100 + 1;       //случайные значения
    inf=rand() % 100 + 1;

    TreeNode *root=new TreeNode(num, inf);	//указатель на корень

    for(int i=1; i<k_elem; i++)
    {
        num=rand() % 100 + 1;   //случайные значения
        inf=rand() % 100 + 1;
        root->Insert(num,inf,root);
    }

    cout << endl << "Дерево:" << endl;
    root->PrintTree(root, 5);
    //cout << endl << "Количество правых узлов:  " << root->getCounter() <<endl;
    cout << endl << " восходящий обход дерева:" << endl;
    clock_t Start1 = clock();
    root->PostOrder(root);
    clock_t End1 = clock();

    cout << endl << " Нисходящий обход дерева:" << endl;
    clock_t Start2 = clock();
    root->preOrder(root);
    clock_t End2 = clock();

    double Res1 = (double)(End1 - Start1)/ CLOCKS_PER_SEC;
    printf("Время восходящего обхода дерева: %.10f сек\n\n", Res1);

    double Res2 = (double)(End2 - Start2)/ CLOCKS_PER_SEC;
    printf("Время нисходящего обхода дерева: %.10f сек\n\n", Res2);

    root->DeleteTree(root);		//освобождение памяти
}