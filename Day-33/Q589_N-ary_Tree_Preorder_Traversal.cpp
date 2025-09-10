
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/*
589. N-ary Tree Preorder Traversal
--------------------------------------------
Given the root of an N-ary tree, return the preorder traversal
of its nodes' values.

Preorder means:
    - Process the root node first
    - Then recursively process all children (from left to right)
*/

/*
# Intuition
- In preorder traversal:
  1. Visit the current node first.
  2. Then recursively visit each child.
- For an N-ary tree, each node may have multiple children.
- Recursive DFS is simple; iterative stack-based solution is also possible.

# Approach
### Recursive:
1. Start from root.
2. Add root's value to result.
3. Recurse for each child in order.

### Iterative (stack):
1. Push root onto stack.
2. While stack is not empty:
   - Pop top node, add its value.
   - Push its children onto stack **in reverse order**, so leftmost child is processed first.

# Complexity
- Time: O(n), visit each node once.
- Space: O(n) recursion stack (recursive) or explicit stack (iterative).
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
    vector<int> preorder(Node* root) {
        vector<int> result;
        if (!root) return result;

        stack<Node*> st;
        st.push(root);

        while (!st.empty()) {
            Node* node = st.top();
            st.pop();
            result.push_back(node->val);

            // Push children in reverse order
            for (int i = node->children.size() - 1; i >= 0; i--) {
                if (node->children[i]) st.push(node->children[i]);
            }
        }
        return result;
    }
};

// Driver
int main() {
    // Example: root = [1,null,3,2,4,null,5,6]
    Node* node5 = new Node(5);
    Node* node6 = new Node(6);
    Node* node3 = new Node(3, {node5, node6});
    Node* node2 = new Node(2);
    Node* node4 = new Node(4);
    Node* root = new Node(1, {node3, node2, node4});

    Solution sol;
    vector<int> result = sol.preorder(root);
    for (int x : result) cout << x << " ";
    cout << endl; // Output: 1 3 5 6 2 4

    return 0;
}

