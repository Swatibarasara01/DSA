#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter number of borrow records: ";
    cin >> n;
    int book[n];
    cout << "Enter Book IDs:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> book[i];
    }
    cout << "Books borrowed more than once:\n";
    for (int i = 0; i < n; i++)
    {
        int count = 1;
        bool printed = false;
        for (int k = 0; k < i; k++)
        {
            if (book[i] == book[k])
            {
                printed = true;
                break;
            }
        }
        if (printed)
            continue;
        for (int j = i + 1; j < n; j++)
        {
            if (book[i] == book[j])
            {
                count++;
            }
        }
        if (count > 1)
        {
            cout << book[i] << " ";
        }
    }
    return 0;
}
