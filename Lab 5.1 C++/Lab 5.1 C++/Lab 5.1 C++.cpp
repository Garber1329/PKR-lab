#include <iostream>
#include <fstream>
#include <time.h>
using namespace std;

void Create(const char* fName);
void Print(const char* fName);
int Process(const char* fName, const char* gName);

int main()
{
	Create("f.dat");
	Print("f.dat");
	Process("f.dat", "g.dat");
	Print("g.dat");
	return 0;
}

void Create(const char* fName)
{
	char ch;
	ofstream f(fName, ios::binary);

	int x;
	do
	{
		cout << "Input number >> ";
		cin >> x;
		f.write((char*)&x, sizeof(x));
		cout << "continue? (y/n): "; cin >> ch;
	} while (ch == 'y' || ch == 'Y');
}

void Print(const char* fName)
{
	cout << endl << "\nfile \"" << fName << "\":\n";
	ifstream f(fName, ios::binary);
	int x;
	while (f.read((char*)&x, sizeof(x)))
		cout << x << endl;
	cout << endl;
}

int Process(const char* fName, const char* gName)
{
	ifstream f(fName, ios::binary);
	ofstream g(gName, ios::binary);
	int x, n = 0;
	while (f.read((char*)&x, sizeof(x)))

		if (x % 2 == 1) {
			n += x;
			g.write((char*)&n, sizeof(n));
		}
	return n;
}