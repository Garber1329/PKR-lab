#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
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
	string s;
	while (getline(fin, s))
	{
		cout << s << endl;
	}
	cout << endl;
}

int testNum(char n) {
	for (int i = 0; i <= 9; i++) {
		if (i == ((int)n - 48)) {
			return true;
		}
	}
	return false;
}

void RoundingTXT(char* fname, char* gname)
{
	ofstream g(gname); 
	string zz;
	ifstream f(fname);

	while (getline(f, zz))
	{
		const char symbol = '.';
		for (int i = 0; i < zz.length(); ++i)
		{
			if (i != 0
				&& testNum(zz[i - 1]) == true
				&& zz[i] == symbol
				&& testNum(zz[i + 1]) == true
				&& testNum(zz[i + 2]) == true
				&& testNum(zz[i + 3]) == true)
			{
				while (!(i != 0
					&& testNum(zz[i - 1]) == true
					&& zz[i] == symbol
					&& testNum(zz[i + 1]) == true
					&& testNum(zz[i + 2]) == true
					&& testNum(zz[i + 3]) == false))
				{

					for (int j = i + 3; j < zz.length(); ++j)
					{
						zz[j] = zz[j + 1];
					}

				}
			}
		}
		
		g << zz << endl;
		
	}
	f.close();
	
}

void Remove(char* fname)
{
	ifstream f(fname);
	ofstream t("TMP.TXT");
	int x;
	while (f >> x) 
		if (x >= 0) 
			t << x << endl; 
	f.close(); 
	t.close();
	remove(fname); 
	rename("TMP.TXT", fname); 
}

int main()
{
	char fname[100];
	cout << "enter file name 1: "; cin >> fname;
	CreateTXT(fname);
	PrintTXT(fname);
	char gname[100];
	cout << "enter file name 2: "; cin >> gname;
	RoundingTXT(fname, gname);
	PrintTXT(gname);
	Remove(fname);
	PrintTXT(fname);
	return 0;
}