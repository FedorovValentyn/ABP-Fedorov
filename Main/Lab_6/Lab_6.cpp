#include <iostream>
#include <iomanip>

using namespace std;


int Lab_6() {
    const int SIZE = 100;
    int signIndex[100];
    int arr[SIZE];
    int signIndexCount = 0;


    for (int i = 0; i < SIZE; ++i) {
        arr[i] = rand() % 101 - 50;
        cout << arr[i] << " ";
        if (i % 25 == 0 && i != 0) {
            cout << endl;
        }
    }

    for (int i = 1; i < SIZE; ++i) {
        if (arr[i - 1] * arr[i] < 0) {
            signIndex[signIndexCount] = i;
            signIndexCount++;
        }
    }

    cout << "Зміни знаку в індексах: " << endl;
    for (int j = 0; j < signIndexCount; ++j) {
        cout << signIndex[j] << " ";
    }
    cout << endl;
    return 0;
}
