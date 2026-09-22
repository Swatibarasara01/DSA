#include <iostream>
using namespace std;

struct Node {
    int patient;
    Node* next;

    Node(int p) {
        patient = p;
        next = nullptr;
    }
};

class PatientQueue {
    Node* front;
    Node* rear;

public:
    PatientQueue() {
        front = nullptr;
        rear = nullptr;
    }

    void arrive(int patient) {
        Node* newNode = new Node(patient);

        if (rear == nullptr) {
            front = rear = newNode;
        }
        else {
            rear->next = newNode;
            rear = newNode;
        }

        cout << "Front patient: " << front->patient << endl;
    }

    void attend() {
        if (front == nullptr) {
            cout << "Error: No patients waiting" << endl;
            return;
        }

        cout << "Attended patient: " << front->patient << endl;

        Node* temp = front;
        front = front->next;

        delete temp;

        if (front == nullptr) {
            rear = nullptr;
            cout << "Ward is Empty" << endl;
        }
        else {
            cout << "Front patient: " << front->patient << endl;
        }
    }
};

int main() {
    PatientQueue q;

    int operations;

    cout << "Enter number of operations: ";
    cin >> operations;

    for (int i = 0; i < operations; i++) {

        int choice;

        cout << "\n1. Arrive" << endl;
        cout << "2. Attend" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            int patient;
            cout << "Enter patient number: ";
            cin >> patient;

            q.arrive(patient);
        }
        else if (choice == 2) {
            q.attend();
        }
        else {
            cout << "Invalid choice!" << endl;
        }
    }

    return 0;
}
