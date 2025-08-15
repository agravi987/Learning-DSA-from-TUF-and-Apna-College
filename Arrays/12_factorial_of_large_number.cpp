#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> factorial(int n) {
        // Initialize result with 1 (i.e., 0! = 1)
        vector<int> res = {1};

        // Loop from 2 to n to compute n!
        for (int i = 2; i <= n; i++) {
            int carry = 0;

            // Multiply current number i with each digit of res
            for (int j = 0; j < res.size(); j++) {
                int val = res[j] * i + carry;
                res[j] = val % 10;      // Store the last digit
                carry = val / 10;       // Carry forward the rest
            }

            // Append remaining carry digits to res
            while (carry) {
                res.push_back(carry % 10);
                carry /= 10;
            }
        }

        // Digits are stored in reverse order, so reverse before returning
        reverse(res.begin(), res.end());
        return res;
    }
};

int main() {
    Solution sol;
    int n;
    cout << "Enter a number to compute its factorial: ";
    cin >> n;

    vector<int> result = sol.factorial(n);

    cout << "Factorial of " << n << " is:\n";
    for (int digit : result) {
        cout << digit;
    }
    cout << endl;

    return 0;
}