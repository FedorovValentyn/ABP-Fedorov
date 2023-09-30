#include <iostream>
#include <iomanip>

using namespace std;


int Lab_2(){

    double x, y;

    cout <<"Введіть занчення х:"<<endl;
    cin>> x;

    cout <<"Введіть занчення y:"<<endl;
    cin>> y;

    cout<< fixed<< setprecision(3);

    cout<<"x :"<<x <<setw(15)<<"y :"<< y<< endl;


    if(y<=x+1 && (y<=1-x ) && (y>=x-1) &&(x*x+y*y<=1)&&  (x >0 && y>0) )
        cout<<"Точка попадає в область"<<endl;

    else
        cout<<"Точка не попадає в область"<<endl;

    return 0;
}