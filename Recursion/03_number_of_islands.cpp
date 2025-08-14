#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Depth-First Search to mark all connected land cells as visited
    void dfs(vector<vector<char>>& grid, int i, int j) {
        // Boundary check: stop if out of bounds
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size()) return;

        // Skip if cell is water ('0') or already visited ('V')
        if (grid[i][j] == '0' || grid[i][j] == 'V') return;

        // Mark current land cell as visited
        grid[i][j] = 'V';

        // Explore all 4 adjacent directions
        dfs(grid, i + 1, j); // Down
        dfs(grid, i - 1, j); // Up
        dfs(grid, i, j + 1); // Right
        dfs(grid, i, j - 1); // Left
    }

    // Main function to count the number of islands
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        int row = grid.size();
        int col = grid[0].size();

        // Traverse every cell in the grid
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                // If cell is unvisited land, start DFS and count one island
                if (grid[i][j] == '1') {
                    dfs(grid, i, j);
                    count++;
                }
            }
        }

        return count;
    }
};

// -------- Main function for testing --------
int main() {
    Solution sol;

    // Sample grid: 3 islands
    vector<vector<char>> grid = {
        {'1','1','0','0','0'},
        {'1','1','0','0','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'}
    };

    int result = sol.numIslands(grid);
    cout << "Number of islands: " << result << endl; // Output: 3

    return 0;
}