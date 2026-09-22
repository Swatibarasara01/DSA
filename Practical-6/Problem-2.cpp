#include <iostream>
#include <string>
using namespace std;

struct Node {
    string page;
    Node* next;
};

class Browser {
private:
    Node* top;

public:
    Browser() {
        top = NULL;
    }

    void visit(string page) {
        Node* newNode = new Node();

        newNode->page = page;
        newNode->next = top;

        top = newNode;

        cout << "Visited: " << page << endl;
        cout << "Current Page: " << top->page << endl;
    }

    void back() {

        if (top == NULL) {
            cout << "Error: No history left. Cannot go back."
                 << endl;
            return;
        }

        Node* temp = top;
        cout << "Going back from: " << top->page << endl;
        top = top->next;
        delete temp;

        if (top == NULL) {
            cout << "Current Page: None" << endl;
        }
        else {
            cout << "Current Page: " << top->page << endl;
        }
    }
};

int main() {

    Browser browser;

    int choice;
    string page;

    do {
        cout << "\n----- BROWSER -----\n";
        cout << "1. Visit Page\n";
        cout << "2. Back\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {

            case 1:
                cout << "Enter page name: ";
                cin >> page;

                browser.visit(page);
                break;

            case 2:
                browser.back();
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
