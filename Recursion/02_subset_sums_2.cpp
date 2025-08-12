#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Recursive helper to generate unique subsets
    void UniqueSubset(int idx, vector<int>& current, vector<int>& nums, vector<vector<int>>& ans) {
        ans.push_back(current); // Add current subset

        for (int i = idx; i < nums.size(); i++) {
            // Skip duplicates at the same recursive level
            if (i != idx && nums[i] == nums[i - 1]) continue;

            current.push_back(nums[i]);              // Include nums[i]
            UniqueSubset(i + 1, current, nums, ans); // Recurse
            current.pop_back();                      // Backtrack
        }
    }

    // Main function to return all unique subsets
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> current;

        sort(nums.begin(), nums.end()); // Sort to group duplicates
        UniqueSubset(0, current, nums, ans);

        return ans;
    }
};

// Driver code to test the function
int main() {
    Solution sol;
    vector<int> nums = {1, 2, 2};

    vector<vector<int>> result = sol.subsetsWithDup(nums);

    cout << "Unique subsets:\n";
    for (const auto& subset : result) {
        cout << "[ ";
        for (int num : subset) {
            cout << num << " ";
        }
        cout << "]\n";
    }

    return 0;
}