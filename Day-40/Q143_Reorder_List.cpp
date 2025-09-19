#include <iostream>
#include <vector>
using namespace std;

/*
143. Reorder List
-----------------
You are given the head of a singly linked list. The list can be represented as:

L0 → L1 → … → Ln-1 → Ln

Reorder the list into the form:
L0 → Ln → L1 → Ln-1 → L2 → Ln-2 → …
 
Constraints:
- You cannot change node values, only rearrange nodes.
- Example 1:
    Input: head = [1,2,3,4]
    Output: [1,4,2,3]
- Example 2:
    Input: head = [1,2,3,4,5]
    Output: [1,5,2,4,3]
*/

/**
 * Definition for singly-linked list.
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/**
 * Approach:
 * ---------
 * 1. Find the middle of the linked list using slow & fast pointers.
 * 2. Reverse the second half of the list.
 * 3. Merge the first half and the reversed second half alternately.
 *
 * Example:
 * Input: [1,2,3,4,5]
 * Step 1: Middle -> split into [1,2,3] and [4,5]
 * Step 2: Reverse second half -> [5,4]
 * Step 3: Merge -> [1,5,2,4,3]
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */

class Solution  {
public:
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;

        // Step 1: Find the middle of the list
        ListNode *slow = head, *fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: Reverse the second half
        ListNode* prev = nullptr;
        ListNode* curr = slow->next;
        while (curr) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        slow->next = nullptr;  // Split the list into two halves

        // Step 3: Merge the two halves
        ListNode* first = head;
        ListNode* second = prev;
        while (second) {
            ListNode* temp1 = first->next;
            ListNode* temp2 = second->next;

            first->next = second;
            second->next = temp1;

            first = temp1;
            second = temp2;
        }
    }
};

// Helper function: Convert vector to linked list
ListNode* createList(vector<int>& arr) {
    if (arr.empty()) return nullptr;
    ListNode* head = new ListNode(arr[0]);
    ListNode* curr = head;
    for (int i = 1; i < arr.size(); i++) {
        curr->next = new ListNode(arr[i]);
        curr = curr->next;
    }
    return head;
}

// Helper function: Print linked list in LeetCode format
void printList(ListNode* head) {
    cout << "[";
    while (head) {
        cout << head->val;
        head = head->next;
        if (head) cout << ",";
    }
    cout << "]\n";
}

// Driver code
int main() {
    Solution sol;

    vector<int> arr1 = {1,2,3,4};
    ListNode* head1 = createList(arr1);
    cout << "Input: [1,2,3,4]\n";
    sol.reorderList(head1);
    cout << "Output: ";
    printList(head1);   // Expected: [1,4,2,3]

    vector<int> arr2 = {1,2,3,4,5};
    ListNode* head2 = createList(arr2);
    cout << "\nInput: [1,2,3,4,5]\n";
    sol.reorderList(head2);
    cout << "Output: ";
    printList(head2);   // Expected: [1,5,2,4,3]

    return 0;
}


// Output =>
// Input: [1,2,3,4]
// Output: [1,4,2,3]

// Input: [1,2,3,4,5]
// Output: [1,5,2,4,3]





