#include <bits/stdc++.h>
using namespace std;

/* Definition for singly-linked list */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    // Iterative Linked List Reverse
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;   // last processed node
        ListNode* curr = head;      // current node
        ListNode* nextNode = nullptr; // store next before breaking link

        while (curr != nullptr) {
            nextNode = curr->next;   // save next
            curr->next = prev;       // reverse pointer
            prev = curr;             // move prev forward
            curr = nextNode;         // move curr forward
        }
        return prev; // new head
    }
};

// ---------------- MAIN (for demo) ----------------
int main() {
    // Create Linked List: 1 -> 2 -> 3 -> nullptr
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);

    Solution sol;
    ListNode* newHead = sol.reverseList(head);

    // Print reversed list
    cout << "Reversed List: ";
    while (newHead) {
        cout << newHead->val << " ";
        newHead = newHead->next;
    }
    return 0;
}

/*
⚡ Quick Notes:
- Classic 3-pointer technique: prev, curr, next
- Steps:
   1. Save next → nextNode = curr->next
   2. Reverse link → curr->next = prev
   3. Move prev → curr
   4. Move curr → nextNode
- Stop when curr = nullptr
- Return prev (new head)

Example: 1->2->3->nullptr
   Iter1: 1->nullptr
   Iter2: 2->1->nullptr
   Iter3: 3->2->1->nullptr

✅ TC: O(N), SC: O(1)
*/
