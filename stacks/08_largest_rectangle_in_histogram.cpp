#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
    // 🔴 Brute-force approach: O(N^2) time complexity
    // For each bar, expand to the right and calculate area with the minimum height
    int largestRectangleAreaBrute(vector<int>& heights) {
        int n = heights.size();
        int ans = 0;

        for(int i = 0; i < n; i++) {
            int minHeight = heights[i]; // Start with current bar

            for(int j = i; j < n; j++) {
                minHeight = min(minHeight, heights[j]); // Update min height in range
                int width = j - i + 1;
                ans = max(ans, minHeight * width); // Calculate area
            }
        }

        return ans;
    }

    // 🔵 Helper: Find index of next smaller element to the right
    vector<int> rightSmaller(vector<int>& arr) {
        int n = arr.size();
        vector<int> result(n, n); // Default to n (no smaller to right)
        stack<int> st;

        for(int i = n - 1; i >= 0; i--) {
            while(!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            if(!st.empty()) result[i] = st.top();
            st.push(i);
        }
        return result;
    }

    // 🟢 Helper: Find index of previous smaller element to the left
    vector<int> leftSmaller(vector<int>& arr) {
        int n = arr.size();
        vector<int> result(n, -1); // Default to -1 (no smaller to left)
        stack<int> st;

        for(int i = 0; i < n; i++) {
            while(!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            if(!st.empty()) result[i] = st.top();
            st.push(i);
        }
        return result;
    }

    // 🟣 Optimized approach: O(N) using monotonic stacks
    int largestRectangleArea(vector<int>& heights) {
        vector<int> right = rightSmaller(heights);
        vector<int> left = leftSmaller(heights);
        int n = heights.size();
        int ans = 0;

        for(int i = 0; i < n; i++) {
            int width = right[i] - left[i] - 1;
            int area = heights[i] * width;
            ans = max(ans, area);
        }

        return ans;
    }
};

int main() {
    Solution sol;

    // Sample input
    vector<int> heights = {2, 1, 5, 6, 2, 3};

    // 🔴 Brute-force result
    int bruteArea = sol.largestRectangleAreaBrute(heights);
    cout << "Brute-force Largest Rectangle Area: " << bruteArea << endl;

    // 🟣 Optimized result
    int optimizedArea = sol.largestRectangleArea(heights);
    cout << "Optimized Largest Rectangle Area: " << optimizedArea << endl;

    return 0;
}