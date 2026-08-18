#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n, h;
    cout << "Enter number of items: ";
    cin >> n;
    vector<string> items(n);
    cout << "Enter items:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> items[i];
    }
    cout << "Enter number of hours: ";
    cin >> h;
    h = h % n;
    for (int i = 0; i < h; i++)
    {
        string first = items[0];

        for (int j = 0; j < n - 1; j++)
        {
            items[j] = items[j + 1];
        }
        items[n - 1] = first;
    }
    cout << "Final display order:\n";

    for (int i = 0; i < n; i++)
    {
        cout << items[i] << " ";
    }
    return 0;
}