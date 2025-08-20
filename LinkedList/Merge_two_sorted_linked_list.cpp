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
    // Merge two sorted linked lists (recursive)
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // Base cases
        if (!list1) return list2;
        if (!list2) return list1;

        // Pick smaller node, recurse for rest
        if (list1->val <= list2->val) {
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        } else {
            list2->next = mergeTwoLists(list1, list2->next);
            return list2;
        }
    }
};

// ---------------- MAIN (demo) ----------------
int main() {
    // list1: 1 -> 3 -> 5
    ListNode* list1 = new ListNode(1);
    list1->next = new ListNode(3);
    list1->next->next = new ListNode(5);

    // list2: 2 -> 4 -> 6
    ListNode* list2 = new ListNode(2);
    list2->next = new ListNode(4);
    list2->next->next = new ListNode(6);

    Solution sol;
    ListNode* merged = sol.mergeTwoLists(list1, list2);

    // Print merged list
    cout << "Merged List: ";
    while (merged) {
        cout << merged->val << " ";
        merged = merged->next;
    }
    return 0;
}

/*
⚡ Quick Notes:
- Classic recursive merge
- Base: if one list empty → return other
- Step:
   Compare heads → smaller one links to merged rest
- Works like merge step of MergeSort

Example:
 list1 = 1->3->5
 list2 = 2->4->6
 → merged = 1->2->3->4->5->6

✅ TC: O(n+m), SC: O(n+m) recursion stack
*/
