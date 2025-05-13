#include <stack>
#include <utility>
#include <algorithm>
using namespace std;

class MinStack {
public:
    stack<pair<int, int>> st;

    MinStack() {}

    void push(int val) {
        if (st.empty()) {
            st.push({val, val});
        } else {
            int currMin = min(val, st.top().second);
            st.push({val, currMin});
        }
    }

    void pop() {
        if (!st.empty()) {
            st.pop();
        }
    }

    int top() {
        return st.top().first;
    }

    int getMin() {
        return st.top().second;
    }
};

