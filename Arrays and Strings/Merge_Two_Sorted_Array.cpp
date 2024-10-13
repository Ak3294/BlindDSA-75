/*
To merge two sorted arrays into one sorted array optimally, you can take advantage of the fact that both input arrays are already sorted. The optimal approach is to use a two-pointer technique to merge them in O(n + m) time, where n and m are the lengths of the two arrays.

Approach:
Use two pointers: one pointing to the current element of the first array, and the other pointing to the current element of the second array.
Compare the elements at both pointers, and append the smaller element to the result array.
Move the pointer forward for the array from which the element was taken.
Once one of the arrays is fully traversed, append the remaining elements of the other array.

*/

#include <iostream>
#include <vector>
using namespace std;

// Function to merge two sorted arrays
vector<int> mergeSortedArrays(const vector<int> &arr1, const vector<int> &arr2)
{
    vector<int> result;
    int i = 0, j = 0; // Pointers for arr1 and arr2

    // Traverse both arrays
    while (i < arr1.size() && j < arr2.size())
    {
        if (arr1[i] < arr2[j])
        {
            result.push_back(arr1[i]);
            i++;
        }
        else
        {
            result.push_back(arr2[j]);
            j++;
        }
    }

    // If there are remaining elements in arr1
    while (i < arr1.size())
    {
        result.push_back(arr1[i]);
        i++;
    }

    // If there are remaining elements in arr2
    while (j < arr2.size())
    {
        result.push_back(arr2[j]);
        j++;
    }

    return result;
}

int main()
{
    vector<int> arr1 = {1, 3, 5, 7}; // Example test case 1
    vector<int> arr2 = {2, 4, 6, 8}; // Example test case 2

    vector<int> mergedArray = mergeSortedArrays(arr1, arr2);

    // Print the merged sorted array
    cout << "Merged array: ";
    for (int num : mergedArray)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
