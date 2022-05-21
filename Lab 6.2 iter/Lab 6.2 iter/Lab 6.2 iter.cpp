#include <iostream>
#include <windows.h>
#include <time.h>
#include <iomanip>
using namespace std;

typedef int Info;
struct Elem
{
	Elem* link;
	Info info;
};

void enqueue(Elem*& first, Elem*& last, Info value);
Info dequeue(Elem*& first, Elem*& last);
void Print(Elem* L);
int Reverse(Elem** first);

int main()
{
	Elem* first = NULL,
		* last = NULL;
	
	for (int i = 1; i <= 5; i++)
		enqueue(first, last, i);

	Print(first);
	cout << endl;

	Reverse(&first);

	Print(first);
	cout << endl;
	
	while (first != NULL)
		cout << "delete: " << dequeue(first, last) << endl;
	cout << endl;

	return 0;
}

int Reverse(Elem** first) {
	int n = 0;
	Elem* next = NULL;           //1
	Elem* prev = NULL;			 //2
	Elem* current = (*first);    //3
	while (current != NULL) {    //4
		n += current->info;      
		next = current->link;    //5
		current->link = prev;    //6
		prev = current;          //7
		current = next;          //8
	}
	(*first) = prev;             //9
	return n;
}

void Print(Elem* L)
{
	while (L != NULL)
	{
		cout << L->info << " ";
		L = L->link;
	}
}

void enqueue(Elem*& first, Elem*& last, Info value)
{
	Elem* tmp = new Elem; // 1
	tmp->info = value; // 2
	tmp->link = NULL; // 3
	if (last != NULL)
		last->link = tmp; // 4
	last = tmp; // 5
	if (first == NULL)
		first = tmp; // 6
}

Info dequeue(Elem * &first, Elem * &last)
{
	Elem* tmp = first->link; // 1
	Info value = first->info; // 2
	delete first; // 3
	first = tmp; // 4
	if (first == NULL)
		last = NULL; // 5
	return value; // 6
}