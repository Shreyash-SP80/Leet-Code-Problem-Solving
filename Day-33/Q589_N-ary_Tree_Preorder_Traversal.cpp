
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

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
