#include <iostream>
using namespace std;

#define MAX 100

class Stack {
private:
    int arr[MAX];
    int top;
    int capacity;

public:
    Stack(int n) {
        capacity = n;
        top = -1;
    }

    void push(int tray) {

        if (top == capacity - 1) {
            cout << "Error: Stack is Full. Cannot place tray "
                 << tray << endl;
            return;
        }

        top++;
        arr[top] = tray;

        cout << "Placed tray: " << tray << endl;
        cout << "Current top tray: " << arr[top] << endl;
    }

    void pop() {

        if (top == -1) {
            cout << "Error: Stack is Empty. Cannot take tray."
                 << endl;
            return;
        }

        cout << "Taken tray: " << arr[top] << endl;

        top--;

        if (top == -1)
            cout << "Current top tray: None" << endl;
        else
            cout << "Current top tray: " << arr[top] << endl;
    }
};

int main() {

    int n;
    cout << "Enter stack capacity: ";
    cin >> n;

    Stack s(n);

    int choice, tray;

    do {
        cout << "\n----- TRAY STACK -----\n";
        cout << "1. Place Tray (Push)\n";
        cout << "2. Take Tray (Pop)\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {

            case 1:
                cout << "Enter tray number: ";
                cin >> tray;
                s.push(tray);
                break;

            case 2:
                s.pop();
                break;

            case 3:
                cout << "Program ended." << endl;
                break;

            default:
                cout << "Invalid choice!" << endl;
        }

    } while (choice != 3);

    return 0;
}
