#include <iostream>
#include <string>
using namespace std;

class Solution {
    // Helper function to convert Roman character to its integer value
    int val(char ch) {
        if (ch == 'I') return 1;
        else if (ch == 'V') return 5;
        else if (ch == 'X') return 10;
        else if (ch == 'L') return 50;
        else if (ch == 'C') return 100;
        else if (ch == 'D') return 500;
        else if (ch == 'M') return 1000;
        else return 0; // Invalid character
    }

public:
    // Main function to convert Roman numeral string to integer
    int romanToInt(string s) {
        int ans = 0;

        // Traverse the string from left to right, except the last character
        for (int i = 0; i < s.size() - 1; i++) {
            // If current value is less than next, subtract it (e.g., IV = 5 - 1)
            if (val(s[i]) < val(s[i + 1])) {
                ans -= val(s[i]);
            } else {
                ans += val(s[i]);
            }
        }

        // Add the last character's value
        ans += val(s[s.size() - 1]);

        return ans;
    }
};

// -------- Main function for testing --------
int main() {
    Solution sol;

    // Sample test cases
    string roman1 = "III";     // 3
    string roman2 = "IV";      // 4
    string roman3 = "IX";      // 9
    string roman4 = "LVIII";   // 58
    string roman5 = "MCMXCIV"; // 1994

    cout << "Roman: " << roman1 << " → Integer: " << sol.romanToInt(roman1) << endl;
    cout << "Roman: " << roman2 << " → Integer: " << sol.romanToInt(roman2) << endl;
    cout << "Roman: " << roman3 << " → Integer: " << sol.romanToInt(roman3) << endl;
    cout << "Roman: " << roman4 << " → Integer: " << sol.romanToInt(roman4) << endl;
    cout << "Roman: " << roman5 << " → Integer: " << sol.romanToInt(roman5) << endl;

    return 0;
}