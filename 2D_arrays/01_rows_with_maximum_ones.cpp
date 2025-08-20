#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int rows = mat.size();       // ✅ Get number of rows
        int cols = mat[0].size();    // ✅ Get number of columns

        int maxCount = 0;            // ✅ Track max number of 1s
        int rowIndex = 0;            // ✅ Track row index with max 1s

        // ✅ Traverse each row and count 1s
        for (int i = 0; i < rows; i++) {
            int count1 = 0;
            for (int j = 0; j < cols; j++) {
                if (mat[i][j] == 1) count1++;
            }

            // ✅ Update if current row has more 1s
            if (count1 > maxCount) {
                maxCount = count1;
                rowIndex = i;
            }
        }

        // ✅ Return row index and count of 1s
        return {rowIndex, maxCount};
    }
};

// 🧪 Main function for testing
int main() {
    Solution sol;
    vector<vector<int>> mat = {
        {0, 1, 1},
        {1, 1, 0},
        {0, 0, 1}
    };

    vector<int> result = sol.rowAndMaximumOnes(mat);
    cout << "Row with max 1s: " << result[0] << ", Count: " << result[1] << endl;

    return 0;
}