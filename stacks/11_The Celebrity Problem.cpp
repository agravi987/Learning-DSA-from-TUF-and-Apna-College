#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    // Function to find the celebrity in a party
    int celebrity(vector<vector<int>>& mat) {
        int n = mat.size(); // Number of people at the party

        stack<int> st;

        // Step 1: Push all people into the stack
        for (int i = 0; i < n; i++) {
            st.push(i);
        }

        // Step 2: Eliminate non-celebrities using pairwise comparison
        while (st.size() > 1) {
            int A = st.top(); st.pop();
            int B = st.top(); st.pop();

            // If A knows B, A can't be a celebrity
            // If A doesn't know B, B can't be a celebrity
            if (mat[A][B] == 1) {
                st.push(B);
            } else {
                st.push(A);
            }
        }

        // Step 3: Final candidate from stack
        int candidate = st.top();

        // Step 4: Validate candidate
        // Celebrity should:
        // - Know no one: mat[candidate][j] == 0 for all j ≠ candidate
        // - Be known by everyone: mat[j][candidate] == 1 for all j ≠ candidate
        for (int j = 0; j < n; j++) {
            if (j != candidate) {
                if (mat[candidate][j] == 1 || mat[j][candidate] == 0) {
                    return -1; // Not a celebrity
                }
            }
        }

        return candidate; // Valid celebrity found
    }
};

// ------------------ MAIN FUNCTION FOR TESTING ------------------

int main() {
    Solution sol;

    // Example matrix:
    // Person i knows person j if mat[i][j] == 1
    // Let's say person 2 is the celebrity:
    // - Everyone knows person 2
    // - Person 2 knows no one

    vector<vector<int>> mat = {
        {0, 1, 1},
        {0, 0, 1},
        {0, 0, 0}
    };

    int result = sol.celebrity(mat);

    if (result == -1) {
        cout << "No celebrity found in the party." << endl;
    } else {
        cout << "Celebrity is person with index: " << result << endl;
    }

    return 0;
}