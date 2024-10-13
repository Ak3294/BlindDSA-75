/*
Kadane’s Algorithm for Maximum Subarray Sum
Problem Statement: Given an array of integers, find the contiguous subarray (containing at least one number)
that has the largest sum and return that sum.

Approach:
1. Kadane’s Algorithm efficiently solves this problem in O(n) time. It iterates through the array and keeps track of two values:
  - current_sum: the maximum sum of the subarray that ends at the current position.
  - max_sum: the maximum sum encountered so far.
2. At each step, Kadane’s algorithm decides whether to:
  - Add the current element to the existing subarray (current_sum + arr[i]).
3. Start a new subarray with the current element (arr[i]).

*/

#include <iostream>
#include <vector>
#include <climits> // For INT_MIN
using namespace std;

// Function to implement Kadane's Algorithm to find the maximum subarray sum
int maxSubArraySum(const vector<int> &nums)
{
    int max_sum = INT_MIN; // Initialize with the smallest possible value
    int current_sum = 0;

    for (int i = 0; i < nums.size(); ++i)
    {
        current_sum = max(nums[i], current_sum + nums[i]); // Include current element or start fresh
        max_sum = max(max_sum, current_sum);               // Update max_sum if current_sum is higher
    }

    return max_sum;
}

int main()
{
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4}; // Example test case

    int result = maxSubArraySum(nums);
    cout << "Maximum subarray sum is: " << result << endl;

    return 0;
}
