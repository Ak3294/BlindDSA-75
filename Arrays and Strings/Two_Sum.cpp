/*
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
You can return the answer in any order.


Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
Example 2:
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int> &nums, int target)
{
    int len = nums.size();
    // First for loop scan 0 to 3
    for (int i = 0; i < len - 1; i++)
    {
        // Scecond For loop scan 1 to 4
        for (int j = i + 1; j < len; j++)
        {
            if (nums[i] + nums[j] == target)
            {
                return {i, j};
            }
        }
    }
    return {};
}

int main(){
    vector<int>nums={2,7,11,15};
    int target = 9;

    vector<int>ans;
    ans = twoSum(nums,target);

    for(int i=0;i<ans.size();i++){
        cout<<nums[ans[i]]<<" ";
    }

}