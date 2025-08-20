#include <bits/stdc++.h>
using namespace std;

/* Definition for singly-linked list node */
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    // Iterative merge using dummy node
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode(-1); // dummy head
        ListNode* tail = dummy;             // tail builds merged list

        while (list1 && list2) {
            if (list1->val < list2->val) {
                tail->next = list1;
                list1 = list1->next;
            } else {
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }
        // Attach leftover nodes
        tail->next = list1 ? list1 : list2;

        return dummy->next; // real head
    }
};

// ---------------- MAIN (demo) ----------------
ListNode* createList(vector<int> arr) {
    if (arr.empty()) return nullptr;
    ListNode* head = new ListNode(arr[0]);
    ListNode* curr = head;
    for (int i = 1; i < arr.size(); i++) {
        curr->next = new ListNode(arr[i]);
        curr = curr->next;
    }
    return head;
}

void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << "nullptr\n";
}

int main() {
    ListNode* list1 = createList({1,3,5});
    ListNode* list2 = createList({2,4,6});

    Solution sol;
    ListNode* merged = sol.mergeTwoLists(list1, list2);

    cout << "Merged List: ";
    printList(merged);
    return 0;
}

/*
⚡ Quick Notes:
- Dummy node trick → simplifies edge cases
- Compare nodes → attach smaller → move forward
- After loop, attach leftover list
- Finally return dummy->next (real head)

Example:
 list1 = 1->3->5
 list2 = 2->4->6
 → merged = 1->2->3->4->5->6

✅ TC: O(n+m)   (n & m = lengths of lists)
✅ SC: O(1)     (just pointers, no recursion stack)
*/
