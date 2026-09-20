#include <iostream>
using namespace std;

class SinglyCircular
{
    struct Node
    {
        int data;
        Node* next;

        Node(int value)
        {
            data = value;
            next = NULL;
        }
    };

    Node* head;

public:

    SinglyCircular()
    {
        head = NULL;
    }

    void join(int value, int position)
    {
        Node* newNode = new Node(value);

        if (head == NULL)
        {
            head = newNode;
            newNode->next = head;
            return;
        }

        if (position == 1)
        {
            Node* last = head;

            while (last->next != head)
                last = last->next;

            newNode->next = head;
            last->next = newNode;
            head = newNode;

            return;
        }

        Node* temp = head;

        for (int i = 1; i < position - 1; i++)
        {
            if (temp->next == head)
            {
                cout << "Invalid position!" << endl;
                delete newNode;
                return;
            }

            temp = temp->next;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }

    void leave(int position)
    {
        if (head == NULL)
        {
            cout << "Circle is empty!" << endl;
            return;
        }

        if (head->next == head)
        {
            if (position == 1)
            {
                delete head;
                head = NULL;
            }
            else
            {
                cout << "Invalid position!" << endl;
            }

            return;
        }

        if (position == 1)
        {
            Node* last = head;

            while (last->next != head)
                last = last->next;

            Node* temp = head;

            head = head->next;
            last->next = head;

            delete temp;

            return;
        }

        Node* temp = head;

        for (int i = 1; i < position - 1; i++)
        {
            if (temp->next == head)
            {
                cout << "Invalid position!" << endl;
                return;
            }
            temp = temp->next;
        }

        Node* deleteNode = temp->next;

        if (deleteNode == head)
        {
            cout << "Invalid position!" << endl;
            return;
        }

        temp->next = deleteNode->next;
        delete deleteNode;
    }

    void display()
    {
        if (head == NULL)
        {
            cout << "Circle is empty!" << endl;
            return;
        }
        Node* temp = head;

        do
        {
            cout << temp->data << " ";
            temp = temp->next;

        } while (temp != head);
        cout << endl;
    }
};

int main()
{
    SinglyCircular circle;

    int choice;
    int student;
    int position;

    do
    {
        cout << "\n===== STUDENT CIRCLE =====" << endl;
        cout << "1. JOIN" << endl;
        cout << "2. LEAVE" << endl;
        cout << "3. DISPLAY" << endl;
        cout << "4. EXIT" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "Enter student number: ";
                cin >> student;

                cout << "Enter position: ";
                cin >> position;

                circle.join(student, position);

                cout << "After JOIN: ";
                circle.display();

                break;

            case 2:
                cout << "Enter position to leave: ";
                cin >> position;

                circle.leave(position);

                cout << "After LEAVE: ";
                circle.display();

                break;

            case 3:
                cout << "Current Circle: ";
                circle.display();

                break;

            case 4:
                cout << "Program ended." << endl;
                break;

            default:
                cout << "Invalid choice!" << endl;
        }

    } while (choice != 4);

    return 0;
}
