#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};

Node* insert(Node* root, int value) {
    if (root == NULL)
        return new Node(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

void inorder(Node* root) {
    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    int n;

    cout << "Enter number of books: ";
    cin >> n;

    Node* root = NULL;

    for (int i = 0; i < n; i++) {
        int code;
        cout << "Enter book code " << i + 1 << ": ";
        cin >> code;
        root = insert(root, code);
    }

    cout << "\nInorder sequence: ";
    inorder(root);

    return 0;
}
