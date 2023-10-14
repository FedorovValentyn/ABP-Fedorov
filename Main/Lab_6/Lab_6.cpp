#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;


int Lab_6() {

    srand(time(nullptr));
    int SIZE;
    int* signIndex = nullptr;
    int signIndexCount = 0;

    cout << "Введіть розмір масиву: ";
    cin >> SIZE;

    int* arr = new int[SIZE];

    for (int i = 0; i < SIZE; ++i) {
        arr[i] = rand() % 101 - 50;
        cout << arr[i] << " ";
        if (i % 25 == 0 && i != 0) {
            cout << endl;
        }
    }
    cout << endl;


    for (int i = 1; i < SIZE; ++i) {
        if (arr[i - 1] * arr[i] < 0) {          //визначаємо скільки разів буде змінюватись знак і виділяємо для нього пам'ять
            signIndexCount++;
        }
    }

    signIndex = new int[signIndexCount];                // Виділяємо пам'ять для масиву з індексами елементів


    signIndexCount = 0;
    for (int i = 1; i < SIZE; ++i) {
        if (arr[i - 1] * arr[i] < 0) {
            signIndex[signIndexCount] = i;                      //зберігаємо індекси
            signIndexCount++;
        }
    }

    cout << "Зміни знаку в індексах: " << endl;
    for (int j = 0; j < signIndexCount; ++j) {
        cout << signIndex[j] << " ";
    }
    cout << endl;


    delete[] arr;
    delete[] signIndex;

    return 0;
}