#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h> // забезпечення відображення кирилиці
using namespace std;

enum Kurs { I = 1, II, III, IV, V, VI };

string KursStr[] = {
    "I", "II", "III", "IV", "V", "VI"
};

enum Spec { KN, INF, MATHandECONOM, PHandINF, WORK};

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
string highestAverageScore(Student* s, const int N);
double percentageStudentsStudyExcellently(Student* s, const int N);

int main(){
    SetConsoleCP(1251); // встановлення сторінки win-cp1251 в потік вводу
    SetConsoleOutputCP(1251); // встановлення сторінки win-cp1251 в потік виводу

    int N;
    cout << "Введіть N: "; cin >> N;

    Student* s = new Student[N];

    Create(s, N);
    Print(s, N);
    cout << "Найбільший середній бал в студента: " << highestAverageScore(s, N) << endl;
    cout << "Процент студентів, які вчаться на «відмінно»: " << percentageStudentsStudyExcellently(s, N) << endl;

    return 0;
}

void Create(Student* s, const int N){
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
                cout << "Оцінка з програмування:"; cin >> s[i].programming;
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

void Print(Student* s, const int N){
    cout << "==================================================================================================="
        << endl;
    cout << "| № |  Прізвище  | Курс |   Спеціальність   | Фізика | Матем. | Програм. | Чис. мет. | Педагогіка |"
        << endl;
    cout << "---------------------------------------------------------------------------------------------------"
        << endl;
    for (int i = 0; i < N; i++)
    {
        cout << "| "  << right << i + 1 << " ";
        cout << "| " << setw(11) << left << s[i].prizv
            << "| " << setw(4) << right << KursStr[(int)s[i].kurs-1] << " "
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

string highestAverageScore(Student* s, const int N){
    double stud = 0, max=0;
    int index = 0;
    for (int i = 0; i < N; i++) {
        stud = s[i].physics + s[i].maths;
        switch (s[i].spec) {
        case KN:
            stud += s[i].programming;
            break;
        case INF:
            stud += s[i].numMethods;
            break;
        case MATHandECONOM:
        case PHandINF:
        case WORK:
            stud += s[i].pedagogy;
            break;
        }
        if (stud > max) {
            max = stud;
            index = i;
        }
        stud = 0;
    };
   return s[index].prizv;
}

double percentageStudentsStudyExcellently(Student* s, const int N){
    int number = 0;
    double stud = 0;
    for (int i = 0; i < N; i++) {
        stud = s[i].physics + s[i].maths;
        switch (s[i].spec) {
        case KN:
            stud += s[i].programming;
            break;
        case INF:
            stud += s[i].numMethods;
            break;
        case MATHandECONOM:
        case PHandINF:
        case WORK:
            stud += s[i].pedagogy;
            break;
        }
        if (stud/3 == 5) {
            number++;
        }
        stud = 0;
    };
    return (number * 100.0) / N;
}
