#include <iostream>
using namespace std;

class Solution {
public:
    // Function to compute x raised to the power n (x^n)
    double myPow(double x, int n) {
        // Convert n to long long to handle INT_MIN safely
        long long power = n;

        // If the exponent is negative, invert the base and make power positive
        if (power < 0) {
            x = 1 / x;
            power = -power;
        }

        double result = 1.0; // This will store the final answer

        // Fast Exponentiation (Binary Exponentiation)
        while (power != 0) {
            // If current power bit is 1 (odd), multiply result with current x
            if (power % 2 == 1)
                result *= x;

            // Square the base for next iteration
            x *= x;

            // Divide the power by 2 (equivalent to right shifting in binary)
            power /= 2;
        }

        return result;
    }
};

int main() {
    Solution sol;

    // Test Cases
    double x1 = 2.0;
    int n1 = 10;
    cout << x1 << "^" << n1 << " = " << sol.myPow(x1, n1) << endl;

    double x2 = 2.0;
    int n2 = -3;
    cout << x2 << "^" << n2 << " = " << sol.myPow(x2, n2) << endl;

    double x3 = 5.0;
    int n3 = 0;
    cout << x3 << "^" << n3 << " = " << sol.myPow(x3, n3) << endl;

    return 0;
}
