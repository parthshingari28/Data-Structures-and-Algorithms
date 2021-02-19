#include <iostream>
using namespace std;
int Partition(int arr[], int start, int end)
{
    // Pick the rightmost element as a pivot from the array
    int pivot = arr[end];
    // elements less than the pivot will be pushed to the left of `pIndex`
    // elements more than the pivot will be pushed to the right of `pIndex`
    // equal elements can go either way
    int pIndex = start;
    // each time we find an element less than or equal to the pivot, `pIndex`
    // is incremented, and that element would be placed before the pivot.
    for (int i = start; i < end; i++)
    {
        if (arr[i] <= pivot)
        {
            swap(arr[i], arr[pIndex]);
            pIndex++;
        }
    }
    // swap `pIndex` with pivot
    swap (arr[pIndex], arr[end]);
    // return `pIndex` (index of the pivot element)
    return pIndex;
}
// Quicksort routine
void quicksort(int arr[] ,int start, int end)
{
    // base condition
    if (start >= end)
        return;
    // rearrange elements across pivot
    int pivot = Partition(arr, start, end);
    // recur on subarray containing elements that are less than the pivot
    quicksort(arr, start, pivot - 1);
    // recur on subarray containing elements that are more than the pivot
    quicksort(arr, pivot + 1, end);
}
 
// C++ implementation of the Quicksort algorithm
int main()
{
    int arr[] = { 9, -3, 5, 2, 6, 8, -6, 1, 3 };
    int n = sizeof(arr)/sizeof(arr[0]);
    quicksort(arr, 0, n - 1);
    // print the sorted array
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}


