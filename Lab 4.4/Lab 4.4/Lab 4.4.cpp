#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <stack>
#include <Windows.h>
using namespace std;

void CreateTXT(char* fname)
{
	ofstream fout(fname);
	char ch;
	string s;
	do
	{
		cin.get();
		cin.sync();
		cout << "enter line: "; getline(cin, s);
		fout << s << endl;
		cout << "continue? (y/n): "; cin >> ch;
	} while (ch == 'y' || ch == 'Y');
	cout << endl;
}

void PrintTXT(char* fname)
{
	ifstream fin(fname);
	string s; int i = 1;
	while (getline(fin, s))
	{
		cout << i << ") " << s << endl;
		i++;
	}
	cout << endl;
}

int ProcessTXT1(char* fname)
{
	ifstream fin(fname);
	string s;
	int k = 1;
	stack<char> stack;
	while (getline(fin, s))
	{	
		for (int i = 0; i < s.length(); i++) {
			switch (s[i]) {
			case '{': 
				stack.push('}');
				cout << "Line " << k << " Index " << i << " " << s[i] << endl;
				break;
			case '}':
				if (stack.empty() || stack.top() != s[i]) {
					return false;
				}
				cout << "Line " << k << " Index " << i << " " << s[i] << endl;
				stack.pop();
				break;
			default:
				break;
			}
		}
		k++;
	}

	return stack.empty();
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int d;
	char fname[100];
	cout << "Введіть назву файлу: (.txt)"; cin >> fname;

	do
	{
		cout << endl;
		cout << "Виберіть дію" << endl;
		cout << "1) створити файл " << endl;
		cout << "2) пошук фігурних дужок " << endl;
		cout << "3) вивід файлу на екран " << endl;
		cout << "0) вихід " << endl << endl;
		cout << "Введіть пункт >> ";
		cin >> d;
		switch (d)
		{
		case 1:
			CreateTXT(fname);
			break;
		case 2:
			if (ProcessTXT1(fname) == 1)
				cout << "Помилок не знайдено" << endl;
			else 
				 cout << "Відсутня фігурна дужка" << endl;
			break;
		case 3:
			PrintTXT(fname);
			break;
		case 0:
			d = 0;
			break;
		default:
			cout << "Такого пункту немає!!!!!" << endl;
			break;

		}

	} while (d != 0);

	return 0;
}