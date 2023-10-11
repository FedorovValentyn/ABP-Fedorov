#include <iostream>

using namespace std;


int Lab_7() {
    int n =9;

    int array[n][n];

    int num = 1;
    int topRow = 0, bottomRow = n - 1, leftCol = 0, rightCol = n - 1;

    while (topRow <= bottomRow && leftCol <= rightCol) {

        for (int i = leftCol; i <= rightCol; i++) {
            array[topRow][i] = num++;
        }
        topRow++;


        for (int i = topRow; i <= bottomRow; i++) {
            array[i][rightCol] = num++;
        }
        rightCol--;


        for (int i = rightCol; i >= leftCol; i--) {
            array[bottomRow][i] = num++;
        }
        bottomRow--;


        for (int i = bottomRow; i >= topRow; i--) {
            array[i][leftCol] = num++;
        }
        leftCol++;
    }


    cout << "Заповнений масив по спіралі:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << array[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}