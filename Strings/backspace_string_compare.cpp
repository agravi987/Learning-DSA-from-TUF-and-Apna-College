#include <iostream>
#include <stack>
using namespace std;

class SolutionWithStack {
public:
    // Time Complexity: O(n + m) — where n and m are lengths of strings s and t
    // Space Complexity: O(n + m) — stack uses extra space proportional to input size

    string processString(string s){
        stack<char> st;

        for(char ch : s){
            if(ch == '#'){
                if(!st.empty()) st.pop();
            } else {
                st.push(ch);
            }
        }

        string result = "";
        while(!st.empty()){
            result = st.top() + result;
            st.pop();
        }

        return result;
    }

    bool backspaceCompare(string s, string t) {
        return processString(s) == processString(t);
    }
};

class SolutionWithTwoPointers {
public:
    // Time Complexity: O(n + m) — traverses each string once
    // Space Complexity: O(n + m) — builds new strings (can be optimized to O(1) in-place)

    string processString(string s){
        int i = s.size() - 1;
        int hashCount = 0;
        string result = "";

        while(i >= 0){
            if(s[i] == '#'){
                hashCount++;
            } else {
                if(hashCount > 0){
                    hashCount--;
                } else {
                    result = s[i] + result;
                }
            }
            i--;
        }

        return result;
    }

    bool backspaceCompare(string s, string t) {
        return processString(s) == processString(t);
    }
};

// ---------------- MAIN FUNCTION ----------------

int main() {
    string s = "y#fo##f";
    string t = "y#f#o##f";

    SolutionWithStack sol1;
    SolutionWithTwoPointers sol2;

    cout << "Test Case: s = \"" << s << "\", t = \"" << t << "\"" << endl;

    // Using Stack
    bool result1 = sol1.backspaceCompare(s, t);
    cout << "Using Stack Result: " << (result1 ? "True" : "False") << endl;

    // Using Two Pointers
    bool result2 = sol2.backspaceCompare(s, t);
    cout << "Using Two Pointers Result: " << (result2 ? "True" : "False") << endl;

    return 0;
}
