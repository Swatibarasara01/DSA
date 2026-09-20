#include <iostream>
#include <string>
using namespace std;

struct Node {
    string song;
    Node* prev;
    Node* next;

    Node(string s) {
        song = s;
        prev = NULL;
        next = NULL;
    }
};

class Playlist {
private:
    Node* head;
    Node* tail;

public:

    Playlist() {
        head = NULL;
        tail = NULL;
    }

    void addBeginning(string song) {

        Node* newNode = new Node(song);

        if (head == NULL) {
            head = tail = newNode;
        }
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }

        cout << "Song added at beginning.\n";
        display();
    }

    void addEnd(string song) {

        Node* newNode = new Node(song);

        if (head == NULL) {
            head = tail = newNode;
        }
        else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }

        cout << "Song added at end.\n";
        display();
    }

    void insertAfter(string givenSong, string newSong) {

        Node* current = head;

        while (current != NULL && current->song != givenSong) {
            current = current->next;
        }

        if (current == NULL) {
            cout << "Song \"" << givenSong << "\" not found.\n";
            return;
        }

        Node* newNode = new Node(newSong);

        newNode->prev = current;
        newNode->next = current->next;

        if (current->next != NULL) {
            current->next->prev = newNode;
        }
        else {
            tail = newNode;
        }

        current->next = newNode;

        cout << "Song inserted successfully.\n";
        display();
    }

    void removeFirst() {

        if (head == NULL) {
            cout << "Playlist is empty.\n";
            return;
        }

        Node* temp = head;

        head = head->next;

        if (head != NULL) {
            head->prev = NULL;
        }
        else {
            tail = NULL;
        }

        delete temp;

        cout << "First song removed.\n";
        display();
    }

    int countSongs() {

        int count = 0;
        Node* current = head;

        while (current != NULL) {
            count++;
            current = current->next;
        }

        return count;
    }

    void display() {

        if (head == NULL) {
            cout << "Playlist is empty.\n";
            return;
        }

        Node* current = head;

        cout << "Playlist: ";

        while (current != NULL) {

            cout << current->song;

            if (current->next != NULL) {
                cout << " <-> ";
            }

            current = current->next;
        }

        cout << endl;
        cout << "Total songs: " << countSongs() << endl;
    }
};

int main() {

    Playlist playlist;

    int choice;
    string song;
    string givenSong;
    string newSong;

    do {

        cout << "\n========== MUSIC PLAYLIST ==========\n";
        cout << "1. Add song at beginning\n";
        cout << "2. Add song at end\n";
        cout << "3. Insert song after a specific song\n";
        cout << "4. Remove first song\n";
        cout << "5. Count songs\n";
        cout << "6. Display playlist\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

            case 1:
                cout << "Enter song name: ";
                cin.ignore();
                getline(cin, song);

                playlist.addBeginning(song);
                break;


            case 2:
                cout << "Enter song name: ";
                cin.ignore();
                getline(cin, song);

                playlist.addEnd(song);
                break;


            case 3:
                cout << "Enter existing song name: ";
                cin.ignore();
                getline(cin, givenSong);

                cout << "Enter new song name: ";
                getline(cin, newSong);

                playlist.insertAfter(givenSong, newSong);
                break;


            case 4:
                playlist.removeFirst();
                break;


            case 5:
                cout << "Total songs: "
                     << playlist.countSongs() << endl;
                break;


            case 6:
                playlist.display();
                break;


            case 7:
                cout << "Program ended.\n";
                break;


            default:
                cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 7);

    return 0;
}
