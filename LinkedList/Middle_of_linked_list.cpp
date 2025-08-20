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
    // Find middle node of linked list
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head; // moves 1 step
        ListNode* fast = head; // moves 2 steps

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;       // 1 step
            fast = fast->next->next; // 2 steps
        }
        return slow; // slow = middle
    }
};

// ---------------- MAIN (demo) ----------------
int main() {
    // Linked list: 1->2->3->4->5->nullptr
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    Solution sol;
    ListNode* mid = sol.middleNode(head);
    cout << "Middle Node Value: " << mid->val << endl;

    return 0;
}

/*
⚡ Quick Notes:
- Use 2 pointers: slow (1 step), fast (2 steps)
- When fast reaches end → slow at middle
- If even length → returns 2nd middle

Example: 1->2->3->4->5
   Iter1: slow=2, fast=3
   Iter2: slow=3, fast=5
   End → middle = 3

✅ TC: O(N), SC: O(1)
*/
