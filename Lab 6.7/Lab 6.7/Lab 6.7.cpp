#include <iostream>
#include <windows.h>
#include <iomanip>
#include <string>
using namespace std;

typedef int Info;
struct Train
{
	Train* link;
	Info number;
	Info hour;
	Info minute;
	Info track;
};

void AddElem(Train*& first, Train*& last, Info number, Info hour, Info minute);
void AddNewElem(Train*& first, Train*& last, Info number, Info hour, Info minute, Info track);
Info DeleteElem(Train*& first, Train*& last);
void Print(Train* first);
void CreateList(Train*& first, Train*& last);
void CreateNewList(Train* first, Train* last, Train*& first1, Train*& last1);

int main()
{
	Train* first = NULL,
		* last = NULL;
	Train* first1 = NULL,
		* last1 = NULL;

	CreateList(first, last);

	Print(first);

	CreateNewList(first, last, first1, last1);

	Print(first1);

	while (first != NULL)
		DeleteElem(first, last);
	cout << endl;
	return 0;
}

void AddElem(Train*& first, Train*& last, Info number, Info hour, Info minute)
{
	Train* tmp = new Train; // 1
	tmp->number = number; // 2
	tmp->hour = hour;
	tmp->minute = minute;
	tmp->track = NULL;
	tmp->link = NULL; // 3
	if (last != NULL)
		last->link = tmp; // 4
	last = tmp; // 5
	if (first == NULL)
		first = tmp; // 6
}

void AddNewElem(Train*& first, Train*& last, Info number, Info hour, Info minute, Info track)
{
	Train* tmp = new Train; // 1
	tmp->number = number; // 2
	tmp->hour = hour;
	tmp->minute = minute;
	tmp->track = track;
	tmp->link = NULL; // 3
	if (last != NULL)
		last->link = tmp; // 4
	last = tmp; // 5
	if (first == NULL)
		first = tmp; // 6
}

Info DeleteElem(Train * &first, Train * &last)
{
	Train* tmp = first->link; // 1
	Info value = first->number; // 2
	delete first; // 3
	first = tmp; // 4
	if (first == NULL)
		last = NULL; // 5
	return value; // 6
}

void Print(Train* first)
{
	cout << "===================================" << endl;
	cout << "| " << setw(8) << left << "Number";
	cout << " | " << setw(9) << left << "Time";
	cout << " | " << setw(8) << left << "track" << " |" << endl;
	while (first != NULL)
	{
		cout << "----------------------------------" << endl;
		cout << "| " << setw(8) << first->number;
		cout << " | " << setw(4) << first->hour << ":" << setw(4) << first->minute;
		cout << " | " << setw(8) << first->track << " |" << endl;
		first = first->link;
	}
	cout << "===================================";
}

void CreateList(Train*& first, Train*& last)
{
	char ch;
	int number, hour, minute;
	do
	{
		cout << "enter number train >> "; 
		cin >> number;
		cout << "enter the train arrival time\n";
		cout << "enter hour >>"; 
		cin >> hour;
		cout << "enter minute >>"; 
		cin >> minute;
		AddElem(first, last, number, hour, minute);
		cout << "continue? (y/n): "; cin >> ch;
	} while (ch == 'y' || ch == 'Y');
	cout << endl;
}

void CreateNewList(Train* first, Train* last, Train*& first1, Train*& last1)
{
	int number,
		hourLow, minuteLow, hourHight, minuteHight,
		track;
	cout << endl << endl << endl;
	cout << "enter the lower and upper time limits\n\n";
	cout << "enter the lower time limit:" << endl;
	cout << "enter hour >>";
	cin >> hourLow;
	cout << "enter minute >>";
	cin >> minuteLow;
	cout << endl  << "enter a higher time limit:" << endl;
	cout << "enter hour >>";
	cin >> hourHight;
	cout << "enter minute >>";
	cin >> minuteHight;

	while (first != NULL)
	{
		if(first->hour >= hourLow && first->hour <= hourHight)
			if (first->minute >= minuteLow && first->minute <= minuteHight) {
				number = first->number;
				hourLow = first->hour;
				minuteLow = first->minute;
				cout << "Input track >> "; cin >> track;
				AddNewElem(first1, last1, number, hourLow, minuteLow, track);
			}
		first = first->link;
	}
}
