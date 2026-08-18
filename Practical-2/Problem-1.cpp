#include <iostream>
using namespace std;

int linearSearchIterative(int arr[], int n, int target)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == target)
        {
            return i;
        }
    }
    return -1;
}

int linearSearchRecursive(int arr[], int n, int target, int index)
{
    if (index >= n)
    {
        return -1;
    }

    if (arr[index] == target)
    {
        return index;
    }

    return linearSearchRecursive(arr, n, target, index + 1);
}

int main()
{
    int n, target;

    cout << "Enter number of elements: ";
    cin >> n;

    int arr[100];

    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Enter target: ";
    cin >> target;

    int pos1 = linearSearchIterative(arr, n, target);
    int pos2 = linearSearchRecursive(arr, n, target, 0);

    if (pos1 == -1)
        cout << "Iterative: Element not found" << endl;
    else
        cout << "Iterative Position: " << pos1 << endl;

    if (pos2 == -1)
        cout << "Recursive: Element not found" << endl;
    else
        cout << "Recursive Position: " << pos2 << endl;

    return 0;
}
