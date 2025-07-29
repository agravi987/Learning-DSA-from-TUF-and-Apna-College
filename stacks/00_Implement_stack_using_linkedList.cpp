#include <iostream>
#include <list>
using namespace std;

// ✅ Stack implementation using std::list for efficient front insert/remove
class Stack {
public:
    list<int> ll;  // Doubly linked list as the underlying container

    // ➕ Adds an element to the top of the stack
    void push(int val) {
        ll.push_front(val);  // O(1) time complexity
    }

    // ➖ Removes the top element if stack is not empty
    void pop() {
        if (ll.empty()) {
            cout << "Stack underflow" << endl;  // Safe handling for empty stack
        } else {
            ll.pop_front();  // O(1) time complexity
        }
    }

    // 🔝 Returns the top element or error message if empty
    int top() {
        if (ll.empty()) {
            cout << "No elements are there in stack" << endl;
            return -1;  // Sentinel value; can customize if needed
        } else {
            return ll.front();  // O(1) time complexity
        }
    }

    // ❓ Checks if the stack is empty
    bool empty() {
        return ll.empty();  // O(1) time complexity
    }
};

int main() {
    Stack st;  // ✅ Create stack instance

    // 📦 Push elements to the stack
    st.push(10); // Stack: [10]
    st.push(20); // Stack: [20, 10]
    st.push(30); // Stack: [30, 20, 10]

    // 🔍 Peek at the top
    cout << "Top element: " << st.top() << endl; // Expected: 30

    // 🚮 Pop one element
    st.pop(); // Removes 30
    cout << "After pop, top is: " << st.top() << endl; // Expected: 20

    // 🔄 Check if the stack is empty
    cout << "Is stack empty? " << (st.empty() ? "Yes" : "No") << endl; // Expected: No

    // 🧹 Pop remaining elements
    st.pop(); // Removes 20
    st.pop(); // Removes 10

    // ⚠️ Try popping when empty
    st.pop(); // Should print: Stack underflow

    // ⚠️ Try accessing top when empty
    st.top(); // Should print: No elements are there in stack

    return 0;
}