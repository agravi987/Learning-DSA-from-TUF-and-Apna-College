// Problem: 160. Intersection of Two Linked Lists
// Given the heads of two singly linked-lists headA and headB, return the node at which the two lists intersect.
// If the two linked lists have no intersection at all, return nullptr.

#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// ------------------------
// First Approach: By Length
// ------------------------
// Time Complexity: O(N + M), where N and M are the lengths of the two lists
// Space Complexity: O(1)

int length(ListNode *head){
    int count = 0;
    while(head != nullptr){
        count++;
        head = head->next;
    }
    return count;
}

ListNode *getIntersectionNode_ByLength(ListNode *headA, ListNode *headB) {
    int l1 = length(headA);
    int l2 = length(headB);
    ListNode *ptr1;
    ListNode *ptr2;
    int d = 0;

    // Point ptr1 to longer list
    if(l1 > l2){
        d = l1 - l2;
        ptr1 = headA;
        ptr2 = headB;
    } else {
        d = l2 - l1;
        ptr1 = headB;
        ptr2 = headA;
    }

    while(d){
        ptr1 = ptr1->next;
        if(ptr1 == nullptr) return nullptr;
        d--;
    }

    while(ptr1 != nullptr && ptr2 != nullptr){
        if(ptr1 == ptr2) return ptr1;
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    return nullptr;
}

// ------------------------
// Second Approach: Two Pointer Switching
// ------------------------
// Time Complexity: O(N + M), where N and M are the lengths of the two lists
// Space Complexity: O(1)

ListNode *getIntersectionNode_TwoPointer(ListNode *headA, ListNode *headB) {
    ListNode *temp1 = headA;
    ListNode *temp2 = headB;

    while(temp1 != temp2){
        temp1 = (temp1 == nullptr) ? headB : temp1->next;
        temp2 = (temp2 == nullptr) ? headA : temp2->next;

        if(temp1 == temp2) return temp1;
    }

    return temp1; // Could be nullptr (no intersection) or the intersecting node
}

// ------------------------
// Note: You can call either function in main() for testing
// ------------------------

int main() {
    // For future testing purposes
    return 0;
}
