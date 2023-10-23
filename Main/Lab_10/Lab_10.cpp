#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cstring>

using namespace std;

struct List1 {
    char a[50] = {};
    char b[50] = {};
    char c[50] = {};
    char d[50] = {};
};

int Unicode1(const char* str) {
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

int Lab_10() {
    fstream file;
    file.open("mainLab_10.cpp", ios::out);
    setlocale(LC_ALL, "Ukranian");
    cout << "Проекти пошуку позаземних сигналів" << endl;

         file << "Рік Науковий керівник Діаметр антени (м) Робоча частота (МГц)\n";

    List1 item;
    for (int i = 1; i < 4; ++i) {
        cout << "Введіть Рік, Науковий керівник, Діаметр антени (м), Робоча частота (МГц): " << endl;
        cin >> item.a >> item.b >> item.c >> item.d;
        file << item.a << " " << item.b << " " << item.c << " " << item.d << "\n";
    }
     cout<<"Вивід даних з папки mainLab_10.cpp" <<endl;
    file.close();

    string separator(64, '_');
    string separator2(64, '-');

    cout << separator << endl;

    ifstream readFile("mainLab_10.cpp");
    if (!readFile.is_open()) {
        cerr << "Не вдалося відкрити файл для читання." << endl;
        return 1;
    }

   string line;
    while (getline(readFile, line)) {
        cout << "| " << line << "|" << endl;
        if (line.find("Рік") == 0) {
            cout << separator2 << endl;
        }
    }

    readFile.close();

    cout << "Примітка: спостерігалися об'єкти від 2 зірок до кількох галактик" << endl;
    cout << "_________________________________________________________________"<<endl;
    return 0;
}
