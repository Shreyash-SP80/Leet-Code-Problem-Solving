
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


