#include <iostream>
#include <vector>
using namespace std;

// Merge function that merges two halves and counts inversions
int mergeAndCount(vector<int> &arr, int left, int mid, int right)
{
    vector<int> leftArr(arr.begin() + left, arr.begin() + mid + 1);
    vector<int> rightArr(arr.begin() + mid + 1, arr.begin() + right + 1);

    int i = 0, j = 0, k = left, inversions = 0;

    while (i < leftArr.size() && j < rightArr.size())
    {
        if (leftArr[i] <= rightArr[j])
        {
            arr[k++] = leftArr[i++];
        }
        else
        {
            arr[k++] = rightArr[j++];
            inversions += (leftArr.size() - i); // Count inversions
        }
    }

    // Copy remaining elements, if any
    while (i < leftArr.size())
    {
        arr[k++] = leftArr[i++];
    }
    while (j < rightArr.size())
    {
        arr[k++] = rightArr[j++];
    }

    return inversions;
}

// Merge sort function that recursively sorts and counts inversions
int mergeSortAndCount(vector<int> &arr, int left, int right)
{
    int inversions = 0;
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        // Count inversions in the left half
        inversions += mergeSortAndCount(arr, left, mid);

        // Count inversions in the right half
        inversions += mergeSortAndCount(arr, mid + 1, right);

        // Count split inversions (i.e., inversions across the two halves)
        inversions += mergeAndCount(arr, left, mid, right);
    }
    return inversions;
}

int main()
{
    vector<int> arr = {2, 4, 1, 3, 5};
    int n = arr.size();

    // Count the number of inversions
    int inversionCount = mergeSortAndCount(arr, 0, n - 1);

    cout << "Number of inversions: " << inversionCount << endl;

    return 0;
}
