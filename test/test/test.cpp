#include <iostream>
#include <time.h>
#include <Windows.h>

using namespace std;

typedef int Info;

struct Elem
{
    Elem* link;
    Info  info;
};

void insert(Elem*& L, Info value)
{
    Elem* tmp = new Elem; // 1
    tmp->info = value; // 2
    if (L != NULL)
    {
        Elem* T = L;
        while (T->link != L)
            T = T->link; // 3
        T->link = tmp; // 4
    }
    else
    {
        L = tmp; // 5
    }
    tmp->link = L; // 6
}

Info remove(Elem*& L)
{
    Elem* T = L;
    while (T->link != L)
        T = T->link; // 1
    Info value = L->info; // 2
    if (T != L)
    {
        Elem* tmp = L->link; // 3
        delete L; // 4
        L = tmp; // 5
        T->link = L; // 6
    }
    else
    {
        delete L; // 4
        L = NULL; // 7
    }
    return value; // 8
}

void Print(int N, Elem*& L)
{
    Info a;
    for (int i = 0; i < N; i++)
    {
        cout << "Елемент " << i << " :";
        cin >> a;
        insert(L, a);
    }
}

int InfoUp(Elem* L, int n)
{
    if (L == NULL)
        return 0;

    Elem* first = L;
    int x = 0;
    while (L->link != first) {
        x = L->info;
        x += n;
        L->info = x;
        L = L->link;
    }
    L->info += n;
    return x;
}


int main()
{
    srand((unsigned)time(NULL));
    SetConsoleCP(1251); // встановлення сторінки win-cp1251 в потік вводу
    SetConsoleOutputCP(1251); // встановлення сторінки win-cp1251 в потік виводу

    Elem* L = NULL;
    int N;
    cout << "Введіть кількість: "; cin >> N;
    Print(N, L);

    char c;
    int n;
    cout << "\nБажаєте збільшити значення інформаційного поля кожного елемента списку на n разів(Y/y or N/n) ? " << endl; cin >> c;
    if (c == 'Y' || c == 'y') {
        cout << "n = "; cin >> n;
        InfoUp(L, n);
    }

    cout << "Змінений список : ";
    while (L != NULL)
    {
        cout << remove(L) << ' ';
    }
    return 0;
}