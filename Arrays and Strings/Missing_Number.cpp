/*
Problem Statement:
You are given an array containing n distinct numbers from 1 to n+1. One number is missing from the array.
Write a function to find the missing number.

Approach:
The most efficient approach to finding the missing number is by calculating the expected sum of the
numbers from 1 to n+1 and comparing it to the actual sum of the array. The difference between these two sums gives the missing number.

*/

#include <iostream>
#include <vector>
using namespace std;

// Function to find the missing number in the array
int findMissingNumber(const vector<int> &nums)
{
    int n = nums.size() + 1;         // Since one number is missing, the total count is size + 1
    int total_sum = n * (n + 1) / 2; // Sum of numbers from 1 to n+1

    int actual_sum = 0;
    for (int num : nums)
    {
        actual_sum += num; // Sum of elements in the given array
    }

    return total_sum - actual_sum; // The missing number
}

int main()
{
    vector<int> nums = {1, 2, 4, 5, 6}; // Example test case
    int missingNumber = findMissingNumber(nums);

    cout << "The missing number is: " << missingNumber << endl;

    return 0;
}
