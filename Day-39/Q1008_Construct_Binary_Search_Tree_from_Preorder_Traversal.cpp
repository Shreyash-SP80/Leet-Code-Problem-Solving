#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/**
 * Definition for a binary tree node.
 */
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
    int idx = 0;

    TreeNode* build(vector<int>& preorder, int bound) {
        if (idx == preorder.size() || preorder[idx] > bound)
            return nullptr;

        TreeNode* root = new TreeNode(preorder[idx++]);
        root->left = build(preorder, root->val);   // left subtree
        root->right = build(preorder, bound);      // right subtree
        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return build(preorder, INT_MAX);
    }
};

// Helper: Print tree in level order (LeetCode format)
void printLevelOrder(TreeNode* root) {
    if (!root) {
        cout << "[]\n";
        return;
    }

    queue<TreeNode*> q;
    q.push(root);
    cout << "[";
    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        if (node) {
            cout << node->val << ",";
            q.push(node->left);
            q.push(node->right);
        } else {
            cout << "null,";
        }
    }
    cout << "\b]\n"; // remove last comma
}

// Driver code
int main() {
    Solution sol;

    vector<int> preorder1 = {8, 5, 1, 7, 10, 12};
    TreeNode* root1 = sol.bstFromPreorder(preorder1);
    cout << "Input: [8,5,1,7,10,12]\n";
    cout << "Output: ";
    printLevelOrder(root1);   // Expected: [8,5,10,1,7,null,12]

    vector<int> preorder2 = {1, 3};
    TreeNode* root2 = sol.bstFromPreorder(preorder2);
    cout << "Input: [1,3]\n";
    cout << "Output: ";
    printLevelOrder(root2);   // Expected: [1,null,3]

    return 0;
}
