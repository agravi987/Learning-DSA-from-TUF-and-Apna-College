#include <iostream>
#include <stack>
#include <climits>
using namespace std;

// Time Complexity: O(1) for all operations
// Space Complexity: O(2 * n) due to storing both value and min in each pair
class MinStack1 {
    // Stack stores pairs: {value, current_min}
    stack<pair<int, int>> st;

public:
    MinStack1() {}

    // Push a value and update the current minimum
    void push(int val) {
        int minVal = val;
        if (!st.empty()) {
            // Compare with previous min to maintain current min
            minVal = min(val, st.top().second);
        }
        st.push({val, minVal});
    }

    // Pop the top element
    void pop() {
        if (!st.empty())
            st.pop();
    }

    // Return the top value
    int top() {
        if (!st.empty())
            return st.top().first;
        return -1;
    }

    // Return the current minimum
    int getMin() {
        if (!st.empty())
            return st.top().second;
        return -1;
    }
};


// Time Complexity: O(1) for all operations
// Space Complexity: O(n), but uses encoding to avoid extra space for min tracking
class MinStack2 {
    long long minVal;             // Stores current minimum
    stack<long long> st;          // Stack stores either actual value or encoded value

public:
    MinStack2() {}

    // Push a value with encoding if it's the new minimum
    void push(int val) {
        if (st.empty()) {
            st.push(val);
            minVal = val;
        } else if (val < minVal) {
            // Encode previous minVal to recover later
            st.push(2LL * val - minVal);
            minVal = val;
        } else {
            st.push(val);
        }
    }

    // Pop and decode if necessary
    void pop() {
        if (st.empty()) return;

        if (st.top() < minVal) {
            // Decode previous minVal
            minVal = 2LL * minVal - st.top();
        }
        st.pop();
    }

    // Return the top value (decode if needed)
    int top() {
        if (st.empty()) return -1;

        if (st.top() < minVal) {
            return (int)minVal;
        } else {
            return (int)st.top();
        }
    }

    // Return the current minimum
    int getMin() {
        if (st.empty()) return -1;
        return (int)minVal;
    }
};



int main() {
    cout << "Testing MinStack1 (pair-based):\n";
    MinStack1 ms1;
    ms1.push(3);
    ms1.push(5);
    cout << "Min: " << ms1.getMin() << "\n"; // 3
    ms1.push(2);
    ms1.push(1);
    cout << "Min: " << ms1.getMin() << "\n"; // 1
    ms1.pop();
    cout << "Top: " << ms1.top() << "\n";    // 2
    cout << "Min: " << ms1.getMin() << "\n"; // 2

    cout << "\nTesting MinStack2 (encoded):\n";
    MinStack2 ms2;
    ms2.push(3);
    ms2.push(5);
    cout << "Min: " << ms2.getMin() << "\n"; // 3
    ms2.push(2);
    ms2.push(1);
    cout << "Min: " << ms2.getMin() << "\n"; // 1
    ms2.pop();
    cout << "Top: " << ms2.top() << "\n";    // 2
    cout << "Min: " << ms2.getMin() << "\n"; // 2

    return 0;
}