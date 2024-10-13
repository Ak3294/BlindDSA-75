#include <iostream>
using namespace std;

int binarySearch(int arr[], int n, int target) {
    int low = 0;
    int high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;  // Avoid potential overflow

        // Check if target is at mid
        if (arr[mid] == target)
            return mid;

        // If target is greater, ignore the left half
        if (arr[mid] < target)
            low = mid + 1;

        // If target is smaller, ignore the right half
        else
            high = mid - 1;
    }

    // Target is not present in the array
    return -1;
}

void printResult(int result, int target) {
    if (result != -1)
        cout << "Element " << target << " found at index " << result << endl;
    else
        cout << "Element " << target << " not found in the array." << endl;
}

int main() {
    int arr[] = {2, 3, 4, 10, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 10;
    
    int result = binarySearch(arr, n, target);
    printResult(result, target);
    
    target = 5;
    result = binarySearch(arr, n, target);
    printResult(result, target);
    
    return 0;
}
