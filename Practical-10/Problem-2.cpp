#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> shelves[10];

    int n;
    cout << "Enter number of books: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        int code;
        cout << "Enter book code: ";
        cin >> code;

        int shelf = code % 10;

        shelves[shelf].push(code);

        cout << "Book " << code
             << " added to shelf " << shelf << endl;
    }

    cout << "\nFinal Shelf Contents:\n";

    for (int i = 0; i < 10; i++) {
        cout << "Shelf " << i << ": ";

        if (shelves[i].empty()) {
            cout << "Empty";
        } else {
            stack<int> temp = shelves[i];

            while (!temp.empty()) {
                cout << temp.top() << " ";
                temp.pop();
            }
        }

        cout << endl;
    }

    return 0;
}
