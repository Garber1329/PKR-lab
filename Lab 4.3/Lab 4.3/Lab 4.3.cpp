#include <iostream>
#include <Windows.h>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

struct Store
{
	string store_name;
	string item_name;
	double price;
};

void createAndAdd(const string fname, int optiion);
void print(const string fname);
bool searchForNameStore(const string fname, const string namestore);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	string fname, namest;

	
	int d;
	cout << "Введіть назву файла: "; getline(cin, fname); 
	do
	{
		cout << endl;
		cout << "Виберіть дію" << endl;
		cout << "1) введення даних про товар " << endl;
		cout << "2) поповнення списку " << endl;
		cout << "3) вивід даних на екран " << endl;
		cout << "4) пошук товарів за імям магазину " << endl;
		cout << "0) вихід " << endl << endl;
		cout << "Введіть пункт >> ";
		cin >> d;
		switch (d)
		{
		case 1:
			createAndAdd(fname, 1);
			break;
		case 2:
			createAndAdd(fname, 2);
			break;
		case 3:
			print(fname);
			break;
		case 4:
			cout << "Введіть назву магазину: ";
			cin.get();
			cin.sync();
			getline(cin, namest);
			cout << searchForNameStore(fname, namest);
			break;
		case 0:
			d = 0;
			break;
		default:
			cout << "Такого пункту немає!!!!!" << endl;
			break;

		}

	} while (d != 0);

}

bool searchForNameStore(const string fname, const string namestore)
{
	char ch[60];

	int num = 1;
	ifstream file(fname);
	if (!file.is_open()) {
		cout << "Файл не відкрився!!";
		return false;
	}
	cout << "=============================================================" << endl;
	cout << "| № |  Назва магазину  |  Назва товару  |  Вартість товару  |" << endl;
	cout << "-------------------------------------------------------------" << endl;

	while (!file.eof())
	{
		file.getline(ch, sizeof(ch));

		if (ch == namestore)
		{
			cout << "|" << setw(2) << num++ << setw(2) << "|";

			//file.getline(ch, sizeof(ch));
			cout << setw(9) << ch << setw(10) << "|";

			file.getline(ch, sizeof(ch));
			cout << setw(9) << ch << setw(8) << "|";

			file.getline(ch, sizeof(ch));
			cout << setw(10) << ch << setw(10) << "|"<< endl;
		}
	}
	cout << "=============================================================" << endl;
	if (num > 0)
		return true;
	else
		return false;
}

void print(const string fname)
{
	ifstream file(fname, ios::in);
	string str;
	int count = 0;
	if (!file.is_open())
	{
		cout << "Файл не відкрився !!!";
		return;
	}
	int num = 1;
	char ch[100];
	cout << "=============================================================" << endl;
	cout << "| № |  Назва магазину  |  Назва товару  |  Вартість товару  |" << endl;
	cout << "-------------------------------------------------------------" << endl;

	while (!file.eof())
	{
		getline(file, str);//визначаємо кількість рядків в файлі
		count++;
	}

	file.close();
	file.open(fname, ios::in);
	for (int i = 0; i < count / 3; i++)
	{
		cout << "|" << setw(2) << num++ << setw(2) << "|";

		file.getline(ch, sizeof(ch));
		cout << setw(9) << ch << setw(10) << "|";

		file.getline(ch, sizeof(ch));
		cout << setw(9) << ch << setw(8) << "|";

		file.getline(ch, sizeof(ch));
		cout << setw(10) << ch << setw(10) << "|"<< endl;

	}
	cout << "=============================================================" << endl;
}

void createAndAdd(const string fname, int optiion)
{
	Store store;
	string strt;
	ofstream file;



	switch (optiion)
	{
	case 1:
		file.open(fname, ios::out);
		break;
	case 2:
		file.open(fname, ios::app);
		break;
	}
	if (!file.is_open())
	{
		cout << "Файл не відкрився !!!";
		return;
	}

	cin.get();
	cin.sync();
	do
	{

		cout << endl;
		cout << "Введіть назву магазину: "; getline(cin, store.store_name);
		file << store.store_name << endl;

		cout << "Введіть назву товару: "; getline(cin, store.item_name);
		file << store.item_name << endl;

		cout << "Введіть ціну одиниці товару: "; cin >> store.price;
		file << store.price << endl;

		cin.get();
		cout << "Введіть 'Y' щоб продовжити або 'N' щоб завершити: ";
		getline(cin, strt);

	} while (strt == "Y" || strt == "y");
}