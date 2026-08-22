#include <iostream>
using namespace std;

struct Node
{
    int token;
    Node *next;
};

Node *head = NULL;

// Critical patient - inserted at the front
void insertbeg(int value)
{
    Node *newNode = new Node;

    newNode->token = value;
    newNode->next = head;
    head = newNode;
}

// Routine patient - inserted at the end
void insertEnd(int value)
{
    Node *newNode = new Node;

    newNode->token = value;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    Node *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
}

// Priority patient - inserted at a specific position
void insertPosition(int value, int position)
{
    Node *newNode = new Node;

    newNode->token = value;
    newNode->next = NULL;

    // Position 1 means insert at front
    if (position == 1)
    {
        newNode->next = head;
        head = newNode;
        return;
    }

    // Find the node before the required position
    Node *temp = head;

    for (int i = 1; i < position - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }

    // Position is greater than current queue length
    if (temp == NULL)
    {
        cout << "Invalid position!" << endl;
        delete newNode;
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

// Display queue
void display()
{
    if (head == NULL)
    {
        cout << "Queue is Empty." << endl;
        return;
    }

    Node *temp = head;

    cout << "Patient Queue: ";

    while (temp != NULL)
    {
        cout << temp->token << " ";
        temp = temp->next;
    }

    cout << endl;
}

int main()
{
    int choice, token, position;

    do
    {
        cout << "\n1. Insert at the front" << endl;
        cout << "2. Insert at the back" << endl;
        cout << "3. Insert at a specific position" << endl;
        cout << "4. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
             // Critical patient-added to the front
            cout << "Enter Patient Token: ";
            cin >> token;

            insertbeg(token);
            display();
            break;

        case 2:
            // Routine patient-added to the end
            cout << "Enter Patient Token: ";
            cin >> token;

            insertEnd(token);
            display();
            break;

        case 3:
            // Priority patient-inserted at the given position
            cout << "Enter Patient Token: ";
            cin >> token;

            cout << "Enter Position: ";
            cin >> position;

            insertPosition(token, position);
            display();
            break;

        case 4:
            cout << "Program Exited." << endl;
            break;

        default:
            cout << "Invalid choice!" << endl;
        }

    } while (choice != 4);

    return 0;
}
