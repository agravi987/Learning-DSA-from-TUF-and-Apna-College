#include <iostream>
#include <stack>
using namespace std;

class MyQueue {
private:
    stack<int> input;   // Stack to handle incoming elements
    stack<int> output;  // Stack to reverse order for front element access

public:
    // Constructor: Initializes the data structure
    MyQueue() {}

    // Pushes element x to the back of the queue
    // Time Complexity: O(1)
    void push(int x) {
        input.push(x);
    }

    // Removes the element from the front of the queue and returns it
    // Amortized Time Complexity: O(1), Worst-case O(n) when transferring elements
    int pop() {
        if (output.empty()) {
            // Transfer all elements from input to output to reverse order
            while (!input.empty()) {
                output.push(input.top());
                input.pop();
            }
        }
        int val = output.top();
        output.pop();  // Remove the front element
        return val;
    }

    // Returns the element at the front of the queue without removing it
    // Amortized Time Complexity: O(1), Worst-case O(n)
    int peek() {
        if (output.empty()) {
            // Transfer all elements only if output is empty
            while (!input.empty()) {
                output.push(input.top());
                input.pop();
            }
        }
        return output.top();  // Front of the queue
    }

    // Returns true if the queue is empty
    // Time Complexity: O(1)
    bool empty() {
        return input.empty() && output.empty();
    }
};

// ----------------------------
// Main Function (Demo Use)
// ----------------------------
int main() {
    MyQueue q;

    // Push elements to the queue
    q.push(10);
    q.push(20);
    q.push(30);

    // Peek front element
    cout << "Front element: " << q.peek() << endl;  // Output: 10

    // Pop front element
    cout << "Popped element: " << q.pop() << endl;  // Output: 10

    // Peek again
    cout << "New front element: " << q.peek() << endl;  // Output: 20

    // Check if queue is empty
    cout << "Is queue empty? " << (q.empty() ? "Yes" : "No") << endl;  // Output: No

    return 0;
}
