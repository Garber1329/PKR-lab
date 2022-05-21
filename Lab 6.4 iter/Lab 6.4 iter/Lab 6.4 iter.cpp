#include <iostream>
#include <iomanip>
using namespace std;

typedef int Info;
struct Elem
{
	Elem* link;
	Info info;
};

void Insert(Elem*& L, Info value)
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

Info Remove(Elem*& L)
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

	return value; // 8 }
}

void insertAfter(Elem*& L, Info value)
{
	Elem* tmp = new Elem; // 1
	tmp->info = value; // 2
	tmp->link = L->link; // 3
	L->link = tmp;
}

int Count(Elem * L) 
{
	if (L == NULL)
		return 0;
	Elem* first = L;
	int k = 1;
	while (L->link != first)
	{
		k++;
		L = L->link;
	}
	return k;
}

void Print(Elem * L) 
{
	if (L == NULL)
		return;

	Elem* first = L;
	cout << setw(4) << L->info;
	while (L->link != first)
	{
		L = L->link;
		cout << setw(4) << L->info;
	}
	cout << endl;
}

int main()
{
	Elem* first = NULL;

	for(int i = 1; i <= 5; i++)
		Insert(first, i);
	
	
	cout << "Print first: " << endl;
	Print(first);

	insertAfter(first, 7);


	cout << "Print first: " << endl;
	Print(first);

	while (first != NULL)
		cout << "Remove first: " << Remove(first) << endl;
	cout << endl;

	return 0;
}