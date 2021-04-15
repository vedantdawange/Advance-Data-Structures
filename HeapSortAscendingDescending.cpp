#include <iostream>

using namespace std;

void Max_Heapify(int arr[], int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest])
        largest = l;

    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        Max_Heapify(arr, n, largest);
    }
}

// Function For creating Max Heap
void Max_HeapSort(int arr[], int n)
{

    for (int i = n / 2 - 1; i >= 0; i--)
        Max_Heapify(arr, n, i);

    for (int i = n - 1; i > 0; i--)
    {

        swap(arr[0], arr[i]);
        Max_Heapify(arr, i, 0);
    }
}

void Min_heapify(int arr[], int n, int i)
{
    int smallest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] < arr[smallest])
        smallest = l;

    if (r < n && arr[r] < arr[smallest])
        smallest = r;

    if (smallest != i)
    {
        swap(arr[i], arr[smallest]);
        Min_heapify(arr, n, smallest);
    }
}

// Function For creating Min Heap
void Min_heapSort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        Min_heapify(arr, n, i);

    for (int i = n - 1; i >= 0; i--)
    {
        swap(arr[0], arr[i]);
        Min_heapify(arr, i, 0);
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

int main()
{
    int data[20];
    int n;

    cout << "\n Enter how many numbers you want to sort(Max 20): ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "\n Enter the number : ";
        cin >> data[i];
    }

    Max_HeapSort(data, n);
    cout << "\n\nAscending Sorted array is : ";
    printArray(data, n);

    Min_heapSort(data, n);
    cout << "\n\nDescending Sorted array is : ";
    printArray(data, n);
}