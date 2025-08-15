#include <iostream>
#include <string>
#include <climits>
using namespace std;

class Solution {
public:
    // Converts a string to an integer following atoi rules
    int myAtoi(string s) {
        int i = 0, n = s.size();
        long ans = 0;           // Use long to detect overflow
        bool negative = false;  // Tracks if the number is negative

        // Step 1: Skip leading whitespaces
        while (i < n && s[i] == ' ') i++;

        // Step 2: Handle optional single '+' or '-' sign
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            negative = (s[i] == '-');
            i++;
        }

        // Step 3: If next character is not a digit, return 0
        if (i >= n || !isdigit(s[i])) return 0;

        // Step 4: Parse digits and build the number
        while (i < n && isdigit(s[i])) {
            ans = ans * 10 + (s[i] - '0');

            // Step 5: Clamp to INT_MAX or INT_MIN if overflow occurs
            if (!negative && ans > INT_MAX) return INT_MAX;
            if (negative && -ans < INT_MIN) return INT_MIN;

            i++;
        }

        // Step 6: Return final result with correct sign
        return negative ? -ans : ans;
    }
};

/*
Time Complexity: O(n)
- We scan the string once, skipping whitespace, checking sign, and parsing digits.

Space Complexity: O(1)
- No extra space used beyond a few variables.
*/

int main() {
    Solution sol;

    // Sample test cases
    string s1 = "42";
    string s2 = "   -42";
    string s3 = "4193 with words";
    string s4 = "words and 987";
    string s5 = "-91283472332";
    string s6 = "+-12";
    string s7 = "--12";
    string s8 = "0000012345";

    cout << "Input: \"" << s1 << "\" → Output: " << sol.myAtoi(s1) << endl;
    cout << "Input: \"" << s2 << "\" → Output: " << sol.myAtoi(s2) << endl;
    cout << "Input: \"" << s3 << "\" → Output: " << sol.myAtoi(s3) << endl;
    cout << "Input: \"" << s4 << "\" → Output: " << sol.myAtoi(s4) << endl;
    cout << "Input: \"" << s5 << "\" → Output: " << sol.myAtoi(s5) << endl;
    cout << "Input: \"" << s6 << "\" → Output: " << sol.myAtoi(s6) << endl;
    cout << "Input: \"" << s7 << "\" → Output: " << sol.myAtoi(s7) << endl;
    cout << "Input: \"" << s8 << "\" → Output: " << sol.myAtoi(s8) << endl;

    return 0;
}