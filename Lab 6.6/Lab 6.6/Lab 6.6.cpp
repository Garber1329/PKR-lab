#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

typedef string Info;
struct Elem
{
	Elem* link;
	Info info;
};

void enqueue(Elem*& first, Elem*& last, Info value);
Info dequeue(Elem*& first, Elem*& last);
void readTXT(Elem*& first, Elem*& last, Elem*& first1, Elem*& last1);
void print(Elem* L);
bool toCompare(Elem* a, Elem* b);
void unificationOfQueues(Elem* first, Elem* first1, Elem*& first2, Elem*& last2);

int main()
{
	Elem* first = NULL,
		* last = NULL;
	Elem* first1 = NULL,
		* last1 = NULL;
	Elem* first2 = NULL,
		* last2 = NULL;

	readTXT(first, last, first1, last1);

	cout << endl << "enqueue 0:" << endl;
	print(first);
	cout << endl << "enqueue 1:" << endl;
	print(first1);

	if (toCompare(first, first1) == 1) {
		cout << endl << "dequeue 1:" << endl;
		while (first1 != NULL)
			cout << dequeue(first1, last1) << " ";
		cout << endl;
	}
	else
	{
		unificationOfQueues(first, first1, first2, last2);
	}

	cout << endl << "enqueue 2:" << endl;
	print(first2);
	
	return 0;
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

void readTXT(Elem*& first, Elem*& last, Elem*& first1, Elem*& last1)
{
	ifstream f("symbols.txt"); 
	string symbol, ss; 
	int i = 1;
	
	while (getline(f, symbol))
	{
		istringstream iss(symbol);
		if (i % 2 == 0) {
			while (iss >> ss) {
				enqueue(first, last, ss);
			}
		}
		else
		{
			while (iss >> ss) {
				enqueue(first1, last1, ss);
			}
		}
		i++;
	}
}

void print(Elem* L)
{
	while (L != NULL)
	{
		cout << L->info << " ";
		L = L->link;
	}
	cout << endl;
}

bool toCompare(Elem* a, Elem* b)
{
	while (a != NULL && b != NULL)
	{
		if (a->info != b->info)
			return false;

		a = a->link;
		b = b->link;
	}

	return (a == NULL && b == NULL);
}

void unificationOfQueues(Elem* first, Elem* first1, Elem*& first2, Elem*& last2)
{
	string s;
	while (first != NULL)
	{
		s = first->info;
		enqueue(first2, last2, s);
		first = first->link;
	}
	while (first1 != NULL)
	{
		s = first1->info;
		enqueue(first2, last2, s);
		first1 = first1->link;
	}
}