#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

/*
    🔶 SOLUTION:
    Since we don't have access to the previous node,
    we copy the value of the next node into the current node,
    and then delete the next node.

    Time Complexity: O(1)
    Space Complexity: O(1)
*/

class Solution {
public:
    void deleteNode(ListNode* node) {
        // Copy the next node's value into the current node
        node->val = node->next->val;

        // Skip the next node and free memory
        ListNode* temp = node->next;
        node->next = node->next->next;
        delete temp;
    }
};

// 🔹 Helper function to print the linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

// 🔹 Main function to demonstrate
int main() {
    // Creating the linked list: 4 -> 5 -> 1 -> 9
    ListNode* head = new ListNode(4);
    head->next = new ListNode(5);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(9);

    cout << "Original list: ";
    printList(head);

    // Deleting node with value 5 (we pass pointer to it)
    Solution sol;
    sol.deleteNode(head->next); // head->next points to 5

    cout << "After deleting node with value 5: ";
    printList(head);

    // Free memory
    while (head) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
