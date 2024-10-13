/*
Variation - 1: Given an integer array nums, find the subarray with the largest sum, and return its sum.
Example 1:
Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: The subarray [4,-1,2,1] has the largest sum 6.
*/

#include <bits/stdc++.h>
using namespace std;

int maximumSubarray(vector<int> nums)
{
    int n = nums.size();
    int maxi = INT_MIN;
    int curr = 0;
    for (int i = 0; i < n; i++)
    {
        curr += nums[i];
        maxi = max(maxi, curr);
        if (curr < 0)
        {
            curr = 0;
        }
    }
    return maxi;
}

int main()
{

    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int ans = maximumSubarray(nums);

    cout << ans << endl;
    return 0;
}

/* Variation-2 : Maximum Ascending Subarrary Sum
Given an array of positive integers nums, return the maximum possible sum of an ascending subarray in nums.

A subarray is defined as a contiguous sequence of numbers in an array.

A subarray [nums[l], nums[l+1], ..., nums[r-1], nums[r]] is ascending if for all i where l <= i < r, nums[i]  < nums[i+1].
Note that a subarray of size 1 is ascending.

Input: nums = [10,20,30,40,50]
Output: 150
Explanation: [10,20,30,40,50] is the ascending subarray with the maximum sum of 150.
*/

/*
#include <bits/stdc++.h>
using namespace std;

int maxAscendingSum(vector<int> &nums)
{
    int n = nums.size();
    int currsum = nums[0];
    int maxsum = nums[0];
    int i = 1;
    while (i < n)
    {
        if (nums[i] > nums[i - 1])
        {
            currsum += nums[i];
        }
        else
        {
            maxsum = max(maxsum, currsum);
            currsum = nums[i];
        }
        i++;
    }
    maxsum = max(maxsum, currsum);
    return maxsum;
}

int main()
{

    vector<int> nums = {10, 20, 30, 5, 10, 50};
    int ans = maxAscendingSum(nums);

    cout << ans << endl;
    return 0;
}

*/