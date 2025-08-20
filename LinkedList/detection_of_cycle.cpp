#include <bits/stdc++.h>
using namespace std;

/* Definition for singly-linked list */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    // Detect cycle using Floyd’s cycle-finding algorithm
    bool hasCycle(ListNode *head) {
        ListNode* slow = head; // moves 1 step
        ListNode* fast = head; // moves 2 steps

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) return true; // cycle found
        }
        return false; // reached end → no cycle
    }
};

// ---------------- MAIN (demo) ----------------
int main() {
    // Create linked list: 1->2->3->4->5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    // Make a cycle: 5->next = 3
    head->next->next->next->next->next = head->next->next;

    Solution sol;
    cout << (sol.hasCycle(head) ? "Cycle Detected" : "No Cycle") << endl;

    return 0;
}

/*
⚡ Quick Notes:
- Floyd’s Algorithm:
   • slow = 1 step
   • fast = 2 steps
- If there’s a cycle → they’ll meet
- If fast/fast->next = nullptr → no cycle

Example:
 1->2->3->4->5
          ↑   ↓
          ←←←←

 Iter1: slow=2, fast=3
 Iter2: slow=3, fast=5
 Iter3: slow=4, fast=4 → cycle found ✅

✅ TC: O(N)
✅ SC: O(1)
*/
