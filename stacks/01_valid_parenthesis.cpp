/*
===========================================
🧠 PROBLEM: Valid Parentheses (LeetCode #20)
===========================================

📝 DESCRIPTION:
Given a string `s` containing just the characters '(', ')', '{', '}', '[' and ']', 
determine if the input string is valid.

✅ A string is valid if:
1. Open brackets must be closed by the same type of brackets.
2. Open brackets must be closed in the correct order.

📥 INPUT:
- A string `s` containing only the characters '(', ')', '{', '}', '[' and ']'

📤 OUTPUT:
- Return true if the string is valid, otherwise false.

🔍 EXAMPLES:
Input: s = "()[]{}"
Output: true

Input: s = "(]"
Output: false

Input: s = "([{}])"
Output: true

===========================================
*/

#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (char ch : s) {
            // Push opening brackets onto the stack
            if (ch == '(' || ch == '{' || ch == '[') {
                st.push(ch);
            } 
            else {
                // If no matching opening bracket
                if (st.empty()) return false;

                char top = st.top();
                // Check if closing matches the top opening
                if ((ch == ')' && top != '(') ||
                    (ch == '}' && top != '{') ||
                    (ch == ']' && top != '[')) {
                    return false;
                }

                st.pop(); // Valid pair found
            }
        }

        // If all brackets matched, stack should be empty
        return st.empty();
    }
};

// ✅ Main Function to Test
int main() {
    Solution sol;

    string s1 = "()[]{}";
    string s2 = "(]";
    string s3 = "([{}])";

    cout << "Input: " << s1 << " -> Output: " << (sol.isValid(s1) ? "true" : "false") << endl;
    cout << "Input: " << s2 << " -> Output: " << (sol.isValid(s2) ? "true" : "false") << endl;
    cout << "Input: " << s3 << " -> Output: " << (sol.isValid(s3) ? "true" : "false") << endl;

    return 0;
}
