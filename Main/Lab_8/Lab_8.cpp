#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cstring>

using namespace std;
struct Foo{
    char a[50] = "a";
    char b[50] = "a";
    char c[50] = "a";
    char d[50] = "a";
};

int UnicodeAddedLength(const char* str)
{
    int nonLatinCounter = 0;
    while(*str) {
        unsigned char unicode = *str;

        if(unicode <= 127) {
            ++str;
            continue;
        }

        nonLatinCounter += 1;
        if(!*(str + 1)) break;
        str += 2;
    }

    return nonLatinCounter;
}

int Lab_8()
{
    setlocale(LC_ALL, "Ukranian");
    cout << "Проекти пошуку позаземних сигналів"<<endl;
    Foo arr[50];
    arr[0] = {"Рік", "Науковий керівник", "Діаметр антени (м)", "Робоча частота (МГц)"};
    for(int i = 1; i < 4; ++i) {
        cout << "Введіть Рік, Науковий керівник, Діаметр антени (м),Робоча частота (МГц) : " << endl;
        cin >> arr[i].a >> arr[i].b >> arr[i].c >> arr[i].d;
    }

    string separator(64, '_');
    string separator2(64, '-');

    cout << separator << endl;
    for(int i = 0; i < 4; ++i) {
        cout << "| " << left << setw(10 + UnicodeAddedLength(arr[i].a)) << arr[i].a
             << "| " << left << setw(6  + UnicodeAddedLength(arr[i].b)) << arr[i].b
             << "| " << left << setw(17 + UnicodeAddedLength(arr[i].c)) << arr[i].c
             << "|" << endl;

        if(i == 0) cout << separator2 << endl;
    }
    cout << separator2 << endl;
    cout << "Примітка: спостерігалися об'єкти від 2 зірок до кількох галактик"<<endl;

    return 0;
}