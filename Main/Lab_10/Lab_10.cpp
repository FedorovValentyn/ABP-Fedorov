#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cstring>

using namespace std;

struct Lust {
    char a[50];
    char b[50];
    char c[50];
    char d[50];
};

int Unicode(const char* str) {
    return strlen(str);
}

void DisplayTable(Lust* table, int size) {
    string separator(64, '_');
    string separator2(64, '-');

    cout << separator << endl;
    cout << "| " << left << setw(10) << "Рік"
         << "| " << left << setw(6) << "Наук. керівник"
         << "| " << left << setw(17) << "Діаметр антени (м)"
         << "| " << left << setw(14) << "Робоча частота (МГц)"
         << "|" << endl;

    cout << separator2 << endl;

    for (int i = 0; i < size; ++i) {
        cout << "| " << left << setw(10 + UnicodeAddedLength(table[i].a)) << table[i].a
             << "| " << left << setw(6 + UnicodeAddedLength(table[i].b)) << table[i].b
             << "| " << left << setw(17 + UnicodeAddedLength(table[i].c)) << table[i].c
             << "| " << left << setw(14 + UnicodeAddedLength(table[i].d)) << table[i].d
             << "|" << endl;

        cout << separator2 << endl;
    }
}

void AddRecord(Lust* table, int& recordCount, const Lust& newRecord) {
    if (recordCount < 50) {
        table[recordCount] = newRecord;
        recordCount++;
        cout << "Новий запис додано." << endl;
    } else {
        cout << "Досягнуто максимальну кількість записів." << endl;
    }
}

void DeleteRecord(Lust* table, int& recordCount, int indexToDelete) {
    if (indexToDelete >= 0 && indexToDelete < recordCount) {
        for (int i = indexToDelete; i < recordCount - 1; ++i) {
            table[i] = table[i + 1];
        }
        recordCount--;
        cout << "Рядок видалено." << endl;
    } else {
        cout << "Некоректний індекс рядка для видалення." << endl;
    }
}

int Lab_10() {
    setlocale(LC_ALL, "Ukranian");
    cout << "Проекти пошуку позаземних сигналів" << endl;

    const int maxRecords = 50;
    Lust table[maxRecords];
    int recordCount = 0;

    ifstream inputFile("mainLab_10.cpp");

    if (!inputFile) {
        cerr << "Помилка відкриття файлу 'mainLab_10.cpp'." << endl;
        return 1;
    }

    Lust record;

    while (inputFile.getline(record.a, 50) &&
           inputFile.getline(record.b, 50) &&
           inputFile.getline(record.c, 50) &&
           inputFile.getline(record.d, 50)) {
        AddRecord(table, recordCount, record);
    }

    inputFile.close();

    int choice;

    while (true) {
        cout << "Оберіть опцію:" << endl;
        cout << "1. Вивести таблицю" << endl;
        cout << "2. Додати рядок" << endl;
        cout << "3. Видалити рядок" << endl;
        cout << "4. Вийти" << endl;
        cout << "Ваш вибір: ";
        cin >> choice;

        if (choice == 1) {
            DisplayTable(table, recordCount);
        } else if (choice == 2) {
            Lust newRecord;
            cout << "Введіть новий запис:" << endl;
            cout << "Рік: ";
            cin.ignore();
            cin.getline(newRecord.a, 50);
            cout << "Науковий керівник: ";
            cin.getline(newRecord.b, 50);
            cout << "Діаметр антени (м): ";
            cin.getline(newRecord.c, 50);
            cout << "Робоча частота (МГц): ";
            cin.getline(newRecord.d, 50);
            AddRecord(table, recordCount, newRecord);
        } else if (choice == 3) {
            int indexToDelete;
            cout << "Введіть індекс рядка, який ви хочете видалити: ";
            cin >> indexToDelete;
            DeleteRecord(table, recordCount, indexToDelete);
        } else if (choice == 4) {
            break;
        } else {
            cout << "Некоректний вибір опції. Спробуйте ще раз." << endl;
        }
    }

    // Відкриття файлу для запису
    ofstream outputFile("mainLab_10.cpp");
    if (!outputFile) {
        cerr << "Помилка відкриття файлу для запису." << endl;
        return 1;
    }

    // Запис у файл
    for (int i = 0; i < recordCount; ++i) {
        outputFile << table[i].a << '\n' << table[i].b << '\n' << table[i].c << '\n' << table[i].d << '\n';
    }

    // Закриття файлу
    outputFile.close();

    return 0;
}
