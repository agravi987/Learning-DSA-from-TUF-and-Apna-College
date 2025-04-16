class Solution {
    public:
        string longestCommonPrefix(vector<string>& strs) {
            // Step 1: Sort the array of strings lexicographically
            sort(strs.begin(), strs.end());
    
            // Step 2: After sorting, the common prefix of the entire array
            // must be a prefix of both the first and last strings.
            string first = strs.front();  // First string after sorting
            string last = strs.back();    // Last string after sorting
            string ans;  // To store the resulting longest common prefix
    
            // Step 3: Find the minimum length between first and last string
            // because we can only compare up to the length of the shorter one
            int n = min(first.length(), last.length());
    
            // Step 4: Compare characters of first and last string
            // until they differ or we reach the end of one string
            for (int i = 0; i < n; i++) {
                if (first[i] != last[i]) 
                    break;  // Stop if characters don't match
    
                ans += first[i];  // Add matching character to answer
            }
    
            // Step 5: Return the longest common prefix found
            return ans;
        }
    };
    