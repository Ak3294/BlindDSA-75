/*
Problem Statement:
Given a sorted array, remove the duplicates in-place such that each element appears only once and return the new length. The relative order of the elements should be maintained, and you must not use extra space for another array (in-place modification).

Approach:
1.Since the array is sorted, all duplicates will be adjacent. We can use two pointers:
2.Pointer i keeps track of the position of the last unique element.
3.Pointer j traverses the array and checks for duplicates.
4.If the element at j is different from the element at i, move i forward and update i's position with the value of j.
*/

#include <iostream>
#include <vector>
using namespace std;

// Function to remove duplicates from a sorted array
int removeDuplicates(vector<int> &nums)
{
    if (nums.empty())
    {
        return 0;
    }

    int i = 0; // Pointer to track the position of the last unique element

    for (int j = 1; j < nums.size(); ++j)
    {
        if (nums[j] != nums[i])
        {
            i++;               // Move to the next unique position
            nums[i] = nums[j]; // Update the next unique element
        }
    }

    return i + 1; // Return the length of the array with unique elements
}

int main()
{
    vector<int> nums = {1, 1, 2, 2, 3, 4, 4, 5}; // Example test case

    int newLength = removeDuplicates(nums);

    // Print the result
    cout << "Array after removing duplicates: ";
    for (int i = 0; i < newLength; ++i)
    {
        cout << nums[i] << " ";
    }
    cout << endl;

    cout << "New length: " << newLength << endl;

    return 0;
}
