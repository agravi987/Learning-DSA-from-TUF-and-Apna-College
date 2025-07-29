#include <iostream>
#include <vector>
using namespace std;

// Custom Stack class using vector internally
class Stack {
    vector<int> vt;

public:
    // Push an element onto the stack
    void push(int val) {
        vt.push_back(val);
    }

    // Pop the top element from the stack
    void pop() {
        if (!vt.empty()) {
            vt.pop_back();
        } else {
            cout << "Stack is empty. Cannot pop.\n";
        }
    }

    // Return the top element of the stack
    int top() {
        if (!vt.empty()) {
            return vt.back();
        } else {
            cout << "Stack is empty. No top element.\n";
            return -1; // Return a sentinel value
        }
    }

    // Check if the stack is empty
    bool empty() {
        return vt.empty();
    }
};

int main() {
    // Create a stack object
    Stack st;

    // Push elements onto the stack
    st.push(10);
    st.push(20);
    st.push(30);

    // Display the top element
    cout << "Top element: " << st.top() << endl; // Should print 30

    // Pop an element
    st.pop();

    // Display the top element again
    cout << "Top after pop: " << st.top() << endl; // Should print 20

    // Pop remaining elements
    st.pop();
    st.pop();

    // Try popping from an empty stack
    st.pop(); // Should print warning

    // Check if stack is empty
    if (st.empty()) {
        cout << "Stack is now empty!\n";
    }

    return 0;
}