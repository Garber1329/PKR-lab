#include <iostream>
#include <iomanip>

using namespace std;

typedef int Info;
struct Elem
{
    Elem* next, * prev;
    int info;
};

void enqueue(Elem*& first, Elem*& last, Info value)
{
    Elem* tmp = new Elem;
    tmp->info = value;
    tmp->next = NULL;
    if (last != NULL)
        last->next = tmp;
    tmp->prev = last;
    last = tmp;
    if (first == NULL)
        first = tmp;
}

int count(Elem*& first, Elem*& last, Elem* tmp, int& result)
{
    if (tmp != NULL)
    {
        if (tmp->info < 0)
            result++;
        return count(first, last, tmp = tmp->next, result);
    }
}

Info dequeue(Elem*& first, Elem*& last)
{
    Elem* tmp = first->next;
    Info value = first->info;
    delete first;
    first = tmp;
    if (first == NULL)
        last = NULL;
    else
        first->prev = NULL;
    return value;
}

void Create(Elem*& first, Elem*& last, int i)
{
    if (i <= 10) {
        enqueue(first, last, i);
        Create(first, last, i + 1);
    }
}

void DeleteEnum(Elem*& first, Elem*& last)
{
    if (first != NULL) {
        cout << "delete:" << dequeue(first, last) << endl;
        DeleteEnum(first, last);
    }
       
}

void PrintEnum(Elem*& first, Elem*& last, Elem* tmp)
{
    if (tmp != NULL) {
        cout << tmp->info << " ";
        return PrintEnum(first, last, tmp = tmp->next);
    }
    else
        cout << endl;
}

int main()
{
    Elem* first = NULL,
        * last = NULL;

    Create(first, last, -8);
    PrintEnum(first, last, first);

    int res = 0;
    count(first, last, first, res);
    cout << " Count = " << res << endl;

    DeleteEnum(first, last);
    return 0;
}