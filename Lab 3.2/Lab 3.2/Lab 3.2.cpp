#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h> // забезпечення відображення кирилиці
using namespace std;

enum Kurs { I = 1, II, III, IV, V, VI };

string KursStr[] = {
    "I", "II", "III", "IV", "V", "VI"
};

enum Spec { KN, INF, MATHandECONOM, PHandINF, WORK };

string SpecStr[] = {
    "Комп.і науки",
    "Інформ.",
    "Матем. та еконо.",
    "Фіз. та інформ.",
    "Труд. навчання"
};

struct Student {
    string prizv;
    Kurs kurs;
    Spec spec;
    int physics, maths;
    union {
        int programming;
        int numMethods;
        int pedagogy;
    };
};

void Create(Student* s, const int N);
void Print(Student* s, const int N);
void Sort(Student* s, const int N);
int BinSearch(Student* s, const int N, const string prizv, const unsigned kurs, const Spec spec);
int* IndexSort(Student* s, const int N);
void PrintIndexSorted(Student* s, int* I, const int N);

int main() {
    SetConsoleCP(1251); // встановлення сторінки win-cp1251 в потік вводу
    SetConsoleOutputCP(1251); // встановлення сторінки win-cp1251 в потік виводу

    int N;
    cout << "Введіть N: "; cin >> N;

    Student* s = new Student[N];

    int ispec, found, kurs;
    Spec spec;
    string prizv;

    int menuItem;
    do {
        cout << endl << endl << endl;
        cout << "Виберіть дію:" << endl << endl;
        cout << " [1] - введення даних з клавіатури" << endl;
        cout << " [2] - вивід даних на екран" << endl;
        cout << " [3] - фізичне впорядкування даних" << endl;
        cout << " [4] - бінарний пошук студент за прізвищем, курсом і спеціальністю" << endl;
        cout << " [5] - індексне впорядкування та вивід даних" << endl;
        cout << " [0] - вихід та завершення роботи програми" << endl << endl;
        cout << "Введіть значення: "; cin >> menuItem;
        cout << endl << endl << endl;
        switch (menuItem)
        {
        case 1:
            Create(s, N);
            break;
        case 2:
            Print(s, N);
            break;
        case 3:
            Sort(s, N);
            break;
        case 4:
            cout << "Введіть ключі пошуку:" << endl;
            cout << " прізвище: "; cin >> prizv;
            cout << " курс: "; cin >> kurs;
            cout << "Спеціальність:0 - Комп’ютерні науки, 1 - Інформатика, \n 2 - Математика та економіка, 3 - Фізика та інформатика, 4 - Трудове навчання"
            << endl << "Введіть спеціальність: ";
            cin >> ispec;
            spec = (Spec)ispec;
            if ((found = BinSearch(s, N, prizv, kurs, spec)) != -1)
                cout << "Знайдено працівника в позиції " << found + 1 << endl;
            else
                cout << "Шуканого працівника не знайдено" << endl;
            break;
        case 5:
            PrintIndexSorted(s, IndexSort(s, N), N);
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

void Create(Student* s, const int N) {
    int kurs, spec;
    for (int i = 0; i < N; i++) {
        cout << "Студент № " << i + 1 << ":" << endl;
        cout << "Прізвище: "; cin >> s[i].prizv;
        cout << "Курс: "; cin >> kurs;
        s[i].kurs = (Kurs)kurs;
        cout << "Спеціальність: 0 - Комп’ютерні науки,  1 - Інформатика, \n 2 - Математика та економіка, 3 - Фізика та інформатика, 4 - Трудове навчання"
            << endl << "Введіть спеціальність: ";
        cin >> spec;        s[i].spec = (Spec)spec;
        cout << "Оцінка з фізики: "; cin >> s[i].physics;
        cout << "Оцінка з математики: "; cin >> s[i].maths;
        switch (s[i].spec) {
        case KN:
            cout << "Оцінка з програмування: "; cin >> s[i].programming;
            break;
        case INF:
            cout << "Оцінка з чисельних методів:"; cin >> s[i].numMethods;
            break;
        case MATHandECONOM:
        case PHandINF:
        case WORK:
            cout << "Оцінка з педагогіки:"; cin >> s[i].pedagogy;
            break;
        }
        cout << endl;
    }
}

void Print(Student* s, const int N) {
    cout << "==================================================================================================="
        << endl;
    cout << "| № |  Прізвище  | Курс |   Спеціальність   | Фізика | Матем. | Програм. | Чис. мет. | Педагогіка |"
        << endl;
    cout << "---------------------------------------------------------------------------------------------------"
        << endl;
    for (int i = 0; i < N; i++)
    {
        cout << "| " << right << i + 1 << " ";
        cout << "| " << setw(11) << left << s[i].prizv
            << "| " << setw(4) << right << KursStr[(int)s[i].kurs - 1] << " "
            << "| " << setw(18) << left << SpecStr[s[i].spec]
            << "| " << setw(6) << right << s[i].physics << " "
            << "| " << setw(6) << right << s[i].maths << " ";
        switch (s[i].spec) {
        case KN:
            cout << "| " << setw(8) << right
                << s[i].programming << " | " << setw(12) << right
                << " | " << setw(12) << right << " |" << endl;
            break;
        case INF:
            cout << "| " << setw(11) << right
                << " | " << setw(9) << right << s[i].numMethods
                << " | " << setw(12) << right << " |" << endl;
            break;
        case MATHandECONOM:
        case PHandINF:
        case WORK:
            cout << "| " << setw(11) << right
                << " | " << setw(12) << right
                << " | " << setw(10) << right << s[i].pedagogy << " |" << endl;
            break;
        }
    }
    cout << "===================================================================================================" << endl;
    cout << endl;
}

void Sort(Student* s, const int N){
    Student tmp;
    for (int i0 = 0; i0 < N - 1; i0++) // метод "бульбашки"
        for (int i1 = 0; i1 < N - i0 - 1; i1++)
            if ((s[i1].kurs > s[i1 + 1].kurs)
                ||
                (s[i1].kurs == s[i1 + 1].kurs &&
                    s[i1].prizv > s[i1 + 1].prizv)
                ||
                (s[i1].kurs == s[i1 + 1].kurs &&
                    s[i1].prizv == s[i1 + 1].prizv &&
                        s[i1].spec > s[i1 + 1].spec))
            {
                tmp = s[i1];
                s[i1] = s[i1 + 1];
                s[i1 + 1] = tmp;
            }
}

int BinSearch(Student* p, const int N, const string prizv, const unsigned kurs, const Spec spec)
{ // повертає індекс знайденого елемента або -1, якщо шуканий елемент відсутній 
    int L = 0, R = N - 1, m;
    do {
        m = (L + R) / 2;
        if (p[m].prizv == prizv && p[m].kurs == kurs && p[m].spec == spec)
            return m;
        if ((p[m].kurs < kurs)
            ||
            (p[m].kurs == kurs &&
                p[m].prizv < prizv)
            ||
            (p[m].kurs == kurs &&
                p[m].prizv == prizv &&
                p[m].spec < spec))
        {
            L = m + 1;
        }
        else
        {
            R = m - 1;
        }
    } while (L <= R);
    return -1;
}

int* IndexSort(Student* s, const int N){
    int* I = new int[N]; // створили індексний масив
    for (int i = 0; i < N; i++)
        I[i] = i; // заповнили його початковими даними
    int i, j, value; // починаємо сортувати масив індексів
    for (i = 1; i < N; i++)
    {
        value = I[i];
        for (j = i - 1;
            j >= 0 && ((s[I[j]].kurs > s[value].kurs)
                ||
                (s[I[j]].kurs == s[value].kurs &&
                    s[I[j]].prizv > s[value].prizv)
                ||
                (s[I[j]].kurs == s[value].kurs &&
                    s[I[j]].prizv == s[value].prizv &&
                        s[I[j]].spec > s[value].spec) );
        j--)
        {
            I[j + 1] = I[j];
        }
        I[j + 1] = value;
    }
    return I;
}

void PrintIndexSorted(Student* s, int* I, const int N){
    cout << "==================================================================================================="
        << endl;
    cout << "| № |  Прізвище  | Курс |   Спеціальність   | Фізика | Матем. | Програм. | Чис. мет. | Педагогіка |"
        << endl;
    cout << "---------------------------------------------------------------------------------------------------"
        << endl;
    for (int i = 0; i < N; i++)
    {
        cout << "| " << right << i + 1 << " ";
        cout << "| " << setw(11) << left << s[I[i]].prizv
            << "| " << setw(4) << right << KursStr[(int)s[I[i]].kurs - 1] << " "
            << "| " << setw(18) << left << SpecStr[s[I[i]].spec]
            << "| " << setw(6) << right << s[I[i]].physics << " "
            << "| " << setw(6) << right << s[I[i]].maths << " ";
        switch (s[I[i]].spec) {
        case KN:
            cout << "| " << setw(8) << right
                << s[I[i]].programming << " | " << setw(12) << right
                << " | " << setw(12) << right << " |" << endl;
            break;
        case INF:
            cout << "| " << setw(11) << right
                << " | " << setw(9) << right << s[I[i]].numMethods
                << " | " << setw(12) << right << " |" << endl;
            break;
        case MATHandECONOM:
        case PHandINF:
        case WORK:
            cout << "| " << setw(11) << right
                << " | " << setw(12) << right
                << " | " << setw(10) << right << s[I[i]].pedagogy << " |" << endl;
            break;
        }
    }
    cout << "===================================================================================================" << endl;
    cout << endl;
}
