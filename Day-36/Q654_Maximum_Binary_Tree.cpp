
#include <iostream>
#include <vector>
using namespace std;

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

