#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <Windows.h>

using namespace std;

enum Specialty { KN, INF, ME, PI, TD };

string specialtyStr[] = { "Комп'ютерні науки", "Інформатика", "Матема. та екн.", " Фізика та інфорю", "Трудове навчання" };

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

void Create(const char* fName)
{
	ofstream f(fName, ios::binary);
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
	cout << "====================================================================================================="
		<< endl;
	cout << "| №  |  Прізвище   | Курс |   Спеціальність   | Фізика | Матем. | Програм. | Чис. мет. | Педагогіка |"
		<< endl;
	cout << "====================================================================================================="
		<< endl;

	ifstream f(fName, ios::binary);
	Student s;
	int i = 1;
	while (f.read((char*)&s, sizeof(Student))) {
		cout << "| " << setw(2) << right << i++;
		cout << " | " << setw(11) << left << s.prizv
			<< " | " << setw(4) << right << s.kurs
			<< " | " << setw(17) << left << specialtyStr[s.specialty]
			<< " | " << setw(6) << right << s.physics
			<< " | " << setw(6) << right << s.maths;
		switch (s.specialty) {
		case KN:
			cout << " | " << setw(8) << fixed << right << s.programming
				<< " | " << setw(12) << " | " << setw(12) << "|" << endl;
			break;
		case INF:
			cout << " | " << setw(11)
				<< " | " << right << fixed << setw(9) << s.numMethods << " | " << setw(13) << " | " << endl;
			break;
		default:
			cout << " | " << setw(11)
				<< " | " << setw(12) << " | " << setw(10) << s.pedagogy << " |" << endl;
			break;
		}

	}
	cout << "=====================================================================================================" << endl;
	cout << endl;
}

string highestAverageScore(const char* fName) {
	ifstream f(fName, ios::binary);
	Student s;
	double stud = 0, max = 0;
	string prizv;
	if (!f)
	{
		cerr << "Error writing file '" << fName << "'" << endl;
		return 0;
	}

	while (f.read((char*)&s, sizeof(Student))) {

		stud = s.physics + s.maths + s.programming;
		if (stud > max) {
			max = stud;
			prizv = s.prizv;
		}
		stud = 0;
	}
	return prizv;
}

double percentageStudentsStudyExcellently(const char* fName) {
	ifstream f(fName, ios::binary);
	Student s;
	int number = 0, N=0;
	double stud = 0;

	if (!f)
	{
		cerr << "Error writing file '" << fName << "'" << endl;
		return 0;
	}

	while (f.read((char*)&s, sizeof(Student))) {
		stud = s.physics + s.maths + s.programming;
		if (stud / 3 == 5) {
			number++;
		}
		stud = 0;
		N++;
	}

	return (number * 100.0) / N;
}


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	char fname[6] = "f.dat";

	int menuItem;

	do
	{
		cout << endl << endl;
		cout << "Виберіть дію:" << endl << endl;
		cout << " [1] - ввести дані у файл" << endl;
		cout << " [2] - вивести дані на екран" << endl;
		cout << " [3] - студент з найбільшим середнім балом" << endl;
		cout << " [4] - Процент студентів, які вчаться на «відмінно»" << endl;
		cout << " [0] - вихід" << endl << endl;
		cout << "Введіть значення: "; cin >> menuItem;
		cout << endl << endl;
		switch (menuItem)
		{
		case 1:
			cin.get(); // очищуємо буфер клавіатури – щоб не було символу
			cin.sync(); // "кінець рядка", який залишився після вводу числа
			Create(fname);
			break;
		case 2:
			Print(fname);
			break;
		case 3:
			cout << "Найбільший середній бал в студента: " << highestAverageScore(fname) << endl;
			break;
		case 4:
			cout << "Процент студентів, які вчаться на «відмінно»: " << percentageStudentsStudyExcellently(fname) << endl;
			break;
		case 0:
			break;
		default:
			cout << "Ви ввели помилкове значення! "<< endl;
		}
	} while (menuItem != 0);

	system("pause");
	cin.get();
	return 0;
}