#include <iostream>
#include <vector>
using namespace std;

// 🚫 Brute Force Approach - O(n^2)
// For each index, multiply all elements except the current one
class BruteForceSolution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, 1);

        for (int i = 0; i < n; i++) {
            int product = 1;
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    product *= nums[j]; // Multiply all elements except self
                }
            }
            result[i] = product;
        }

        return result;
    }
};

// ⚡ Optimized Prefix-Suffix Approach - O(n) time and O(n) space
// No division used
class OptimalSolution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        // Initialize prefix and suffix arrays with 1
        vector<int> prefix(n, 1);
        vector<int> suffix(n, 1);
        vector<int> result(n);

        // Build prefix product array
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] * nums[i - 1];
        }

        // Build suffix product array
        for (int i = n - 2; i >= 0; i--) {
            suffix[i] = suffix[i + 1] * nums[i + 1];
        }

        // Multiply prefix and suffix for the final result
        for (int i = 0; i < n; i++) {
            result[i] = prefix[i] * suffix[i];
        }

        return result;
    }
};

// 🔍 Utility function to print vector
void printVector(const vector<int>& vec) {
    for (int val : vec) {
        cout << val << " ";
    }
    cout << endl;
}

int main() {
    vector<int> input = {1, 2, 3, 4};

    // Test Brute Force
    BruteForceSolution brute;
    vector<int> bruteResult = brute.productExceptSelf(input);
    cout << "Brute Force Result: ";
    printVector(bruteResult);

    // Test Optimal
    OptimalSolution optimal;
    vector<int> optimalResult = optimal.productExceptSelf(input);
    cout << "Optimal Prefix-Suffix Result: ";
    printVector(optimalResult);

    return 0;
}
