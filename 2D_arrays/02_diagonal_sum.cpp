#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size(); // ✅ Number of rows/columns (square matrix)

        // Edge case: 1x1 matrix
        if (n == 1) {
            return mat[0][0];
        }

        int sum = 0;

        // ✅ Traverse both diagonals
        // Primary diagonal: mat[i][i]
        // Secondary diagonal: mat[i][n - 1 - i]
        // Time: O(n), Space: O(1)
        for (int i = 0; i < n; i++) {
            sum += mat[i][i] + mat[i][n - 1 - i];
        }

        // ✅ If n is odd, subtract the center element (double-counted)
        if (n % 2 != 0) {
            sum -= mat[n / 2][n / 2];
        }

        return sum;
    }
};

// 🧪 Main function for testing
int main() {
    Solution sol;
    vector<vector<int>> mat = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int result = sol.diagonalSum(mat);
    cout << "Diagonal sum: " << result << endl;

    return 0;
}