#include <iostream>
#include <fstream>
#include <iomanip>
#include <Windows.h>

using namespace std;

struct Price {
	char nameTowar[20];
	char shop[20];
	int coast;
};

void Create(const char* fName);
void Print(const char* fName);
void fWrite(fstream& f, const int i, Price x);
Price fRead(fstream& f, const int i);
void fChange(fstream& f, const int i, const int j);
void Sort(const char* fName);
int shopSearch(const char* fName, char shop[]);



int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	char f[64];
	char g[6] = "g.dat";
	char prizv[64];

	int menuItem;
	do {
		cout << endl << "Оберіть дію: " << endl;
		cout << "[1]  введення даних з клавіатури" << endl;
		cout << "[2]  вивід даних на екран" << endl;
		cout << "[3]  сортувати товари за алфавітом" << endl;
		cout << "[4]  пошук магазина" << endl;
		cout << "[5]  ввести назву файла" << endl;
		cout << "[0]  вихід " << endl << endl;
		cout << "Введіть значення: "; cin >> menuItem;
		switch (menuItem) {
		case 1:
			Create(f);
			break;
		case 2:
			Print(f);
			break;
		case 3:
			Sort(f);
			break;
		case 4:
			char shop[64];
			cout << "Ввведіть магазин, який бажаєте знайти: ";
			cin >> shop;
			shopSearch(f, shop);
			break;
		case 5:
			cout << "Введіть назву файла: "; cin >> f;
			break;
		case 0:
			break;
		default:
			cout << "Ви ввели помилковезначення!" << endl;
		}
	} while (menuItem != 0);



	system("pause");
	cin.get();
	return 0;
}

void Create(const char* fName)
{
	ofstream f(fName, ios::binary);
	Price price;
	char ch;
	int i = 1;
	do {
		cout << "Товар №: " << i++ << ": " << endl;
		cin.ignore();
		cout << "Назва товару: ";
		cin >> price.nameTowar;
		cout << "Назва магазину: ";
		cin >> price.shop;
		cout << "Вартість товару у грн.: "; cin >> price.coast;
		cout << endl;

		cout << endl;
		if (!f.write((char*)&price, sizeof(Price))) {
			cerr << "Error writing file." << endl;
		}
		cout << "Continue?(Y/N)"; cin >> ch;
	} while (ch == 'y' || ch == 'Y');
}



void Print(const char* fName)
{
	cout << "=================================================" << endl;
	cout << "|  №  |    Товар     |     Магазин     |  Ціна  |" << endl;
	cout << "-------------------------------------------------" << endl;

	ifstream f(fName, ios::binary);
	Price price;
	int i = 1;
	while (f.read((char*)&price, sizeof(Price))) {
		cout << "| " << setw(3) << right << i++ 
			<< " | " << setw(12) << left << price.nameTowar
			<< " | " << setw(15) << right << price.shop
			<< " | " << setw(6) << left << price.coast << " |" << endl;

	}
	cout << "=================================================" << endl;
	cout << endl;
}



void fWrite(fstream& f, const int i, Price x) {
	f.seekp(i * (long)sizeof(Price));
	f.write((char*)&x, sizeof(Price));
}

Price fRead(fstream& f, const int i) {
	Price x;
	f.seekg(i * (long)sizeof(Price));
	f.read((char*)&x, sizeof(Price));
	return x;
}

void fChange(fstream& f, const int i, const int j) {
	Price x = fRead(f, i);
	Price y = fRead(f, j);
	fWrite(f, i, y);
	fWrite(f, j, x);
}

void Sort(const char* fName) {
	fstream f(fName, ios::binary | ios::in | ios::out);

	f.seekg(0, ios::end);
	int size = f.tellg() / sizeof(Price);
	f.seekg(0, ios::beg);

	for (int i = 1; i < size; i++) {
		for (int j = 0; j < size - i; j++) {
			Price a = fRead(f, j);
			Price b = fRead(f, j + 1);
			if (strcmp(a.nameTowar, b.nameTowar)==1)
			{
				fChange(f, j, j + 1);
			}
		}
	}


	f.seekp(0, ios::end);
}

int shopSearch(const char* fName, char userStr[]) {
	ifstream f(fName, ios::binary);
	Price price;
	int n = 1;

	cout << "=================================================" << endl;
	cout << "|  №  |    Товар     |     Магазин     |  Ціна  |" << endl;
	cout << "-------------------------------------------------" << endl;

	while (f.read((char*)&price, sizeof(Price))) {
		if (strcmp(price.shop, userStr) == 0) {
			cout << "| " << setw(3) << right << n++ 
				<< " | " << setw(12) << left << price.nameTowar
				<< " | " << setw(15) << right << price.shop
				<< " | " << setw(6) << left << price.coast << " |" << endl;
		}
	}

	cout << "=================================================" << endl;
	cout << endl;

	if (n == 1) {
		cout << endl;
		cout << "Cпівпадінь за введеними даними не знайдено." << endl << endl;
		return -1;
	}
	else {
		return 1;
	}
}