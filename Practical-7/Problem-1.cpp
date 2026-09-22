#include <iostream>
using namespace std;

class Queue {
    int *arr;
    int capacity;
    int front;
    int rear;
    int count;

public:
    Queue(int n) {
        capacity = n;
        arr = new int[capacity];
        front = 0;
        rear = -1;
        count = 0;
    }

    void join(int token) {
        if (count == capacity) {
            cout << "Error: Queue is Full" << endl;
            return;
        }

        rear = (rear + 1) % capacity;
        arr[rear] = token;
        count++;

        cout << "Front token: " << arr[front] << endl;
    }

    void serve() {
        if (count == 0) {
            cout << "Error: Queue is Empty" << endl;
            return;
        }

        cout << "Served token: " << arr[front] << endl;

        front = (front + 1) % capacity;
        count--;

        if (count > 0)
            cout << "Front token: " << arr[front] << endl;
        else
            cout << "Queue is Empty" << endl;
    }

    ~Queue() {
        delete[] arr;
    }
};

int main() {
    int n, operations;

    cout << "Enter queue capacity: ";
    cin >> n;

    Queue q(n);

    cout << "Enter number of operations: ";
    cin >> operations;

    for (int i = 0; i < operations; i++) {
        int choice;

        cout << "\n1. Join\n";
        cout << "2. Serve\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            int token;
            cout << "Enter token number: ";
            cin >> token;

            q.join(token);
        }
        else if (choice == 2) {
            q.serve();
        }
        else {
            cout << "Invalid choice!" << endl;
        }
    }

    return 0;
}
