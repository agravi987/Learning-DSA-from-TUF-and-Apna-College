#include <iostream>
#include <string>
using namespace std;

//////////////////////////////////////////////////////
// ✅ Solution 1: Expand Around Center with Substrings
// Time Complexity: O(n²)
// Space Complexity: O(1)
// Reason: For each character, we expand outward in both directions.
//         Substring extraction is constant-time due to internal optimizations.
//////////////////////////////////////////////////////
class Solution1 {
public:
    string longestPalindrome(string s) {
        if (s.length() <= 1) {
            return s; // Edge case: empty or single-character string
        }

        string lps = ""; // Stores the longest palindromic substring found

        for (int i = 0; i < s.size(); i++) {
            // -------- Check for odd-length palindromes --------
            int low = i, high = i; // Center at i
            while (low >= 0 && high < s.size() && s[low] == s[high]) {
                low--;
                high++;
            }
            string palindrome = s.substr(low + 1, high - low - 1);
            if (palindrome.length() > lps.length()) {
                lps = palindrome;
            }

            // -------- Check for even-length palindromes --------
            low = i - 1;
            high = i; // Center between i-1 and i
            while (low >= 0 && high < s.size() && s[low] == s[high]) {
                low--;
                high++;
            }
            palindrome = s.substr(low + 1, high - low - 1);
            if (palindrome.length() > lps.length()) {
                lps = palindrome;
            }
        }

        return lps;
    }
};

//////////////////////////////////////////////////////
// ✅ Solution 2: Expand Around Center with Length Tracking
// Time Complexity: O(n²)
// Space Complexity: O(1)
// Reason: Same expansion logic, but avoids substring comparisons.
//         Only tracks start and end indices for final extraction.
//////////////////////////////////////////////////////
class Solution2 {
public:
    // Helper function to expand around center and return length of palindrome
    int expandFromCenter(string s, int i, int j) {
        while (i >= 0 && j < s.size() && s[i] == s[j]) {
            i--;
            j++;
        }
        return j - i - 1; // Final length of palindrome
    }

    string longestPalindrome(string s) {
        int start = 0, end = 0; // Track start and end indices of longest palindrome

        for (int i = 0; i < s.size(); i++) {
            int len1 = expandFromCenter(s, i, i + 1); // Even-length palindrome
            int len2 = expandFromCenter(s, i, i);     // Odd-length palindrome
            int len = max(len1, len2);                // Max of both

            if (end - start < len) {
                start = i - (len - 1) / 2;
                end = i + len / 2;
            }
        }

        return s.substr(start, end - start + 1);
    }
};

//////////////////////////////////////////////////////
// 🔍 Main Function for Testing Both Solutions
//////////////////////////////////////////////////////
int main() {
    Solution1 sol1;
    Solution2 sol2;

    // Sample test cases
    string inputs[] = {"babad", "cbbd", "a", "forgeeksskeegfor"};

    cout << "=== Longest Palindromic Substring ===\n\n";
    for (string input : inputs) {
        cout << "Input: " << input << endl;
        cout << "→ Solution 1: " << sol1.longestPalindrome(input) << endl;
        cout << "→ Solution 2: " << sol2.longestPalindrome(input) << endl;
        cout << "-------------------------------------\n";
    }

    return 0;
}