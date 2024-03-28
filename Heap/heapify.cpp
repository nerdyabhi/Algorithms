#include <iostream>
using namespace std;

void heapify(int *arr, int n, int i)
{
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int largest = i;

    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void build_heap(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
}

void heap_sort(int arr[], int n)
{
    while (n > 0)
    {
        n--;                  // decrement size
        swap(arr[0], arr[n]); // swap first with last

        heapify(arr, n, 0);
    }
}
int main()
{
    int arr[] = {12, 15, 13, 11, 14};
    int n = sizeof(arr) / sizeof(arr[0]);

    build_heap(arr, n);

    heap_sort(arr, n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}