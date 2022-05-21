#include <iostream>
#include <fstream>
#include <Windows.h>
using namespace std;

typedef string Info;
struct Elem
{
	Elem* link;
	Info info;
};

void push(Elem*& top, Info value);
Info pop(Elem*& top);
void readTXT(Elem*& top);
void print(Elem* top);
int count(Elem* top);
void DivideSteck(Elem* top, Elem*& top1, Elem*& top2, int value);

int main()
{
	Elem* top = NULL,
		* top1 = NULL,
		* top2 = NULL;

	readTXT(top);

	int value = count(top);

	DivideSteck(top, top1, top2, value);

	cout << "top1" << endl;
	print(top1);
	cout << "top2" << endl;
	print(top2);

	cout << "delete" << endl;
	while (top != NULL) {
		cout << pop(top) << " ";
	}
	cout << endl;
	return 0;
}

void push(Elem*& top, Info value)
{
	Elem* tmp = new Elem; // 1
	tmp->info = value; // 2
	tmp->link = top; // 3
	top = tmp; // 4
}

Info pop(Elem*& top)
{
	Elem* tmp = top->link; // 1
	Info value = top->info; // 2
	delete top; // 3
	top = tmp; // 4
	return value; // 5
}

void readTXT(Elem*& top)
{
	ifstream f("symbols.txt"); 
	string element;
	if (!f.eof()) { 
		f >> element;
		push(top, element);
	}
	while (!f.eof()) { 
		f >> element;
		push(top, element);
	}
}

void print(Elem* top)
{
	while (top != NULL)
	{
		cout << top->info << " ";
		top = top->link;
	}
	cout << endl;
}

int count(Elem* top)
{
	int value = 0;
	while (top != NULL)
	{
		value++;
		top = top->link;
	}
	return value;
}

void DivideSteck(Elem* top, Elem*& top1, Elem*& top2, int value)
{
	int k = 0;

	if (value % 2 == 0) 
	{
		while (top != NULL)
		{
			if (value / 2 > k) {
				push(top1, top->info);
				top = top->link;
				k++;
			} 
			else
			{
				push(top2, top->info);
				top = top->link;
			}
		}
	}
	else 
	{
		while (top != NULL)
		{
			push(top1, top->info);
			top = top->link;
		}
	}
	
}
