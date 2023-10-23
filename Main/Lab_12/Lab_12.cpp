#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

class Student {
private:
    string name;
    int age;
    string vnz;

public:
    string getName() const { return name; }
    void setName(const string &value) { name = value; }

    int getAge() const { return age; }
    void setAge(const int &value) { age = value; }

    string getVnz() const { return vnz; }
    void setVnz(const string &value) { vnz = value; }

    void Show() const {
        cout << "Ім'я: " << name << endl;
        cout << "Вік: " << age << endl;
        cout << "Університет: " << vnz << endl;
    }

    void generateGrades() {
        int grades[7];

        for (int i = 0; i < 7; ++i) {
            grades[i] = rand() % 41 + 60;
        }

        cout << "English: " << grades[0] << endl;
        cout << "Theory probability and Math statistic: " << grades[1] << endl;
        cout << "Mathematical analysis: " << grades[2] << endl;
        cout << "Discrete mathematics: " << grades[3] << endl;
        cout << "Introducing to studies of university: " << grades[4] << endl;
        cout << "Linear Algebra: " << grades[5] << endl;
        cout << "Algorithmisation and basics of programming: " << grades[6] << endl;
    }
};

void Lab_12() {
    int point;
    Student student;

    refresher:
    cout << "Choose the point : " << endl;
    cout << "1. Get all info " << endl;
    cout << "2. Student's name " << endl;
    cout << "3. Student's age " << endl;
    cout << "4. Info about the university " << endl;
    cout << "5. Marks" << endl;
    cout << "6. Exit" << endl;

    cin >> point;
    switch (point) {
        case 1: {
            string name;
            cout << "Введіть ім'я студента: ";
            cin >> name;
            student.setName(name);

            cout << "Введіть вік студента: ";
            int age;
            cin >> age;
            student.setAge(age);

            cout << "Введіть назву університету: ";
            string vnz;
            cin >> vnz;
            student.setVnz(vnz);

            student.Show();
            goto refresher;
        }

        case 2 : {
            char name_Changing;
            string changed_name;
            cout << "Ім'я студента: " << student.getName() << endl;
            cout << "Would you like to change the name? Put 'y' for yes and 'n' for no" << endl;
            cin >> name_Changing;

            if (name_Changing == 'y') {
                cout << "Enter the name you would like change to : " << endl;
                cin >> changed_name;
                student.setName(changed_name);
                cout << "New name is :" << student.getName() << endl;
            }
            goto refresher;
        }

        case 3: {
            cout << "Вік студента: " << student.getAge() << endl;
            goto refresher;
        }

        case 4: {
            cout << "Університет: " << student.getVnz() << endl;
            cout << "Завдання університету - надати необхідні умови для навчання" << endl;
            goto refresher;
        }
        case 5: {
            student.generateGrades();
            goto refresher;

            case 6: {
                cout << "Exit" << endl;
                return;
            }
        }
    }
}