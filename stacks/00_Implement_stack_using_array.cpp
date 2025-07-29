#include<iostream>
using namespace std;

// Stack class using a simple fixed-size array
class Stack {
private:
    static const int maxSize = 5; // Maximum capacity of stack
    int arr[maxSize];             // Array to hold stack elements
    int topIndex;                 // Index of the top element (-1 means empty)

public:
    // Constructor to initialize an empty stack
    Stack() {
        topIndex = -1;
    }

    // Push operation: adds an element to the top of the stack
    void push(int val) { // O(1)
        if(topIndex >= maxSize - 1) {
            cout << "Stack Overflow" << endl; // Cannot push, stack is full
        } else {
            arr[++topIndex] = val; // Move index up and insert value
        }
    }

    // Pop operation: removes the top element from the stack
    void pop() { // O(1)
        if(topIndex == -1) {
            cout << "Stack UnderFlow" << endl; // Cannot pop, stack is empty
        } else {
            topIndex--; // Just reduce top index to "forget" the top element
        }
    }

    // Top operation: returns the current top element
    int top() { // O(1)
        if(topIndex == -1) {
            cout << "No elements are in stack" << endl; // Stack is empty
            return -1; // Sentinel value to indicate no top element
        } else {
            return arr[topIndex]; // Return value at the top
        }
    }

    // Empty operation: checks if the stack is empty
    bool empty() {
        return (topIndex == -1);
    }
};

int main() {
    Stack st;

    // ⚡ Pushing elements into the stack
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    st.push(60); // Exceeds maxSize — should trigger overflow
    st.push(70); // Another overflow

    // 🔍 Checking the top element of the stack
    cout << "Current top: " << st.top() << endl;

    // 🔄 Popping one element from the stack
    st.pop();
    cout << "Top after pop: " << st.top() << endl;

    // 🧹 Emptying the entire stack
    st.pop(); // Pops 40
    st.pop(); // Pops 30
    st.pop(); // Pops 20
    st.pop(); // Pops 10
    st.pop(); // Stack is empty now
    st.pop(); // One extra pop — triggers underflow

    return 0;
}