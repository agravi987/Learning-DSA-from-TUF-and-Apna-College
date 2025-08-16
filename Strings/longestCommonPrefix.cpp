#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

/* ---------------- Brute Force Approach ---------------- */
class BruteSolution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";

        string prefix = "";

        // Compare each character of the first string with all others
        for (int i = 0; i < strs[0].size(); i++) {
            char ch = strs[0][i];

            for (int j = 1; j < strs.size(); j++) {
                // Stop if index exceeds or mismatch occurs
                if (i >= strs[j].size() || strs[j][i] != ch) {
                    return prefix;
                }
            }

            prefix += ch;
        }

        return prefix;
    }
};

/*
Time Complexity: O(n * m)
- n = number of strings
- m = length of the shortest string
Space Complexity: O(1)
- Only uses a few variables
*/



/* ---------------- Optimal Approach (Sort + Compare) ---------------- */
class OptimalSolution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";

        // Step 1: Sort strings lexicographically
        sort(strs.begin(), strs.end());

        // Step 2: Compare first and last strings only
        string first = strs.front();
        string last = strs.back();
        string ans = "";

        int n = min(first.length(), last.length());

        for (int i = 0; i < n; i++) {
            if (first[i] != last[i]) break;
            ans += first[i];
        }

        return ans;
    }
};

/*
Time Complexity: O(n log n + m)
- n log n for sorting
- m for comparing first and last strings
Space Complexity: O(1)
- Sorting is in-place, only a few variables used
*/

/* ---------------- Main Function for Testing ---------------- */
int main() {
    vector<string> test1 = {"flower", "flow", "flight"};
    vector<string> test2 = {"dog", "racecar", "car"};
    vector<string> test3 = {"interspecies", "interstellar", "interstate"};

    BruteSolution brute;
    OptimalSolution optimal;

    cout << "Brute Force:\n";
    cout << "Test1 → " << brute.longestCommonPrefix(test1) << endl; // Output: "fl"
    cout << "Test2 → " << brute.longestCommonPrefix(test2) << endl; // Output: ""
    cout << "Test3 → " << brute.longestCommonPrefix(test3) << endl; // Output: "inters"

    cout << "\nOptimal:\n";
    cout << "Test1 → " << optimal.longestCommonPrefix(test1) << endl;
    cout << "Test2 → " << optimal.longestCommonPrefix(test2) << endl;
    cout << "Test3 → " << optimal.longestCommonPrefix(test3) << endl;

    return 0;
}