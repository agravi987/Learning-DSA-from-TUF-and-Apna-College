#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    // Function to find the longest palindromic substring in a given string
    string longestPalindrome(string s) {
        // Edge case: if the string is empty or has only one character, it's already a palindrome
        if (s.length() <= 1) {
            return s;
        }

        string lps = ""; // Stores the longest palindromic substring found

        // Iterate through each character in the string
        for (int i = 0; i < s.size(); i++) {
            // -------- Check for odd-length palindromes --------
            int low = i, high = i; // Center at i
            while (low >= 0 && high < s.size() && s[low] == s[high]) {
                low--;
                high++;
            }
            // Extract the palindrome substring
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
            // Extract the palindrome substring
            palindrome = s.substr(low + 1, high - low - 1);
            if (palindrome.length() > lps.length()) {
                lps = palindrome;
            }
        }

        return lps;
    }
};

// -------- Main function for testing --------
int main() {
    Solution sol;

    // Sample test cases
    string input1 = "babad";
    string input2 = "cbbd";
    string input3 = "a";
    string input4 = "forgeeksskeegfor";

    cout << "Input: " << input1 << " → Longest Palindrome: " << sol.longestPalindrome(input1) << endl;
    cout << "Input: " << input2 << " → Longest Palindrome: " << sol.longestPalindrome(input2) << endl;
    cout << "Input: " << input3 << " → Longest Palindrome: " << sol.longestPalindrome(input3) << endl;
    cout << "Input: " << input4 << " → Longest Palindrome: " << sol.longestPalindrome(input4) << endl;

    return 0;
}