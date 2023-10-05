#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;


int Lab_3(){
    long  k2 = 1;
    double dbln, sum=0, term;
    const double EPS = 0.000001;
    short k1= 1;
    int n;

    for (n = 0; ;n++, k2 *=2, k1 = -1*k1) {
        dbln = static_cast<double>(n);
        term = k1 * (1 - ((dbln+1)*(dbln +1))/((dbln+2)*(dbln+2)));
        if (fabs(term)>=EPS){
            sum +=term;
        }
        else {
                break;
        }
        if (n==9){
            cout<<"Сума 10 членів ряду : " << fixed<< setprecision(6)<< sum<<endl;
        }
    }
    cout<<"Повна сума ряду: "<< fixed<<setprecision(6)<< sum<<endl;
    cout<<"Ітерація: "<< n << endl;
    return 0;
}