#include <iostream>
#include <windows.h>
#include <iomanip>
#include <string>

using namespace std;

struct StElem
{
    StElem* next,
          * prev;
    string prizv;
    double averageMark;
    int stipend;
};

void CreateList(StElem*& first, StElem*& last, int N);
void AddElem(StElem*& first, StElem*& last, string prizv, double averageMark, int stipend);
void Print(StElem* first, int i);
int Find(StElem* first, int i, double x);
void DeleteBegElem(StElem*& first, StElem*& last);
void DeleteElem(StElem*& first, StElem*& last);
void Scanning(StElem* first, StElem* last);

int main()
{
    StElem* first = NULL,
        * last = NULL;

    int N;
    double x;
    cout << "N: "; cin >> N;
    cout << endl;
    CreateList(first, last, N);
    cout << endl;
    for (int i = 0; i < 3; i++)
        Print(first, i);
    cout << endl;
    cout << "students with a given average score: "; cin >> x;
    cout << endl;
    for (int i = 0; i < 3; i++)
        Find(first, i, x);
    cout << endl;
    cout << "Remov of students without stipend." << endl << endl;
    Scanning(first, last);
    for (int i = 0; i < 3; i++)
        Print(first, i);
    cout << endl;
    return 0;
}

void CreateList(StElem*& first, StElem*& last, int N)
{
    string prizv;
    double averageMark;
    int stipend;
    for (int i = 0; i < N; i++)
    {
        cin.sync();
        cout << "prizv: "; cin >> prizv;
        cout << "averageMark: "; cin >> averageMark;
        {
            cout << "stipend: "; cin >> stipend;
        } while (stipend < 0);
        AddElem(first, last, prizv, averageMark, stipend);
        cout << endl << endl;
    }
}

void AddElem(StElem*& first, StElem*& last, string prizv, double averageMark, int stipend)
{
    StElem* tmp = new StElem;
    tmp->prizv = prizv;
    tmp->averageMark = averageMark;
    tmp->stipend = stipend;
    tmp->next = NULL;
    if (last != NULL)
        last->next = tmp;
    tmp->prev = last;
    last = tmp;
    if (first == NULL)
        first = tmp;
}

void Print(StElem* first, int i)
{
    while (first != NULL)
    {
        if (i == 0)
            cout << "| " << setw(8) << left << first->prizv << " ";
        else if (i == 1)
            cout << "| " << setw(8) << left << first->averageMark << " ";
        else
            cout << "| " << setw(8) << left << first->stipend << " ";

        first = first->next;
    }
    cout << "|" << endl;
}

int Find(StElem* first, int i, double x)
{
    int k = 0;
    while (first != NULL)
    {
        if (first->averageMark == x)
        {
            if (i == 0)
                cout << "| " << setw(8) << left << first->prizv << " ";
            else if (i == 1)
                cout << "| " << setw(8) << left << first->averageMark << " ";
            else
                cout << "| " << setw(8) << left << first->stipend << " ";
            k++;
        }
        first = first->next;
    }
    cout << "|" << endl;
    return k;
}

void DeleteBegElem(StElem*& first, StElem*& last)
{
    StElem* tmp = first->next;
    delete first;
    first = tmp;
}

void DeleteElem(StElem*& first, StElem*& last)
{
    StElem* tmp = first->next->next;
    delete first->next;
    first->next = tmp;
}

void Scanning(StElem* first, StElem* last)
{
    while (first != NULL && first->stipend == 0)
        DeleteBegElem(first, last);
    while (first != NULL && first->next != NULL)
    {
        if (first->next->stipend == 0)
            DeleteElem(first, last);
        else
            first = first->next;
    }
}