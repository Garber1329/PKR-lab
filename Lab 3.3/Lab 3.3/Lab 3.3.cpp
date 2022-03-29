#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <Windows.h> 
using namespace std;

struct Price {
	string nameTowar;
	string shop;
	double cost;
};

void Create(Price* p, const int N);
void Print(Price* p, const int N);
void SaveToFile(Price* p, const int N, const char* filename);
void LoadFromFile(Price*& p, int& N, const char* filename);
void Sort(Price* p, const int N);
int PrintShop(Price* p, const int N, const string nameShop);


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int N;
	cout << "Введіть к-сть товарів: "; cin >> N;
	Price* p = new Price[N];
    char filename[100];
    string nameShop;

    int menuItem;
    do {
        cout << endl;
        cout << "Виберіть дію:" << endl << endl;
        cout << " [1] - введення даних з клавіатури" << endl;
        cout << " [2] - вивід даних на екран" << endl;
        cout << " [3] - сортування даних за алфавітом" << endl;
        cout << " [4] - вивід товарів, що продаються в магазині" << endl;
        cout << " [7] - запис даних у файл" << endl;
        cout << " [8] - зчитування даних із файлу" << endl;
        cout << " [0] - вихід та завершення роботи програми" << endl << endl;
        cout << "Введіть значення: "; cin >> menuItem;
        cout << endl;
        switch (menuItem)
        {
        case 1:
            Create(p, N);
            break;
        case 2:
            Print(p, N);
            break;
        case 3:
            Sort(p, N);
            break;
        case 4:
            cin.get();
            cin.sync();

            cout << "Назва магазину: "; getline(cin, nameShop);
            PrintShop(p, N, nameShop);
            break;
        case 7:
            cin.get(); 
            cin.sync(); 

            cout << "Введіть ім'я файлу: "; cin.getline(filename, 99);
            SaveToFile(p, N, filename);
            break;
        case 8:
            cin.get(); 
            cin.sync(); 

            cout << "Введіть ім'я файлу: "; cin.getline(filename, 99);
            LoadFromFile(p, N, filename);
            break;
        case 0:
            break;
        default:
            cout << "Ви ввели помилкове значення! "
                "Слід ввести число - номер вибраного пункту меню" << endl;
        }
    } while (menuItem != 0);

    return 0;
}

void Create(Price* p, const int N)
{
    for (int i = 0; i < N; i++) {
        cout << "Товар № " << i + 1 << ":" << endl;
        cout << "Назва товару: "; cin >> p[i].nameTowar;
        cout << "Назва магазину: "; cin >> p[i].shop;
        cout << "Вартість товару у грн.: "; cin >> p[i].cost;
        cout << endl;
    }
}

void Print(Price* p, const int N)
{
    cout << "============================================================="
        << endl;
    cout << "|  №  |   Назва товару   |   Назва магазину  |   Вартість   |"
        << endl;
    cout << "============================================================="
        << endl;
     
    for (int i = 0; i < N; i++)
    {
        cout << "| " << setw(3) << right << i + 1
            << " | " << setw(16) << left << p[i].nameTowar
            << " | " << setw(17) << left << p[i].shop
            << " | " << setw(12) << right << setprecision(2) << p[i].cost << " |";
        cout << endl;
        cout << "-------------------------------------------------------------";
        cout << endl;
    }
}

void SaveToFile(Price* p, const int N, const char* filename)
{
    ofstream fout(filename, ios::binary); // відкрили бінарний файл запису
    fout.write((char*)&N, sizeof(N)); // записали кількість елементів
    for (int i = 0; i < N; i++)
        fout.write((char*)&p[i], sizeof(Price)); // записали елементи масиву
    fout.close();
}

void LoadFromFile(Price*& p, int& N, const char* filename)
{
    delete[] p; // знищили попередні дані
    ifstream fin(filename, ios::binary); // відкрили бінарний файл зчитування
    fin.read((char*)&N, sizeof(N)); // прочитали кількість елементів
    p = new Price[N]; // створили динамічний масив
    for (int i = 0; i < N; i++)
        fin.read((char*)&p[i], sizeof(Price)); // прочитали елементи масиву
    fin.close();
}

void Sort(Price* p, const int N)
{
    Price tmp;
    for (int i = 0; i < N - 1; i++)
        for (int j = 0; j < N - i - 1; j++)
            if (p[j].nameTowar > p[j + 1].nameTowar) {
                tmp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = tmp;
            }
}

int PrintShop(Price* p, const int N, const string nameShop)
{
    int stan = 0;
    for (int i = 0; i < N; i++) {
        if (p[i].shop == nameShop) {
            stan = 1;
            break;
        }
        else if(i == N-1){
            stan = -1;
            cout << "Такого магазину немає" << endl;
        }
    }

    if (stan == 1){
        cout << "============================================================="
            << endl;
        cout << "|  №  |   Назва товару   |   Назва магазину  |   Вартість   |"
            << endl;
        cout << "============================================================="
            << endl;

        for (int i = 0; i < N; i++)
        {
            if (p[i].shop == nameShop) {
                cout << "| " << setw(3) << right << i + 1
                    << " | " << setw(16) << left << p[i].nameTowar
                    << " | " << setw(17) << left << p[i].shop
                    << " | " << setw(12) << right << setprecision(2) << p[i].cost << " |";
                cout << endl;
                cout << "-------------------------------------------------------------";
                cout << endl;
            }
            
        }
    }
    return stan;
}
