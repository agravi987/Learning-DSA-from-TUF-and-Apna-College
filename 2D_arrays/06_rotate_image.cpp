#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Brute force approach: uses extra space to store rotated version
// Time: O(n^2), Space: O(n^2)
class Solution1 {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> ans(n, vector<int>(n)); // temporary matrix

        // Place each element at its rotated position
        // (i, j) → (j, n - i - 1)
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                ans[j][n - i - 1] = matrix[i][j];
            }
        }

        // Copy rotated matrix back to original
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                matrix[i][j] = ans[i][j];
            }
        }
    }
};

// Optimized approach: transpose + reverse rows
// Time: O(n^2), Space: O(1)
class Solution2 {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        // Step 1: Transpose the matrix (swap across diagonal)
        // Only swap upper triangle to avoid double swapping
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // Step 2: Reverse each row to complete 90° rotation
        for (int i = 0; i < n; i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};

int main() {
    vector<vector<int>> mat = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    // Choose which solution to test
    Solution2 sol; // Try Solution1 or Solution2

    cout << "Original Matrix:\n";
    for (auto& row : mat) {
        for (int val : row) cout << val << " ";
        cout << "\n";
    }

    sol.rotate(mat); // Rotate the matrix

    cout << "\nRotated Matrix:\n";
    for (auto& row : mat) {
        for (int val : row) cout << val << " ";
        cout << "\n";
    }

    return 0;
}