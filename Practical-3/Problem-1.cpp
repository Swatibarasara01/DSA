#include <iostream>
using namespace std;

void printArray(int arr[], int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Bubble Sort
void bubbleSort(int arr[], int n)
{
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = 0; j < n - i - 1; j++)
        {
            if(arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Insertion Sort
void insertionSort(int arr[], int n)
{
    for(int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while(j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

// Selection Sort
void selectionSort(int arr[], int n)
{
    for(int i = 0; i < n - 1; i++)
    {
        int minIndex = i;

        for(int j = i + 1; j < n; j++)
        {
            if(arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }

        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

int main()
{
    int n;

    cout << "Enter number of answer sheets: ";
    cin >> n;

    int marks[n];

    cout << "Enter marks:\n";
    for(int i = 0; i < n; i++)
    {
        cin >> marks[i];
    }

    int bubble[n], insertion[n], selection[n];

    for(int i = 0; i < n; i++)
    {
        bubble[i] = marks[i];
        insertion[i] = marks[i];
        selection[i] = marks[i];
    }

    // Bubble Sort
    bubbleSort(bubble, n);
    cout << "\nBubble Sort Result:\n";
    printArray(bubble, n);

    // Insertion Sort
    insertionSort(insertion, n);
    cout << "\nInsertion Sort Result:\n";
    printArray(insertion, n);

    // Selection Sort
    selectionSort(selection, n);
    cout << "\nSelection Sort Result:\n";
    printArray(selection, n);

    return 0;
}
