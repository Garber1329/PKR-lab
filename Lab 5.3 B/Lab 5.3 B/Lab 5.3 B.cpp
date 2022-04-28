#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <Windows.h>

using namespace std;

enum Specialty { KN, INF, ME, PI, TD };

string specialtyStr[] = { "Комп. науки", "Інформ.", "Матем. та екном.", " Фізика та інф.", "Трудове навчання" };


struct Student {
	char prizv[64];
	unsigned kurs;
	Specialty specialty;
	unsigned physics;
	int maths;
	union {
		unsigned programming;
		unsigned numMethods;
		unsigned pedagogy;
	};
};


void Create(const char* fName);
void Print(const char* fName);
void fWrite(fstream& f, const int i, Student x);
Student fRead(fstream& f, const int i);
void fChange(fstream& f, const int i, const int j);
void Sort(const char* fName);
void indexSort(const char* fName, const char* gName);
void indexPrint(const char* fName, const char* gName);
int binSearch(const char* fName, const char* prizv, const int kurs, const int physics);


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	char f[50];
	char g[6] = "g.dat";
	char prizv[64];
	int kurs, specialty, binNum;

	int menuItem;
	do {
		cout << endl << endl << "Оберіть дію: " << endl;
		cout << "[1]  введення даних з клавіатури." << endl;
		cout << "[2]  вивід даних на екран." << endl;
		cout << "[3]  фізичне впорядкування" << endl;
		cout << "[4]  індексне впорядкування та вивід масиву." << endl;
		cout << "[5]  бінарний пошук" << endl;
		cout << "[6]  ввести назву файла" << endl;
		cout << "[0]  вихід" << endl << endl;
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
			indexSort(f, g);
			indexPrint(f, g);
			break;
		case 5:
			cout << "Перевірка наявності студента за прізвищем, курсом, та оцінкою з фізики." << endl;
			cout << "Введіть прізвище: "; cin >> prizv;
			cout << "Введіть курс: "; cin >> kurs;
			cout << "Спеціальність (0 - Комп'ютерні науки, 1 - Інформатика, 2 - Математика та екноміка, 3 - Фізика та інформатика, 4 - Трудове навчання): " << endl;
			cout << "Введіть спеціальеність: "; cin >> specialty;
			binNum = binSearch(f, prizv, kurs, specialty);
			if (binNum == -1) {
				cout << "Не знайдено студента з такими характеристиками!!!" << endl;
			}
			else {
				cout << "Номер цього студента в списку: " << binNum << endl;
			}
			break;
		case 6:
			cout << "Введіть назву файла: "; cin >> f;
			break;
		case 0:
			break;
		default:
			cout << "Ви ввели помилковезначення! Слід ввести число - номер вибраного пункту меню" << endl;
		}
	} while (menuItem != 0);



	system("pause");
	cin.get();
	return 0;
}

void Create(const char* fName)
{
	ofstream f(fName, ios::binary);
	if (!f.is_open())
	{
		cout << "Файл не відкрився !!!";
		return;
	}
	Student s;
	char ch;
	int specialty;
	do {

		cout << "Прізвище: ";
		cin >> s.prizv;
		cout << "Курс: "; cin >> s.kurs;
		cout << "Спеціальність (0 - Комп'ютерні науки, 1 - Інформатика, 2 - Математика та екноміка, 3 - Фізика та інформатика, 4 - Трудове навчання): ";
		cin >> specialty;
		s.specialty = (Specialty)specialty;
		cout << "Оцінка з фізики: "; cin >> s.physics;
		cout << "Оцінка з математики: "; cin >> s.maths;
		switch (s.specialty) {
		case KN:
			cout << "Оцінка з програмування: "; cin >> s.programming;
			break;
		case INF:
			cout << "Оцінка з чисельних методоів: "; cin >> s.numMethods;
			break;
		default:
			cout << "Оцінка педагогіки: "; cin >> s.pedagogy;
			break;
		}

		cout << endl;
		if (!f.write((char*)&s, sizeof(Student))) {
			cerr << "Error writing file." << endl;
		}
		cout << "Continue?(Y/N)"; cin >> ch;
	} while (ch == 'y' || ch == 'Y');
}



void Print(const char* fName)
{
	cout << endl << "\nfile \"" << fName << "\":\n";
	cout << "===================================================================================================="
		<< endl;
	cout << "| №  |  Прізвище  | Курс |   Спеціальність   | Фізика | Матем. | Програм. | Чис. мет. | Педагогіка |"
		<< endl;
	cout << "===================================================================================================="
		<< endl;
	ifstream f(fName, ios::binary);
	Student s;
	int i = 1;
	while (f.read((char*)&s, sizeof(Student))) {
		cout << "| " << right << i++ 
			<< " | " << setw(11) << left << s.prizv
			<< " | " << setw(4) << right << s.kurs
			<< " | " << setw(17) << left << specialtyStr[s.specialty]
			<< " | " << setw(6) << right << s.physics
			<< " | " << setw(6) << right << s.maths;
		switch (s.specialty) {
		case KN:
			cout << " | " << setw(8) << fixed << right << s.programming
				<< " | " << setw(12) << " | " << setw(12) << " |" << endl;
			break;
		case INF:
			cout << " | " << setw(11)
				<< " | " << right << fixed << setw(9) << s.numMethods << " | " << setw(12) << " |" << endl;
			break;
		default:
			cout << " | " << setw(11)
				<< " | " << setw(12) << " | " << setw(10) << s.pedagogy << " |" << endl;
			break;
		}

	}
	cout << "====================================================================================================" << endl;
	cout << endl;
}


void fWrite(fstream& f, const int i, Student x) {
	f.seekp(i * (long)sizeof(Student));
	f.write((char*)&x, sizeof(Student));
}

Student fRead(fstream& f, const int i) {
	Student x;
	f.seekg(i * (long)sizeof(Student));
	f.read((char*)&x, sizeof(Student));
	return x;
}

void fChange(fstream& f, const int i, const int j) {
	Student x = fRead(f, i);
	Student y = fRead(f, j);
	fWrite(f, i, y);
	fWrite(f, j, x);
}

void Sort(const char* fName) {
	fstream f(fName, ios::binary | ios::in | ios::out);

	f.seekg(0, ios::end);
	int size = f.tellg() / sizeof(Student);
	f.seekg(0, ios::beg);

	for (int i = 1; i < size; i++) {
		for (int j = 0; j < size - i; j++) {
			Student a = fRead(f, j);
			Student b = fRead(f, j + 1);
			if ((a.kurs > b.kurs) ||
				(a.kurs == b.kurs && a.prizv > b.prizv) ||
				(a.kurs == b.kurs && a.prizv == b.prizv && a.specialty > b.specialty)) {
				fChange(f, j, j + 1);
			}
		}
	}


	f.seekp(0, ios::end);
}

void indexSort(const char* fName, const char* gName) {
	fstream g(gName, ios::binary | ios::in | ios::out | ios::trunc);
	fstream f(fName, ios::binary | ios::in | ios::out);

	f.seekg(0, ios::end);
	int size = f.tellg() / sizeof(Student);
	f.seekg(0, ios::beg);

	for (int i = 0; i < size; i++)
		g.write((char*)&i, sizeof(int));
	g.seekg(0, ios::beg);

	int value1, value2, tmp;

	for (int i = 1; i < size; i++) {
		for (int j = 0; j < size - i; j++) {
			;
			g.seekg(j * (long)sizeof(int));
			g.read((char*)&value1, sizeof(int));
			g.read((char*)&value2, sizeof(int));
			Student a = fRead(f, value1);
			Student b = fRead(f, value2);
			if ((a.kurs > b.kurs) ||
				(a.kurs == b.kurs && a.prizv > b.prizv) ||
				(a.kurs == b.kurs && a.prizv == b.prizv && a.specialty > b.specialty)) {
				int tmp1;
				int tmp2;
				g.seekg(j * (long)sizeof(int));
				g.read((char*)&tmp1, sizeof(int));
				g.seekg((j + 1) * (long)sizeof(int));
				g.read((char*)&tmp2, sizeof(int));
				g.seekg(j * (long)sizeof(int));
				g.write((char*)&tmp2, sizeof(int));
				g.seekg((j + 1) * (long)sizeof(int));
				g.write((char*)&tmp1, sizeof(int));
			}
		}
	}

	g.seekg(0, ios::beg);
	f.seekp(0, ios::end);
	f.close();
	g.close();
}

void indexPrint(const char* fName, const char* gName) {
	cout << endl << "\nfile \"" << fName << "\":\n";
	cout << "===================================================================================================="
		<< endl;
	cout << "| №  |  Прізвище  | Курс |   Спеціальність   | Фізика | Матем. | Програм. | Чис. мет. | Педагогіка |"
		<< endl;
	cout << "===================================================================================================="
		<< endl;
	ifstream g(gName, ios::binary);
	fstream f(fName, ios::binary | ios::in | ios::out);
	Student s;

	f.seekg(0, ios::end);
	int size = f.tellg() / sizeof(Student);
	f.seekg(0, ios::beg);

	int ind, i = 1;

	while (g.read((char*)&ind, sizeof(int))) {
		f.seekp(ind * (long)sizeof(Student));
		f.read((char*)&s, sizeof(Student));
		cout << "| " << right << i++
			<< " | " << setw(11) << left << s.prizv
			<< " | " << setw(4) << right << s.kurs
			<< " | " << setw(18) << left << specialtyStr[s.specialty]
			<< " | " << setw(6) << right << s.physics
			<< " | " << setw(6) << right << s.maths;
		switch (s.specialty) {
		case KN:
			cout << " | " << setw(8) << fixed << right << s.programming
				<< " | " << setw(12) << " | " << setw(12) << " |" << endl;
			break;
		case INF:
			cout << " | " << setw(11)
				<< " | " << right << fixed << setw(9) << s.numMethods << " | " << setw(12) << " |" << endl;
			break;
		default:
			cout << " | " << setw(11)
				<< " | " << setw(12) << " | " << setw(10) << s.pedagogy << " |" << endl;
			break;
		}

	}
	cout << "====================================================================================================" << endl;
	cout << endl;
}

int binSearch(const char* fName, const char* prizv, const int kurs, const int specialty) {
	fstream f(fName, ios::binary | ios::in | ios::out);
	int L = 0, m;
	f.seekg(0, ios::end);
	int R = f.tellg() / sizeof(Student);
	f.seekg(0, ios::beg);
	do {
		m = (L + R) / 2;
		Student a = fRead(f, m);
		if (a.specialty == specialty && a.kurs == kurs && strcmp(a.prizv, prizv) == 0) {
			return m + 1;
		}
		else if ((a.kurs > kurs) ||
			(a.kurs == kurs && a.prizv > prizv) ||
			(a.kurs == kurs && a.prizv == prizv && a.specialty > specialty)) {
			R = m - 1;
		}
		else {
			L = m + 1;
		}
	} while (L <= R);
	return -1;
}