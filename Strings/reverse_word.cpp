
// problem 151 leetcode 

class Solution {
    public:
        string reverseWords(string s) {
    
            // Step 1: Reverse the entire string to bring words in reverse order
            reverse(s.begin(), s.end());
    
            int n = s.length();
            string ans = "";
    
            for (int i = 0; i < n; i++) {
                // Step 2: Skip any extra spaces (leading or between words)
                while (s[i] == ' ' && i < n) i++;
    
                string word = "";
    
                // Step 3: Collect characters for the current word
                while (s[i] != ' ' && i < n) {
                    word += s[i];
                    i++;
                }
    
                // Step 4: If a word was found, reverse it to get original order
                if (!word.empty()) {
                    reverse(word.begin(), word.end()); // reverse each word back
                    ans += " " + word; // build the result with spaces
                }
            }
    
            // Step 5: Return final answer (skip the leading space)
            return ans.substr(1);
        }
    };
    