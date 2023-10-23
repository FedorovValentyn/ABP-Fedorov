#include <iostream>
#include <string>
#include <iomanip>
#include <windows.h>
#include "Lab_1//Lab_1.cpp"
#include "Lab_2//Lab_2.cpp"
#include "Lab_3//Lab_3.cpp"
#include "Lab_4//Lab_4.cpp"
#include "Lab_5//Lab_5.cpp"
#include "Lab_6//Lab_6.cpp"
#include "Lab_7//Lab_7.cpp"
#include "Lab_8//Lab_8.cpp"
#include "Lab_9//Lab_9.cpp"
#include "Lab_10//Lab_10.cpp"
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
            Lab_3();
            break;
        case 4:
            Lab_4();
            break;
        case 5:
            Lab_5();
            break;
        case 6:
            Lab_6();
            break;
        case 7:
            Lab_7();
            break;
        case 8:
            Lab_8();
            break;
        case 9:
            Lab_9();
            break;
        case 10:
            Lab_10();
            break;
        case 15:
            cout<< "Введіть номер лаби:"<<endl;
            break;
        case 16 :
            return 0;
        default :
            cout<< "Неправильне значення"<< endl;
    }
        goto anchor;
}