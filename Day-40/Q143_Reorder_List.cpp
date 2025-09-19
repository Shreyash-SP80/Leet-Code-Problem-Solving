#include <iostream>
#include <vector>
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

