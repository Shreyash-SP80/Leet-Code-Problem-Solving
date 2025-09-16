#include <iostream>
using namespace std;

/**
 * 1021. Remove Outermost Parentheses
 * ----------------------------------
 * Approach:
 * - Use a counter `depth` to track the nesting level of parentheses.
 * - When we encounter '(', if depth > 0, it means it’s not the outermost one,
 *   so we add it to the result. Then increase depth.
 * - When we encounter ')', first decrease depth, and if depth > 0,
 *   it means it’s not the outermost one, so we add it to the result.
 * - This way, the outermost parentheses of every primitive block are removed.
 *
 * Time Complexity: O(n), where n is the length of the string.
 * Space Complexity: O(n), for the result string.
 */


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

/*
Expected Output:

Input: (()())(())
Output: ()()()

Input: (()())(())(()(()))
Output: ()()()()(())

Input: ()()
Output: 
*/

