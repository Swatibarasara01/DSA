#include <iostream>
using namespace std;

class DoublyCircular
{
    struct Node
    {
        int data;
        Node* next;
        Node* prev;

        Node(int value)
        {
            data = value;
            next = NULL;
            prev = NULL;
        }
    };

    Node* head;

public:

    DoublyCircular()
    {
        head = NULL;
    }

    void join(int value, int position)
    {
        Node* newNode = new Node(value);

        if (head == NULL)
        {
            head = newNode;

            head->next = head;
            head->prev = head;

            return;
        }

        if (position == 1)
        {
            Node* last = head->prev;

            newNode->next = head;
            newNode->prev = last;

            last->next = newNode;
            head->prev = newNode;

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
        newNode->prev = temp;

        temp->next->prev = newNode;
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
            Node* deleteNode = head;
            Node* last = head->prev;

            head = head->next;

            last->next = head;
            head->prev = last;

            delete deleteNode;

            return;
        }

        Node* temp = head;

        for (int i = 1; i < position; i++)
        {
            if (temp->next == head)
            {
                cout << "Invalid position!" << endl;
                return;
            }

            temp = temp->next;
        }

        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;

        delete temp;
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
    DoublyCircular circle;

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
