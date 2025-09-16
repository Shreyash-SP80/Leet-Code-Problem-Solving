#include <iostream>
using namespace std;

class Solution {
public:
    string removeOuterParentheses(string s) {
        string result;
        int depth = 0;

        for (char c: s) {
            if (c == '(') {
                if (depth > 0) result.push_back(c); // skip outermost '('
                depth++;
            } else {
                depth--;
                if (depth > 0) result.push_back(c); // skip outermost ')'
            }
        }
        return result;
    }
};

// --------------------
// Driver Code
// --------------------
int main() {
    Solution sol;

    string s1 = "(()())(())";
    cout << "Input: " << s1 << "\n";
    cout << "Output: " << sol.removeOuterParentheses(s1) << "\n\n";

    string s2 = "(()())(())(()(()))";
    cout << "Input: " << s2 << "\n";
    cout << "Output: " << sol.removeOuterParentheses(s2) << "\n\n";

    string s3 = "()()";
    cout << "Input: " << s3 << "\n";
    cout << "Output: " << sol.removeOuterParentheses(s3) << "\n";

    return 0;
}

