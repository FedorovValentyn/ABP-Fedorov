#include <iostream>
#include <iomanip>
#include <string>
#include <list>
#include <cstring>

using namespace std;

struct Foo {
    char a[50] = "a";
    char b[50] = "a";
    char c[50] = "a";
    char d[50] = "a";
};

int UnicodeAdded(const char* str) {
    int nonLatinCounter = 0;
    while (*str) {
        unsigned char unicode = *str;

        if (unicode <= 127) {
            ++str;
            continue;
        }

        nonLatinCounter += 1;
        if (!*(str + 1)) break;
        str += 2;
    }

    return nonLatinCounter;
}

int Lab_9() {
    setlocale(LC_ALL, "Ukranian");
    cout << "Проекти пошуку позаземних сигналів" << endl;

    list<Foo> arr;
    arr.push_back({"Рік", "Науковий керівник", "Діаметр антени (м)", "Робоча частота (МГц)"});

    for (int i = 1; i < 4; ++i) {
        Foo item;
        cout << "Введіть Рік, Науковий керівник, Діаметр антени (м), Робоча частота (МГц): " << endl;
        cin >> item.a >> item.b >> item.c >> item.d;
        arr.push_back(item);
    }

    string separator(64, '_');
    string separator2(64, '-');

    cout << separator << endl;

    for (const Foo& item : arr) {
        cout << "| " << left << setw(20 + UnicodeAdded(item.a)) << item.a
             << "| " << left << setw(20 + UnicodeAdded(item.b)) << item.b
             << "| " << left << setw(20 + UnicodeAdded(item.c)) << item.c
             << "|" << endl;
        cout << separator2 << endl;
    }

    cout << "Примітка: спостерігалися об'єкти від 2 зірок до кількох галактик" << endl;
    cout << "_________________________________________________________________"<<endl;
    return 0;
}

