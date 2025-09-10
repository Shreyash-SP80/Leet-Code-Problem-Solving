/*
234. Palindrome Linked List
--------------------------------------------
Given the head of a singly linked list, return true if it is a palindrome,
otherwise return false.
*/

/*
# Intuition
- A palindrome reads the same forward and backward.
- In a linked list, we cannot access elements backwards directly.
- Idea:
  1. Find the middle of the list using slow/fast pointers.
  2. Reverse the second half of the list.
  3. Compare first half and reversed second half node by node.

# Approach
1. Use two pointers (slow & fast) to find the middle.
   - When fast reaches the end, slow is at the middle.
2. Reverse the second half starting from `slow`.
3. Compare nodes:
   - Start `left` at head, `right` at head of reversed second half.
   - If mismatch occurs → not a palindrome.
4. If all matched → palindrome.

# Complexity
- Time: O(n)  
  * Traversing list to find middle, reversing, and comparing → linear.
- Space: O(1)  
  * In-place reversal, no extra storage.
*/

/**
 * Definition for singly-linked list.
 */

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;

        // Step 1: Find middle
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: Reverse second half
        ListNode* prev = nullptr;
        ListNode* curr = slow;
        while (curr) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        // Step 3: Compare first half and reversed second half
        ListNode* left = head;
        ListNode* right = prev;
        while (right) {
            if (left->val != right->val) return false;
            left = left->next;
            right = right->next;
        }
        return true;
    }
};

// Driver
int main() {
    // Example: head = [1,2,2,1]
    ListNode* node4 = new ListNode(1);
    ListNode* node3 = new ListNode(2, node4);
    ListNode* node2 = new ListNode(2, node3);
    ListNode* head  = new ListNode(1, node2);

    Solution sol;
    cout << (sol.isPalindrome(head) ? "true" : "false") << endl; // true

    return 0;
}

