#include <iostream>
using namespace std;

/*
===========================================
🧩 LeetCode 21. Merge Two Sorted Lists
===========================================

📌 Problem Statement:
---------------------
You are given the heads of two sorted linked lists: `list1` and `list2`.

Merge the two lists into one sorted list.  
The merged list should be made by **splicing together the nodes** of the first two lists.

🔁 Requirements:
- Do not create new nodes — rearrange the existing nodes' `next` pointers.
- Return the head of the merged linked list.

📥 Example 1:
Input:  list1 = [1,2,4], list2 = [1,3,4]  
Output: [1,1,2,3,4,4]

📥 Example 2:
Input:  list1 = [], list2 = []  
Output: []

📥 Example 3:
Input:  list1 = [], list2 = [0]  
Output: [0]

-------------------------------------------
🧠 Approach:
-------------------------------------------
1. Use a dummy node to simplify handling the head of the merged list.
2. Initialize a pointer `tail` to the dummy node.
3. Traverse both lists:
   - Compare values at current nodes of list1 and list2.
   - Append the smaller node to `tail` and move that list forward.
4. Once one list is exhausted, append the remaining nodes of the other list.
5. Return `dummy.next` (the merged list's head).

🔧 Time Complexity: O(n + m) — where n and m are lengths of list1 and list2
🔧 Space Complexity: O(1) — in-place merging (no new node creation)
===========================================
*/



// 🧱 Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        // Dummy node to simplify list construction
        ListNode dummy(0);
        ListNode *tail = &dummy; // Pointer to last node in merged list

        // Traverse both lists and choose the smaller node at each step
        while (list1 && list2) {
            if (list1->val <= list2->val) {
                tail->next = list1;
                list1 = list1->next;
            } else {
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }

        // Append the remaining nodes of the non-empty list
        tail->next = list1 ? list1 : list2;

        // Return the merged list's head
        return dummy.next;
    }
};

// ✅ Example usage (Helper functions)
void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Creating list1: 1 -> 2 -> 4
    ListNode* list1 = new ListNode(1);
    list1->next = new ListNode(2);
    list1->next->next = new ListNode(4);

    // Creating list2: 1 -> 3 -> 4
    ListNode* list2 = new ListNode(1);
    list2->next = new ListNode(3);
    list2->next->next = new ListNode(4);

    Solution sol;
    ListNode* mergedHead = sol.mergeTwoLists(list1, list2);

    cout << "Merged List: ";
    printList(mergedHead);
    // Merged List: 1 -> 1 -> 2 -> 3 -> 4 -> 4

    return 0;
}
