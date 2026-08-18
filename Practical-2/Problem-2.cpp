#include <iostream>
using namespace std;

int binarySearchIterative(int arr[], int n, int target)
{
    int low = 0, high = n - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}

int binarySearchRecursive(int arr[], int low, int high, int target)
{
    if (low > high)
        return -1;

    int mid = (low + high) / 2;

    if (arr[mid] == target)
        return mid;

    if (arr[mid] < target)
        return binarySearchRecursive(arr, mid + 1, high, target);

    return binarySearchRecursive(arr, low, mid - 1, target);
}

int main()
{
    int n, target;

    cout << "Enter number of elements: ";
    cin >> n;

    int arr[100];

    cout << "Enter sorted elements:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Enter target: ";
    cin >> target;

    int pos1 = binarySearchIterative(arr, n, target);
    int pos2 = binarySearchRecursive(arr, 0, n - 1, target);

    if (pos1 == -1)
        cout << "Iterative: Element not found\n";
    else
        cout << "Iterative Position: " << pos1 << endl;

    if (pos2 == -1)
        cout << "Recursive: Element not found\n";
    else
        cout << "Recursive Position: " << pos2 << endl;

    return 0;
}
