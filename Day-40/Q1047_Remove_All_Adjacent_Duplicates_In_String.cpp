#include <iostream>
#include <stack>
using namespace std;


class Solution {
public:
    string removeDuplicates(string s) {

        

        // By using Stack
        stack<char> st;

        for (char c : s) {
            if (!st.empty() && st.top() == c) {
                st.pop();  // remove duplicate
            } else {
                st.push(c);
            }
        }

        // Build final result
        string result;
        while (!st.empty()) {
            result.push_back(st.top());
            st.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

// Helper: Run a test
void runTest(string s) {
    Solution sol;
    cout << "Input: \"" << s << "\"\n";
    cout << "Output: \"" << sol.removeDuplicates(s) << "\"\n\n";
}

// Driver code
int main() {
    runTest("abbaca");   // Expected: "ca"
    runTest("azxxzy");   // Expected: "ay"
    runTest("aabccba");  // Expected: "a" (remove "aa" -> "bccba", remove "cc" -> "bba", remove "bb" -> "a")

    return 0;
}

