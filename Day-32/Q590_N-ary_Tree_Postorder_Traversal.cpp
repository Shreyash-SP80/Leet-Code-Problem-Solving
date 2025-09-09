#include <iostream>
#include <vector>
using namespace std;


/*
590. N-ary Tree Postorder Traversal
--------------------------------------------
Given the root of an N-ary tree, return the postorder traversal
of its nodes' values.

Postorder means:
    - Traverse all children first
    - Then process the root node
*/

/*
# Intuition
- In postorder, for each node:
    1. Visit all children recursively in order.
    2. Visit the node itself.
- For an N-ary tree, unlike binary trees, each node can have many children.
- This can be solved easily with recursion (DFS).
- Iterative solutions use a stack with reversed order trick.

# Approach (Recursive)
1. Define a helper function `dfs(node)`:
   - For each child of node → recursively call dfs.
   - After processing children, push node's value into result.
2. Call dfs(root).
3. Return result.

# Complexity
- Time: O(n), visiting every node once.
- Space: O(n) for recursion stack (worst-case skewed tree).
*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}
    Node(int _val) { val = _val; }
    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}
    Node(int _val) { val = _val; }
    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> result;
        dfs(root, result);
        return result;

        // Iterative Solution =>
        
        // if (!root) return {};
        // vector<int> ans;
        // stack<Node*> st;

        // st.push(root);

        // while (!st.empty()) {
        //     Node* node = st.top();
        //     st.pop();
        //     ans.push_back(node->val);
        //     for (auto child: node->children) {
        //         if (child) st.push(child);
        //     }
        // }

        // reverse(ans.begin(), ans.end());
        // return ans;
    }

private:
    // Using recursion
    void dfs(Node* node, vector<int>& result) {
        if (!node) return;  // base condition
        for (Node* child : node->children) {
            dfs(child, result);
        }
        result.push_back(node->val);
    }
};

// Driver
int main() {
    Solution sol;

    // Example: root = [1,null,3,2,4,null,5,6]
    Node* node5 = new Node(5);
    Node* node6 = new Node(6);
    Node* node3 = new Node(3, {node5, node6});
    Node* node2 = new Node(2);
    Node* node4 = new Node(4);
    Node* root = new Node(1, {node3, node2, node4});

    vector<int> result = sol.postorder(root);
    for (int x : result) cout << x << " "; 
    cout << endl; // 5 6 3 2 4 1

    return 0;
}



