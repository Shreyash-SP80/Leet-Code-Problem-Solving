#include <iostream>
using namespace std;

/** 
 * 921. Minimum Add to Make Parentheses Valid 
 * ------------------------------------------
 * Approach:
 * - We need to make the parentheses string valid with the minimum insertions.
 * - Maintain two counters:
 *      1. balance   → number of unmatched '('
 *      2. insertion → number of ')' insertions needed when an unmatched ')' is found
 * - Iterate over the string:
 *      - If char is '(' → increase balance.
 *      - If char is ')' → 
 *            - if balance > 0 → match it with an open bracket (balance--).
 *            - else → no open bracket available, so we need an extra '(' (insertion++).
 * - Final answer = balance (unmatched '(' left) + insertion (extra needed).
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */

class Solution {
public:
    int minAddToMakeValid(string s) {
        int balance = 0;    // count of unmatched '('
        int insertion = 0;  // count of needed insertions

        for (char c: s) {
            if (c == '(') {
                balance++;
            } else {
                if (balance > 0) {
                    balance--;  // match with an open bracket
                } else {
                    insertion++; // need an extra '('
                }
            }
        }

        return balance + insertion;
    }
};

// --------------------
// Driver Code
// --------------------
int main() {
    Solution sol;

    string s1 = "())";
    cout << "Input: \"())\"\nOutput: " << sol.minAddToMakeValid(s1) << "\n\n";

    string s2 = "(((";
    cout << "Input: \"((\"\nOutput: " << sol.minAddToMakeValid(s2) << "\n\n";

    string s3 = "()";
    cout << "Input: \"()\"\nOutput: " << sol.minAddToMakeValid(s3) << "\n\n";

    string s4 = "()))((";
    cout << "Input: \"()))((\"\nOutput: " << sol.minAddToMakeValid(s4) << "\n";

    return 0;
}


/*
Expected Output:

Input: "())"
Output: 1

Input: "((("
Output: 3

Input: "()"
Output: 0

Input: "()))(("
Output: 4
*/





