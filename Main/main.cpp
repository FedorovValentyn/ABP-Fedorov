#include <iostream>
#include <string>
#include <iomanip>
#include <windows.h>
#include "Lab_1//Lab_1.cpp"
#include "Lab_2//Lab_2.cpp"
using namespace std;


int main(){
    SetConsoleOutputCP(CP_UTF8);
int nomerLabaratornoi;
anchor:
    cout<< "Виберіть номер лаби:"<< endl;
    cin>> nomerLabaratornoi;
    switch(nomerLabaratornoi) {
        case 1:
            Lab_1();
            break;
        case 2:
            Lab_2();
            break;
        case 3:
            cout<< "Введіть номер лаби:"<<endl;
            break;
        case 4 :
            return 0;
        default :
            cout<< "Неправильне значення"<< endl;
    }
        goto anchor;
}