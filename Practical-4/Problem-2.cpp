#include <iostream>
using namespace std;

struct Node
{
    int token;
    Node *next;
};

Node *head = NULL;


// Critical patient -> inserted at the front
void insertbeg(int value)
{
    Node *newNode = new Node;

    newNode->token = value;
    newNode->next = head;

    head = newNode;
}


// Routine patient -> inserted at the end
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


// Priority patient -> inserted at a specific position
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

    Node *temp = head;

    // Move to the node before required position
    for (int i = 1; i < position - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }

    // Position is greater than queue length
    if (temp == NULL)
    {
        cout << "Invalid position!" << endl;
        delete newNode;
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}


// Delete patient by token value
void deleteByValue(int value)
{
    if (head == NULL)
    {
        cout << "Queue is Empty." << endl;
        return;
    }

    // If first node contains the value
    if (head->token == value)
    {
        Node *temp = head;
        head = head->next;

        delete temp;

        cout << "Patient " << value << " deleted." << endl;
        return;
    }

    Node *temp = head;

    // Find node before the node to be deleted
    while (temp->next != NULL && temp->next->token != value)
    {
        temp = temp->next;
    }

    // Value not found
    if (temp->next == NULL)
    {
        cout << "Patient token not found." << endl;
        return;
    }

    Node *deleteNode = temp->next;

    temp->next = deleteNode->next;

    delete deleteNode;

    cout << "Patient " << value << " deleted." << endl;
}


// Forward traversal
void display()
{
    if (head == NULL)
    {
        cout << "Queue is Empty." << endl;
        return;
    }

    Node *temp = head;

    cout << "Patient Queue (Front to Back): ";

    while (temp != NULL)
    {
        cout << temp->token << " ";
        temp = temp->next;
    }

    cout << endl;
}


// Reverse printing using recursion
void reversePrint(Node *temp)
{
    if (temp == NULL)
        return;

    reversePrint(temp->next);

    cout << temp->token << " ";
}


int main()
{
    int choice;
    int token;
    int position;

    do
    {
        cout << "\n===== Hospital Patient Queue =====" << endl;

        cout << "1. Insert at the front" << endl;
        cout << "2. Insert at the back" << endl;
        cout << "3. Insert at a specific position" << endl;
        cout << "4. Delete patient by token" << endl;
        cout << "5. Display queue (Front to Back)" << endl;
        cout << "6. Reverse print (Back to Front)" << endl;
        cout << "7. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;


        switch (choice)
        {
        case 1:

            // Critical patient -> added to the front
            cout << "Enter Patient Token: ";
            cin >> token;

            insertbeg(token);
            display();

            break;


        case 2:

            // Routine patient -> added to the end
            cout << "Enter Patient Token: ";
            cin >> token;

            insertEnd(token);
            display();

            break;


        case 3:

            // Priority patient -> inserted at specific position
            cout << "Enter Patient Token: ";
            cin >> token;

            cout << "Enter Position: ";
            cin >> position;

            insertPosition(token, position);
            display();

            break;


        case 4:

            // Patient leaves -> delete token by value
            cout << "Enter Patient Token to Delete: ";
            cin >> token;

            deleteByValue(token);
            display();

            break;


        case 5:

            // Forward traversal -> Front to Back
            display();

            break;


        case 6:

            // Reverse printing -> Back to Front
            if (head == NULL)
            {
                cout << "Queue is Empty." << endl;
            }
            else
            {
                cout << "Patient Queue (Back to Front): ";

                reversePrint(head);

                cout << endl;
            }

            break;


        case 7:

            cout << "Program Exited." << endl;

            break;


        default:

            cout << "Invalid choice!" << endl;
        }

    } while (choice != 7);


    return 0;
}
