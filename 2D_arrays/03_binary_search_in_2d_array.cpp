#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // 🔍 Binary search within a specific row
    // Time: O(log n), Space: O(1)
    bool rowSearch(vector<vector<int>>& matrix, int target, int n, int row) {
        int start = 0, end = n - 1;
        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (matrix[row][mid] == target) {
                return true;
            } else if (matrix[row][mid] > target) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return false;
    }

    // 🔍 Binary search across rows to find the potential row
    // Time: O(log m) for row search + O(log n) for column search
    // Total Time: O(log m + log n), Space: O(1)
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();

        int startRow = 0, endRow = m - 1;

        while (startRow <= endRow) {
            int midRow = startRow + (endRow - startRow) / 2;

            // Check if target lies within this row's range
            if (target >= matrix[midRow][0] && target <= matrix[midRow][n - 1]) {
                return rowSearch(matrix, target, n, midRow);
            } else if (target < matrix[midRow][0]) {
                endRow = midRow - 1;
            } else {
                startRow = midRow + 1;
            }
        }

        return false; // Target not found
    }
};

// 🧪 Main function for testing
int main() {
    Solution sol;
    vector<vector<int>> matrix = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}
    };
    int target = 16;

    bool found = sol.searchMatrix(matrix, target);
    cout << "Target " << target << (found ? " found." : " not found.") << endl;

    return 0;
}