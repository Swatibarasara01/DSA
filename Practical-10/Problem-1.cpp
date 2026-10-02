#include <iostream>
using namespace std;

int main() {
    int parking[10];

    for (int i = 0; i < 10; i++) {
        parking[i] = -1;
    }

    int n;
    cout << "Enter number of vehicles: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        int registration;
        cout << "Enter vehicle registration number: ";
        cin >> registration;

        int slot = registration % 10;
        int start = slot;

        while (parking[slot] != -1) {
            slot = (slot + 1) % 10;

            if (slot == start) {
                cout << "Parking lot is full. Vehicle cannot be parked.\n";
                break;
            }
        }

        if (parking[slot] == -1) {
            parking[slot] = registration;
            cout << "Vehicle " << registration
                 << " parked at slot " << slot << endl;
        }
    }

    cout << "\nFinal Parking Lot:\n";
    for (int i = 0; i < 10; i++) {
        if (parking[i] == -1)
            cout << "Slot " << i << ": Empty" << endl;
        else
            cout << "Slot " << i << ": " << parking[i] << endl;
    }

    return 0;
}
