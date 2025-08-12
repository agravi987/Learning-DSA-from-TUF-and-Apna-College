#include <iostream>
#include <vector>
using namespace std;

void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    cout << endl;
}

/* -------------------- Brute Force Approach -------------------- */
// Time: O(m*n*(m+n)) + O(m*n) ≈ O(n³)
// Space: O(1)
class BruteSolution {
    int m, n;

    // Marks entire row with a placeholder if not already zero
    void mark_row(vector<vector<int>>& matrix, int i) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] != 0)
                matrix[i][j] = -201; // placeholder
        }
    }

    // Marks entire column with a placeholder if not already zero
    void mark_col(vector<vector<int>>& matrix, int j) {
        for (int i = 0; i < m; i++) {
            if (matrix[i][j] != 0)
                matrix[i][j] = -201;
        }
    }

public:
    void setZeroes(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();

        // First pass: mark rows and columns
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    mark_row(matrix, i);
                    mark_col(matrix, j);
                }
            }
        }

        // Second pass: convert placeholders to zero
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == -201)
                    matrix[i][j] = 0;
            }
        }
    }
};

/* -------------------- Better Approach -------------------- */
// Time: O(m*n)
// Space: O(m + n)
class BetterSolution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> row(m, 0);
        vector<int> col(n, 0);

        // First pass: record zero positions
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    row[i] = 1;
                    col[j] = 1;
                }
            }
        }

        // Second pass: zero out marked rows and columns
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (row[i] == 1 || col[j] == 1)
                    matrix[i][j] = 0;
            }
        }
    }
};

/* -------------------- Optimal Approach -------------------- */
// Time: O(m*n)
// Space: O(1)
class OptimalSolution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        bool firstRowZero = false, firstColZero = false;

        // Check if first row has zero
        for (int j = 0; j < n; j++) {
            if (matrix[0][j] == 0) {
                firstRowZero = true;
                break;
            }
        }

        // Check if first column has zero
        for (int i = 0; i < m; i++) {
            if (matrix[i][0] == 0) {
                firstColZero = true;
                break;
            }
        }

        // Use first row and column as markers
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        // Zero out cells based on markers
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
            }
        }

        // Zero out first row if needed
        if (firstRowZero) {
            for (int j = 0; j < n; j++)
                matrix[0][j] = 0;
        }

        // Zero out first column if needed
        if (firstColZero) {
            for (int i = 0; i < m; i++)
                matrix[i][0] = 0;
        }
    }
};

/* -------------------- Main Function -------------------- */
int main() {
    vector<vector<int>> input = {
        {1, 2, 3},
        {4, 0, 6},
        {7, 8, 9}
    };

    // Brute
    vector<vector<int>> bruteMatrix = input;
    BruteSolution brute;
    brute.setZeroes(bruteMatrix);
    cout << "Brute Solution:\n";
    printMatrix(bruteMatrix);

    // Better
    vector<vector<int>> betterMatrix = input;
    BetterSolution better;
    better.setZeroes(betterMatrix);
    cout << "Better Solution:\n";
    printMatrix(betterMatrix);

    // Optimal
    vector<vector<int>> optimalMatrix = input;
    OptimalSolution optimal;
    optimal.setZeroes(optimalMatrix);
    cout << "Optimal Solution:\n";
    printMatrix(optimalMatrix);

    return 0;
}