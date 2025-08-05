#include<iostream>
#include<vector>
#include<stack>
using namespace std;

// Function to find the previous smaller element for each element in the array
vector<int> prevSmallerElement(vector<int> arr) {
    vector<int> ans;         // Stores the final result
    stack<int> st;           // Stack to keep track of previous elements

    for(int i = 0; i < arr.size(); i++) {
        // Remove elements from the stack that are >= current element
        while(!st.empty() && st.top() >= arr[i]) {
            st.pop();
        }

        // If stack is empty, no smaller element to the left
        if(st.empty()) {
            ans.push_back(-1);
        } else {
            ans.push_back(st.top()); // Top of stack is the previous smaller
        }

        // Push current element for future comparisons
        st.push(arr[i]);
    }

    return ans;
}

int main() {
    vector<int> arr = {3, 1, 0, 8, 6};

    vector<int> ans = prevSmallerElement(arr);

    // Print the result
    for(int val : ans) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}