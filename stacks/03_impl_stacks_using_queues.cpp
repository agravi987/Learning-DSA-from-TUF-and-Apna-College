#include <iostream>
#include <queue>
using namespace std;

class MyStack {
public:
    queue<int> q1;  // Primary queue
    queue<int> q2;  // Temporary queue

    // Constructor
    MyStack() {}

    // Push element x onto stack
    void push(int x) {
        // Step 1: If q1 is empty, just push x
        if (q1.empty()) {
            q1.push(x);
        } else {
            // Step 2: Move all elements from q1 to q2
            while (!q1.empty()) {
                q2.push(q1.front());
                q1.pop();
            }

            // Step 3: Push the new element to q1
            q1.push(x);

            // Step 4: Move everything back from q2 to q1
            while (!q2.empty()) {
                q1.push(q2.front());
                q2.pop();
            }
        }
    }

    // Removes the element on top of the stack and returns it
    int pop() {
        int val = q1.front();
        q1.pop();
        return val;
    }

    // Get the top element
    int top() {
        return q1.front();
    }

    // Returns true if the stack is empty
    bool empty() {
        return q1.empty();
    }
};

// Main function to test MyStack
int main() {
    MyStack* obj = new MyStack();

    obj->push(10);
    obj->push(20);
    obj->push(30);

    cout << "Top element: " << obj->top() << endl;    // Output: 30
    cout << "Popped: " << obj->pop() << endl;         // Output: 30
    cout << "Top after pop: " << obj->top() << endl;  // Output: 20
    cout << "Is stack empty? " << (obj->empty() ? "Yes" : "No") << endl;  // Output: No

    delete obj;  // Clean up memory
    return 0;
}
