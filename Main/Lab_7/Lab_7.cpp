#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;


void fillArray(int** array, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            array[i][j] = rand() % 101 - 50;
        }
    }
}



void swapSecondaryDiagonal(int** array, int n) {
    int rowLength = n - 1;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < rowLength; j++) {
            cout << "ij " << array[i][j] << " ji " << array[n-1-j][n-1-i] << endl;
            array[n-1-j][n-1-i] = array[i][j];
        }
        rowLength--;
    }
}


void displayArray(int** array, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }
}

int Lab_7() {
    int n;
    cout << "Введіть розміреність матриці : " << endl;
    cin >> n;

    int** array = new int*[n];
    for (int i = 0; i < n; i++) {
        array[i] = new int[n];
    }


    srand(time(nullptr));

    fillArray(array, n);

    cout << "Оригінальна матриця:" << endl;
    displayArray(array, n);

    swapSecondaryDiagonal(array, n);

    cout << "Матриця з відображенням по діагоналі:" << endl;
    displayArray(array, n);


    for (int i = 0; i < n; i++) {
        delete[] array[i];
    }
    delete[] array;

    return 0;
}
