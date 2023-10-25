#include <iostream>
#include <iomanip>
#include <stdexcept>

using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;
    Node* tail;

public:
    LinkedList() : head(nullptr), tail(nullptr) {}

    LinkedList(const LinkedList& other) : head(nullptr), tail(nullptr) {
        copyFrom(other);
    }

    ~LinkedList() {
        clearList();
    }

    void insertAtHead(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
    }

    void insertAtTail(int value) {
        Node* newNode = new Node(value);
        if (!tail) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void display() const {
        Node* current = head;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    Node* search(int value) {
        Node* current = head;
        while (current) {
            if (current->data == value) {
                return current;
            }
            current = current->next;
        }
        return nullptr;
    }

    Node* getHead() const {
        return head;
    }

    Node* getTail() const {
        return tail;
    }

    LinkedList& operator=(const LinkedList& other) {
        if (this == &other) {
            return *this;
        }
        clearList();
        copyFrom(other);
        return *this;
    }

private:
    void copyFrom(const LinkedList& other) {
        Node* current = other.head;
        while (current) {
            insertAtTail(current->data);
            current = current->next;
        }
    }

    void clearList() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
    }
};

class Dynamic2DArray {
private:
    int** arr;
    int numRows;
    int numCols;
    int maxRows;
    int maxCols;

public:
    Dynamic2DArray() : arr(nullptr), numRows(0), numCols(0), maxRows(0), maxCols(0) {}

    Dynamic2DArray(int rows, int cols) : arr(nullptr), numRows(0), numCols(0), maxRows(0), maxCols(0) {
        createArray(rows, cols);
    }

    Dynamic2DArray(const Dynamic2DArray& other) : arr(nullptr), numRows(0), numCols(0), maxRows(0), maxCols(0) {
        copyFrom(other);
    }

    ~Dynamic2DArray() {
        clearArray();
    }

    void createArray(int rows, int cols) {
        if (rows <= 0 || cols <= 0) {
            throw invalid_argument("Rows and columns must be positive.");
        }

        clearArray();

        maxRows = rows;
        maxCols = cols;

        numRows = rows;
        numCols = cols;

        arr = new int*[numRows];
        for (int i = 0; i < numRows; ++i) {
            arr[i] = new int[numCols];
        }
    }

    void setValue(int row, int col, int value) {
        if (row < 0 || row >= numRows || col < 0 || col >= numCols) {
            throw out_of_range("Index out of bounds.");
        }
        arr[row][col] = value;
    }

    int getValue(int row, int col) const {
        if (row < 0 || row >= numRows || col < 0 || col >= numCols) {
            throw out_of_range("Index out of bounds.");
        }
        return arr[row][col];
    }

    void printArray() const {
        for (int i = 0; i < numRows; ++i) {
            for (int j = 0; j < numCols; ++j) {
                cout << setw(4) << arr[i][j];
            }
            cout << endl;
        }
    }

    int findMax() const {
        int maxVal = arr[0][0];
        for (int i = 0; i < numRows; ++i) {
            for (int j = 0; j < numCols; ++j) {
                if (arr[i][j] > maxVal) {
                    maxVal = arr[i][j];
                }
            }
        }
        return maxVal;
    }

    int findMin() const {
        int minVal = arr[0][0];
        for (int i = 0; i < numRows; ++i) {
            for (int j = 0; j < numCols; ++j) {
                if (arr[i][j] < minVal) {
                    minVal = arr[i][j];
                }
            }
        }
        return minVal;
    }

    int getMaxRows() const {
        return maxRows;
    }

    int getMaxCols() const {
        return maxCols;
    }

    int getCurrentRows() const {
        return numRows;
    }

    int getCurrentCols() const {
        return numCols;
    }

    Dynamic2DArray& operator=(const Dynamic2DArray& other) {
        if (this == &other) {
            return *this;
        }
        clearArray();
        copyFrom(other);
        return *this;
    }

private:
    void copyFrom(const Dynamic2DArray& other) {
        createArray(other.maxRows, other.maxCols);
        for (int i = 0; i < numRows; ++i) {
            for (int j = 0; j < numCols; ++j) {
                arr[i][j] = other.arr[i][j];
            }
        }
    }

    void clearArray() {
        if (arr) {
            for (int i = 0; i < numRows; ++i) {
                delete[] arr[i];
            }
            delete[] arr;
            arr = nullptr;
            numRows = 0;
            numCols = 0;
            maxRows = 0;
            maxCols = 0;
        }
    }
};

int Lab_14() {
    LinkedList myList;

    myList.insertAtHead(1);
    myList.insertAtHead(2);
    myList.insertAtHead(3);
    myList.insertAtTail(4);
    myList.insertAtTail(5);

    cout << "Linked List: ";
    myList.display();

    Node* foundNode = myList.search(3);
    if (foundNode) {
        cout << "Found: " << foundNode->data << endl;
    } else {
        cout << "Element not found." << endl;
    }

    Node* head = myList.getHead();
    Node* tail = myList.getTail();

    if (head) {
        cout << "Head: " << head->data << endl;
    } else {
        cout << "List is empty." << endl;
    }

    if (tail) {
        cout << "Tail: " << tail->data << endl;
    } else {
        cout << "List is empty." << endl;
    }

    Dynamic2DArray array(3, 4);

    for (int i = 0; i < array.getCurrentRows(); ++i) {
        for (int j = 0; j < array.getCurrentCols(); ++j) {
            array.setValue(i, j, i * array.getCurrentCols() + j);
        }
    }

    cout << "Dynamic 2D Array:" << endl;
    array.printArray();

    cout << "Max Value: " << array.findMax() << endl;
    cout << "Min Value: " << array.findMin() << endl;

    cout << "Max Rows: " << array.getMaxRows() << endl;
    cout << "Max Columns: " << array.getMaxCols() << endl;
    cout << "Current Rows: " << array.getCurrentRows() << endl;
    cout << "Current Columns: " << array.getCurrentCols() << endl;

    return 0;
}


