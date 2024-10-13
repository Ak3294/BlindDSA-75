#include <iostream>
using namespace std;

int interpolationSearch(int arr[], int n, int target)
{
    // Initialize low and high
    int low = 0, high = n - 1;

    while (low <= high && target >= arr[low] && target <= arr[high])
    {
        if (low == high)
        {
            if (arr[low] == target)
                return low;
            return -1;
        }

        // Estimate the position of the target using the interpolation formula
        int pos = low + ((target - arr[low]) * (high - low)) / (arr[high] - arr[low]);

        // If the target is found
        if (arr[pos] == target)
            return pos;

        // If the target is larger, ignore the left half
        if (arr[pos] < target)
            low = pos + 1;

        // If the target is smaller, ignore the right half
        else
            high = pos - 1;
    }

    return -1; // Target not found
}

void printResult(int result, int target)
{
    if (result != -1)
        cout << "Element " << target << " found at index " << result << endl;
    else
        cout << "Element " << target << " not found in the array." << endl;
}

int main()
{
    int arr[] = {10, 12, 13, 16, 18, 19, 20, 21, 22, 23, 24, 33, 35, 42, 47};
    int n = sizeof(arr) / sizeof(arr[0]);

    int target = 18;
    int result = interpolationSearch(arr, n, target);
    printResult(result, target);

    target = 30;
    result = interpolationSearch(arr, n, target);
    printResult(result, target);

    return 0;
}
