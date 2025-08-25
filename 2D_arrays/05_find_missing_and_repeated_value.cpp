#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    /*
    Function: findMissingAndRepeatedValues
    Purpose: Given an n x n grid containing numbers from 1 to n^2,
             find the one repeated number and the one missing number.

    Time Complexity:
    - O(n^2): Traverses all elements in the grid once
    - O(1): Average time for unordered_set operations (insert/find)

    Space Complexity:
    - O(n^2): In worst case, stores all unique values in the set
    */
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        unordered_set<int> seen;  // Tracks unique values
        int n = grid.size();      // Grid is n x n

        vector<int> ans;          // Result: [repeated, missing]
        int sum = 0;              // Sum of unique values

        // Traverse the grid to find repeated value and compute sum
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int val = grid[i][j];

                // If already seen, it's the repeated value
                if (seen.find(val) != seen.end()) {
                    ans.push_back(val);  // Repeated value
                } else {
                    sum += val;          // Add to sum if unique
                }

                seen.insert(val);        // Mark value as seen
            }
        }

        // Total expected sum of numbers from 1 to n^2
        int total = (n * n * (n * n + 1)) / 2;

        // Missing value = total expected - sum of unique values
        int missing = total - sum;
        ans.push_back(missing);  // Append missing value

        return ans;  // Final result: [repeated, missing]
    }
};

int main() {
    Solution sol;

    /*
    Test Case:
    Grid = 3x3 = 9 elements
    Expected numbers: 1 to 9
    Repeated: 8
    Missing: 9
    */
    vector<vector<int>> grid = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 8}
    };

    vector<int> result = sol.findMissingAndRepeatedValues(grid);

    cout << "Repeated Value: " << result[0] << "\n";
    cout << "Missing Value: " << result[1] << "\n";

    return 0;
}