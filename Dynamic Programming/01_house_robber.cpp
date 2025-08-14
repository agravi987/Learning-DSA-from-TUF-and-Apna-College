#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Function to calculate the maximum amount that can be robbed
    int rob(vector<int>& nums) {
        int n = nums.size();

        // Edge case: only one house
        if (n == 1) {
            return nums[0];
        }

        // dp[i] stores the max amount that can be robbed from house 0 to i
        vector<int> dp(n);

        // Base cases
        dp[0] = nums[0]; // Only one house to rob
        dp[1] = max(nums[0], nums[1]); // Choose richer of first two houses

        // Fill dp array using recurrence relation
        for (int i = 2; i < n; i++) {
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
        }

        // Final answer is the max amount robbed up to the last house
        return dp[n - 1];
    }
};

// -------- Main function for testing --------
int main() {
    Solution sol;

    // Sample test cases
    vector<int> houses1 = {1, 2, 3, 1};
    vector<int> houses2 = {2, 7, 9, 3, 1};
    vector<int> houses3 = {5};
    vector<int> houses4 = {2, 1, 1, 2};

    cout << "Max rob from houses1: " << sol.rob(houses1) << endl; // Output: 4
    cout << "Max rob from houses2: " << sol.rob(houses2) << endl; // Output: 12
    cout << "Max rob from houses3: " << sol.rob(houses3) << endl; // Output: 5
    cout << "Max rob from houses4: " << sol.rob(houses4) << endl; // Output: 4

    return 0;
}