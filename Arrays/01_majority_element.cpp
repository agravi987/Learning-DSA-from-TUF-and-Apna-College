// 🎯 Leetcode 169: Majority Element
// 🏆 The Majority Element appears more than ⌊n/2⌋ times in an array.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // 🟠 1️⃣ Brute Force Approach - O(n²) (Slow 🐌)
    int majorityElementBruteForce(vector<int>& nums) {
        int n = nums.size();
        
        // 🧮 Count frequency of each element
        for(int val : nums){
            int freq = 0;
            for(int ele : nums){
                if(val == ele) freq++;

                // ✅ If frequency > n/2, return the majority element
                if(freq > n/2) return val;
            }
        }
        return -1;  // ❌ No majority element (shouldn’t happen as per problem constraints)
    }

    // 🟡 2️⃣ Sorting Approach - O(n log n) (Faster ⚡)
    int majorityElementSorting(vector<int>& nums) {
        sort(nums.begin(), nums.end()); // 🔀 Sorting the array
        return nums[nums.size()/2];  // ✅ Majority element is at mid
    }

    // 🟢 3️⃣ Moore’s Voting Algorithm - O(n) (Best ✅)
    int majorityElementMooreVoting(vector<int>& nums) {
        int freq = 0, ans = 0;
        
        // 🗳️ Voting phase
        for(int num : nums){
            if(freq == 0) ans = num;  // Pick new candidate
            freq += (num == ans) ? 1 : -1;  // ✅ Vote for candidate or against
        }
        return ans; // 🎯 Majority element
    }
};

// 🚀 Driver Code
int main() {
    Solution sol;
    vector<int> nums = {2,2,1,1,1,2,2};

    cout << "🔹 Brute Force Output: " << sol.majorityElementBruteForce(nums) << endl;
    cout << "🔹 Sorting Approach Output: " << sol.majorityElementSorting(nums) << endl;
    cout << "🔹 Moore’s Voting Algorithm Output: " << sol.majorityElementMooreVoting(nums) << endl;

    return 0;
}
