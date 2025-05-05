/*
    Problem: Maximum Subarray (LeetCode #53)
    -----------------------------------------
    Given an integer array nums, find the contiguous subarray (containing at least one number)
    which has the largest sum and return its sum.

    Example:
    Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
    Output: 6
    Explanation: [4,-1,2,1] has the largest sum = 6.
*/

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

// ------------------- Brute Force Approach -------------------
// Time Complexity: O(n^2)
// Space Complexity: O(1)
int maxSubArrayBruteForce(vector<int>& nums) {
    int maxSum = INT_MIN;
    int n = nums.size();

    for(int i = 0; i < n; ++i) {
        int sum = 0;
        for(int j = i; j < n; ++j) {
            sum += nums[j];
            maxSum = max(maxSum, sum);
        }
    }
    return maxSum;
}

// ------------------- Kadane's Algorithm -------------------
// Time Complexity: O(n)
// Space Complexity: O(1)
int maxSubArrayKadane(vector<int>& nums) {
    int currSum = 0, maxSum = INT_MIN;

    for(int num : nums) {
        currSum += num;
        maxSum = max(maxSum, currSum);

        if(currSum < 0) {
            currSum = 0;
        }
    }
    return maxSum;
}

// ------------------- Main Function -------------------
int main() {
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    cout << "Brute Force Result: " << maxSubArrayBruteForce(nums) << endl;
    cout << "Kadane's Algorithm Result: " << maxSubArrayKadane(nums) << endl;

    return 0;
}
