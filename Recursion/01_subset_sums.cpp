#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Definition of the Solution class
class Solution {
public:
    // Helper function to recursively generate subset sums
    void helper(int idx, int sum, vector<int>& ans, vector<int>& arr, int n) {
        // Base case: if we've considered all elements
        if (idx == n) {
            ans.push_back(sum); // Store the current subset sum
            return;
        }

        // Include the current element in the subset
        helper(idx + 1, sum + arr[idx], ans, arr, n);

        // Exclude the current element from the subset
        helper(idx + 1, sum, ans, arr, n);
    }

    // Main function to return all subset sums in sorted order
    vector<int> subsetSums(vector<int>& arr) {
        vector<int> ans;
        helper(0, 0, ans, arr, arr.size()); // Start recursion from index 0 with sum 0
        sort(ans.begin(), ans.end());       // Sort the result for consistency
        return ans;
    }
};

// Driver code to test the subsetSums function
int main() {
    Solution sol;

    // Sample input array
    vector<int> arr = {2, 3};

    // Get all subset sums
    vector<int> result = sol.subsetSums(arr);

    // Print the result
    cout << "Subset sums in sorted order: ";
    for (int sum : result) {
        cout << sum << " ";
    }
    cout << endl;

    return 0;
}