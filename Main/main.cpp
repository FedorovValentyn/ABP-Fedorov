#include <iostream>
#include <stdio.h>
#include <string>
#include <iomanip>

using namespace std;


int main(void){
    setlocale(LC_ALL, "ukr");

    int year1,year2,year3;
    string direc1,direc2,direc3;
    int diametr1,diametr2,diametr3;
    int freq1, freq2,freq3;


    cout << "1. Введіть: рік, керівника, діаметр, частоту >" << endl;
    cin>> year1;
    cin>>direc1;
    cin>>diametr1;
    cin>>freq1;

    cout << "2. Введіть: рік, керівника, діаметр, частоту >" << endl;
    cin>> year2;
    cin>>direc2;
    cin>>diametr2;
    cin>>freq2;

    cout << "3. Введіть: рік, керівника, діаметр, частоту >" << endl;
    cin>> year3;
    cin>>direc3;
    cin>>diametr3;
    cin>>freq3;

          cout<<(" --------------------------------------------------\n");
    cout<<("|       Проекти пошуку позаземних сигналів        |\n");
    cout<<("|-------------------------------------------------|\n");
    cout<<("|  Рік   | Науковий  | Діаметр    | Робоча частота|\n");
    cout<<("|        | керівник  | антени (м) |    (ГГц)      |\n");
    cout<<("|--------|-----------|------------|---------------|\n");

    cout << ("|")<< setw(5)<< year1<< setw(4)<<("|") << setw(12)<< direc1 <<setw(5)<<("|")<<setw(5)<< diametr1 << setw(8)<<("|")<< setw(6)<<freq1<< setw(10)<<("|")<< endl;

    cout << ("|")<< setw(5)<< year2<< setw(4)<<("|") << setw(12)<< direc2 <<setw(3)<<("|")<<setw(5)<< diametr2 << setw(8)<<("|")<< setw(6)<<freq2<< setw(10)<<("|")<< endl;

    cout << ("|")<< setw(5)<< year3<< setw(4)<<("|") << setw(12)<< direc3 <<setw(5)<<("|")<<setw(5)<< diametr3 << setw(8)<<("|")<< setw(6)<<freq3<< setw(10)<<("|")<< endl;

    cout<<("|-------------------------------------------------|\n");
    cout<<("|         Примітка: спостерігалися об'єкти        |\n");
    cout<<("|          від 2 зірок  до кількох галактик       |\n");
    cout<<("---------------------------------------------------\n");





    return 0;
}