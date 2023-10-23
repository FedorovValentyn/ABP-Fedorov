#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class RLY {
public:
    string a;
    string b;
    string c;
    string d;

    RLY() {
        a = "";
        b = "";
        c = "";
        d = "";
    }

    RLY(const string& a_val, const string& b_val, const string& c_val, const string& d_val)
            : a(a_val), b(b_val), c(c_val), d(d_val) {}

    // Функції-аксесори (get та set) для кожного поля:

    string getA() const { return a; }
    void setA(const string& value) { a = value; }

    string getB() const { return b; }
    void setB(const string& value) { b = value; }

    string getC() const { return c; }
    void setC(const string& value) { c = value; }

    string getD() const { return d; }
    void setD(const string& value) { d = value; }

    // Функція show для виведення даних про проект:

    void show() const {
        cout << "| " << left << setw(10 + Unicode(a)) << a
             << "| " << left << setw(6 + Unicode(b)) << b
             << "| " << left << setw(17 + Unicode(c)) << c
             << "| " << left << setw(17 + Unicode(d)) << d
             << "|" << endl;
    }

private:
    int Unicode(const string& str) const {
        int nonLatinCounter = 0;
        for (char c : str) {
            if (static_cast<unsigned char>(c) > 127) {
                nonLatinCounter += 1;
            }
        }
        return nonLatinCounter;
    }
};

int Lab_11() {
    setlocale(LC_ALL, "Ukrainian");
    cout << "Проекти пошуку позаземних сигналів" << endl;

    RLY arr[4];

    // Виведення розділювача
    string separator(64, '-');
    cout << separator << endl;

    for (int i = 1; i < 4; ++i) {
        string a_val, b_val, c_val, d_val;
        cout << "Введіть Рік, Науковий керівник, Діаметр антени (м), Робоча частота (МГц): " << endl;
        cin >> a_val >> b_val >> c_val >> d_val;
        arr[i] = RLY(a_val, b_val, c_val, d_val);
    }

    string separator2(64, '-');

    // Виведення заголовка таблиці перед першим рядком даних
    cout << "| " << left << setw(10) << "Рік"
         << "| " << left << setw(6) << "Науковий керівник"
         << "| " << left << setw(17) << "Діаметр антени (м)"
         << "| " << left << setw(24) << "Робоча частота (МГц)"
         << "|"<<endl;

    for (int i = 1; i < 4; ++i) {
        arr[i].show();

        if (i == 1) cout << separator2 << endl;
    }

    cout << "Примітка: спостерігалися об'єкти від 2 зірок до кількох галактик" << endl;
    cout << "_________________________________________________________________" << endl;

    return 0;
}
