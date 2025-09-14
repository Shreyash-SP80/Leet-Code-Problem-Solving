
#include <iostream>
#include <vector>
using namespace std;

/*
========================================================
   LeetCode 654. Maximum Binary Tree
========================================================

Problem:
---------
You are given an integer array nums with no duplicates. 
A maximum binary tree can be built recursively using:
1. Create a root node with the maximum value in nums.
2. Recursively build the left subtree on the subarray left of the maximum.
3. Recursively build the right subtree on the subarray right of the maximum.

Return the maximum binary tree built from nums.

--------------------------------------------------------
Example 1:
Input: nums = [3,2,1,6,0,5]
Output: [6,3,5,null,2,0,null,null,1]

Example 2:
Input: nums = [3,2,1]
Output: [3,null,2,null,1]
--------------------------------------------------------

Approach:
----------
1. Use recursion with helper function build(nums, l, r).
2. Find index of maximum element in range [l, r].
3. Create a node with this value.
4. Recursively build left subtree with [l, maxIdx-1].
5. Recursively build right subtree with [maxIdx+1, r].
6. Base case → return nullptr if l > r.

Time Complexity: O(n^2) (worst case when array is sorted)
Space Complexity: O(n)   (recursion depth)

========================================================
*/


// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return build(nums, 0, (int)nums.size() - 1);
    }

private:
    TreeNode* build(const vector<int>& nums, int l, int r) {
        if (l > r) return nullptr;

        int maxIdx = l;
        for (int i = l + 1; i <= r; ++i) {
            if (nums[i] > nums[maxIdx]) maxIdx = i;
        }

        TreeNode* root = new TreeNode(nums[maxIdx]);
        root->left  = build(nums, l, maxIdx - 1);
        root->right = build(nums, maxIdx + 1, r);
        return root;
    }
};

// Helper function: Preorder traversal to display tree
void preorder(TreeNode* root) {
    if (!root) return;
    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

// Driver code
int main() {
    Solution sol;

    vector<int> nums1 = {3,2,1,6,0,5};
    TreeNode* root1 = sol.constructMaximumBinaryTree(nums1);
    cout << "Preorder traversal of tree from nums1: ";
    preorder(root1); // Expected output: 6 3 2 1 5 0
    cout << endl;

    vector<int> nums2 = {3,2,1};
    TreeNode* root2 = sol.constructMaximumBinaryTree(nums2);
    cout << "Preorder traversal of tree from nums2: ";
    preorder(root2); // Expected output: 3 2 1
    cout << endl;

    return 0;
}

// Output => 
// Preorder traversal of tree from nums1: 6 3 2 1 5 0 
// Preorder traversal of tree from nums2: 3 2 1 


