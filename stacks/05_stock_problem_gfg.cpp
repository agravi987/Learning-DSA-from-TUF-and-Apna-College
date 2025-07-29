#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/*
    Function to calculate stock span:
    For each day, the span is the number of consecutive days before it (including today)
    where the stock price was less than or equal to today's price.
*/
class Solution {
public:
    vector<int> calculateSpan(vector<int>& arr) {
        stack<int> st;                      // Stack to keep indices of useful elements
        vector<int> ans(arr.size());        // Stores the span for each day

        for (int i = 0; i < arr.size(); i++) {
            // Pop all previous indices where the stock price is less than or equal to current
            while (!st.empty() && arr[st.top()] <= arr[i]) {
                st.pop();
            }

            // If stack is empty, no greater element to the left, so span is full length (i + 1)
            // Else, span is the distance to the last greater element
            ans[i] = st.empty() ? (i + 1) : (i - st.top());

            // Push current index onto stack for future comparisons
            st.push(i);
        }

        return ans;
    }
};

int main() {
    vector<int> prices = {100, 80, 60, 70, 60, 75, 85};

    Solution sol;
    vector<int> spans = sol.calculateSpan(prices);

    cout << "Stock spans for each day:\n";
    for (int span : spans) {
        cout << span << " ";
    }
    cout << endl;

    return 0;
}