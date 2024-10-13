#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to swap two elements
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function, similar to the one in QuickSort
int partition(vector<int> &arr, int low, int high)
{
    int pivot = arr[high]; // Pivot element is chosen as the last element
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

// Quickselect function to find the kth smallest element
int quickSelect(vector<int> &arr, int low, int high, int k)
{
    if (low <= high)
    {
        int pi = partition(arr, low, high);

        // If the partitioning index is equal to k-1, we found the kth smallest
        if (pi == k - 1)
            return arr[pi];

        // If pi is greater, the kth smallest is in the left partition
        if (pi > k - 1)
            return quickSelect(arr, low, pi - 1, k);

        // Otherwise, it's in the right partition
        return quickSelect(arr, pi + 1, high, k);
    }

    return -1; // This should not be reached if k is valid
}

int main()
{
    vector<int> arr = {12, 3, 5, 7, 19, 2, 4};
    int n = arr.size();
    int k = 3; // We want the 3rd smallest element

    // Find the kth smallest element
    int result = quickSelect(arr, 0, n - 1, k);

    if (result != -1)
        cout << "The " << k << "rd smallest element is " << result << endl;
    else
        cout << "Invalid input." << endl;

    return 0;
}
