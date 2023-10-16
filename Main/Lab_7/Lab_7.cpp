#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstdlib>
using namespace std;

int Lab_7() {

    int n;
    cout<<"Введіть розмірність масиву : " <<endl;
    cin>> n;
    int array[n][n];
    int rowLength = n - 1;


    for(int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            array[i][j] = rand() % 101-50;
            cout << array[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < rowLength; j++) {
            cout << endl;
            cout << "ij " << array[i][j] << " ji " << array[n-1-j][n-1-i] << endl;
            array[n-1-j][n-1-i] = array[i][j];
        }
        rowLength--;
    }

    cout << "Матриця з верхнім та нижнім трикутником побічної діагоналі:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }
return 0;
}

