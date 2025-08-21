#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    /*
     * Function: searchMatrix
     * ----------------------
     * Searches for a target value in a 2D matrix where:
     * - Each row is sorted in ascending order (left to right)
     * - Each column is sorted in ascending order (top to bottom)
     *
     * Strategy:
     * Start from the top-right corner and move:
     * - LEFT if current value > target
     * - DOWN if current value < target
     *
     * This works because:
     * - Moving left decreases the value (row is sorted)
     * - Moving down increases the value (column is sorted)
     *
     * Time Complexity: O(m + n) — worst case touches one full row and one full column
     * Space Complexity: O(1) — constant space, no extra data structures used
     */
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();       // Total number of rows
        int n = matrix[0].size();    // Total number of columns

        // ✅ Start from top-right corner: matrix[0][n-1]
        // This position gives us maximum flexibility to move in both directions
        int row = 0;
        int col = n - 1;

        // 🔁 Loop until we go out of bounds
        while (row < m && col >= 0) {
            int current = matrix[row][col];

            // 🎯 Case 1: Target found
            if (current == target) {
                return true;
            }

            // ⬅️ Case 2: Target is smaller → move left to smaller values
            else if (target < current) {
                col--;
            }

            // ⬇️ Case 3: Target is larger → move down to larger values
            else {
                row++;
            }
        }

        // ❌ Target not found after exhausting valid positions
        return false;
    }
};

// 🧪 Main function for testing
int main() {
    Solution sol;

    // 📋 Sample matrix: each row and column is sorted
    vector<vector<int>> matrix = {
        {1, 4, 7, 11},
        {12, 15, 20, 25},
        {30, 34, 50, 60}
    };

    int target = 20;

    // 🔍 Search for the target
    bool found = sol.searchMatrix(matrix, target);

    // 📤 Output result
    cout << "Target " << target << (found ? " found." : " not found.") << endl;

    return 0;
}