#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Func{
public:
    string a;
    string b;
    string c;
    string d;

    Func() : a(""), b(""), c(""), d("") {}

    Func(const string& a_val, const string& b_val, const string& c_val, const string& d_val)
            : a(a_val), b(b_val), c(c_val), d(d_val) {}

    string getA() const { return a; }
    void setA(const string& value) { a = value; }

    string getB() const { return b; }
    void setB(const string& value) { b = value; }

    string getC() const { return c; }
    void setC(const string& value) { c = value; }

    string getD() const { return d; }
    void setD(const string& value) { d = value; }

    void show() const {
        cout << "| " << left << setw(10) << a
             << "| " << left << setw(6) << b
             << "| " << left << setw(17) << c
             << "| " << left << setw(24) << d
             << "|" << endl;
    }

    int Unicode() const {
        int nonLatinCounter = 0;
        for (char c : a + b + c + d) {
            if (static_cast<unsigned char>(c) > 127) {
                nonLatinCounter += 1;
            }
        }
        return nonLatinCounter;
    }

    Func& operator=(const Func& other) {
        if (this == &other) {
            return *this;
        }
        a = other.a;
        b = other.b;
        c = other.c;
        d = other.d;
        return *this;
    }

    Func operator+(const Func& other) const {
        Func result;
        result.a = a + other.a;
        result.b = b + other.b;
        result.c = c + other.c;
        result.d = d + other.d;
        return result;
    }

    bool operator==(const Func& other) const {
        return (a == other.a) && (b == other.b) && (c == other.c) && (d == other.d);
    }

    friend istream& operator>>(istream& is, Func& rly) {
        is >> rly.a >> rly.b >> rly.c >> rly.d;
        return is;
    }

    friend ostream& operator<<(ostream& os, const Func& rly) {
        os << "| " << left << setw(10) << rly.a
           << "| " << left << setw(6) << rly.b
           << "| " << left << setw(17) << rly.c
           << "| " << left << setw(24) << rly.d
           << "|";
        return os;
    }
};

int Lab_13() {
    setlocale(LC_ALL, "Ukrainian");
    cout << "Проекти пошуку позаземних сигналів" << endl;

    Func arr[4];

    string separator(64, '-');
    cout << separator << endl;

    for (int i = 1; i < 4; ++i) {
        cout << "Введіть Рік, Науковий керівник, Діаметр антени (м), Робоча частота (МГц): " << endl;
        cin >> arr[i];
    }

    string separator2(64, '-');

    cout << "| " << left << setw(10) << "Рік"
         << "| " << left << setw(6) << "Науковий керівник"
         << "| " << left << setw(17) << "Діаметр антени (м)"
         << "| " << left << setw(24) << "Робоча частота (МГц)"
         << "|" << endl;

    for (int i = 1; i < 4; ++i) {
        cout << arr[i] << endl;

        if (i == 3) cout << separator2 << endl;
    }

    cout << "Примітка: спостерігалися об'єкти від 2 зірок до кількох галактик" << endl;
    cout << "_________________________________________________________________" << endl;

    return 0;
}
