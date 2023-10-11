#include <iostream>
#include <iomanip>
#include <cmath>
#include <time.h>

using namespace std;


int Lab_4(){
    srand(time(NULL));

    const int SIZE = 100;
    int arr[SIZE];

    for (int i = 0; i < SIZE; i++) {
        arr[i] = rand()% 101 -50;
    }

    for (int i = 0; i < SIZE; i++) {
        cout << arr[i] << " ";
        if (i % 25 == 0 && i != 0) {
            cout << endl;
        }
    }

    cout <<" " <<endl;
    cout <<""<<endl;
    int lastPositiveIndex = SIZE-1;

    for (int i = 0; i <= lastPositiveIndex; i++) {
        int temp = 0;

        if (arr[i] >= 0) {
//            cout << "first pos " << arr[i] << ' ' << i;
            for (int j = lastPositiveIndex; j > i; j--) {
                if (arr[j] >= 0) {
//                    cout << "last pos " << arr[j] << ' ' << j << endl;
                    lastPositiveIndex = j;
                    temp = arr[i];
                    arr[i] = arr[lastPositiveIndex];
                    arr[lastPositiveIndex] = temp;
                    lastPositiveIndex--;
                    break;
                }
            }
        }
    }

    for (int i = 0; i < SIZE; i++) {
        cout << arr[i] << ' ';
        if (i % 25 == 0 && i != 0) {
            cout<<"  " << endl;
        }
    }
    cout<<"  "<<endl;
    return 0;
}