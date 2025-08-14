#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    // Converts an integer to its Roman numeral representation
    string intToRoman(int num) {
        // Roman numeral mappings in descending order
        int values[] =    {1000, 900, 500, 400, 100, 90,  50,  40,  10,  9,   5,  4,  1};
        string symbols[] = {"M", "CM","D", "CD","C","XC","L","XL","X","IX","V","IV","I"};

        string result = "";

        // Greedy matching: subtract largest possible value repeatedly
        for (int i = 0; i < 13; i++) {
            while (num >= values[i]) {
                result += symbols[i];
                num -= values[i];
            }
        }

        return result;
    }
};

/*
Time Complexity: O(1)
- The loop runs at most 13 * (num / smallest value), but since Roman numerals are bounded (1–3999),
  the number of iterations is constant and small.

Space Complexity: O(1)
- Only a fixed-size array and a string are used. No dynamic memory allocation based on input size.
*/

int main() {
    Solution sol;

    // Sample test cases
    int num1 = 3;      // III
    int num2 = 4;      // IV
    int num3 = 9;      // IX
    int num4 = 58;     // LVIII
    int num5 = 1994;   // MCMXCIV

    cout << "Integer: " << num1 << " → Roman: " << sol.intToRoman(num1) << endl;
    cout << "Integer: " << num2 << " → Roman: " << sol.intToRoman(num2) << endl;
    cout << "Integer: " << num3 << " → Roman: " << sol.intToRoman(num3) << endl;
    cout << "Integer: " << num4 << " → Roman: " << sol.intToRoman(num4) << endl;
    cout << "Integer: " << num5 << " → Roman: " << sol.intToRoman(num5) << endl;

    return 0;
}