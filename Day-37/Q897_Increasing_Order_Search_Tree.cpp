
#include <iostream>
#include <vector>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode *dummy = new TreeNode(0);
        TreeNode *curr = dummy;

        inorder(root, curr);

        return dummy->right;  // new root is right child of dummy
    }

private:
    void inorder(TreeNode* node, TreeNode*& curr) {
        if (!node) return;

        inorder(node->left, curr);

        node->left = nullptr;        // remove left link
        curr->right = node;          // attach node to the right
        curr = node;                 // move pointer

        TreeNode* right = node->right;  
        node->right = nullptr;       // detach old right
        inorder(right, curr);        // process right subtree
    }
};

// Utility function: print tree as right-skewed list
void printRightSkewed(TreeNode* root) {
    while (root) {
        cout << root->val;
        if (root->right) cout << " -> ";
        root = root->right;
    }
    cout << endl;
}

// Driver code
int main() {
    Solution sol;

    // Example 1: [5,3,6,2,4,null,8,1,null,null,null,7,9]
    TreeNode* root1 = new TreeNode(5);
    root1->left = new TreeNode(3);
    root1->right = new TreeNode(6);
    root1->left->left = new TreeNode(2);
    root1->left->right = new TreeNode(4);
    root1->right->right = new TreeNode(8);
    root1->left->left->left = new TreeNode(1);
    root1->right->right->left = new TreeNode(7);
    root1->right->right->right = new TreeNode(9);

    TreeNode* result1 = sol.increasingBST(root1);
    cout << "Output 1: ";
    printRightSkewed(result1);
    // Expected: 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> 9

    // Example 2: [5,1,7]
    TreeNode* root2 = new TreeNode(5);
    root2->left = new TreeNode(1);
    root2->right = new TreeNode(7);

    TreeNode* result2 = sol.increasingBST(root2);
    cout << "Output 2: ";
    printRightSkewed(result2);
    // Expected: 1 -> 5 -> 7

    return 0;
}

