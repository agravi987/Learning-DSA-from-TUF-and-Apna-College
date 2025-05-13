#include <iostream>
using namespace std;

// Definition for singly-linked list node
struct ListNode {
    int val;
    ListNode* next;

    // Constructors for convenience
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    // Function to merge two sorted linked lists
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // Creating a dummy node to simplify edge cases
        ListNode* dummyHead = new ListNode(-1);
        ListNode* temp = dummyHead;  // Temp pointer to build the merged list

        ListNode* l1 = list1;
        ListNode* l2 = list2;

        // Traverse both lists and pick smaller values
        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val < l2->val) {
                temp->next = l1;
                l1 = l1->next;
            } else {
                temp->next = l2;
                l2 = l2->next;
            }
            temp = temp->next;
        }

        // Attach remaining nodes if any
        if (l1 != nullptr) temp->next = l1;
        if (l2 != nullptr) temp->next = l2;

        // Return head of merged list
        return dummyHead->next;
    }
};

// Helper function to create linked list from array
ListNode* createList(int arr[], int n) {
    if (n == 0) return nullptr;
    ListNode* head = new ListNode(arr[0]);
    ListNode* current = head;
    for (int i = 1; i < n; i++) {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }
    return head;
}

// Helper function to print linked list
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "nullptr" << endl;
}

int main() {
    // Input arrays for two sorted lists
    int arr1[] = {1, 3, 5};
    int arr2[] = {2, 4, 6};

    // Creating linked lists from arrays
    ListNode* list1 = createList(arr1, 3);
    ListNode* list2 = createList(arr2, 3);

    // Creating object of Solution class
    Solution solution;

    // Merging the two sorted lists
    ListNode* mergedList = solution.mergeTwoLists(list1, list2);

    // Printing the merged list
    cout << "Merged Linked List: ";
    printList(mergedList);

    return 0;
}
