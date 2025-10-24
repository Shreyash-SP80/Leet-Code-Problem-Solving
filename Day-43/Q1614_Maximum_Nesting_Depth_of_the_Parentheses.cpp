#include <iostream>
#include <stack>
#include <string>
using namespace std;


/*
🧮 LeetCode 1614 — Maximum Nesting Depth of the Parentheses
Difficulty: Easy
Topic: Stack 

-------------------------------------------------
📝 Problem Statement:
Given a valid parentheses string s, return the nesting depth of s.
The nesting depth is the maximum number of nested parentheses.

-------------------------------------------------
📘 Examples:

Example 1:
Input: s = "(1+(2*3)+((8)/4))+1"
Output: 3
Explanation: Digit 8 is inside of 3 nested parentheses in the string.

Example 2:
Input: s = "(1)+((2))+(((3)))"
Output: 3
Explanation: Digit 3 is inside of 3 nested parentheses.

Example 3:
Input: s = "()(())((()()))"
Output: 3
Explanation: The maximum depth of nested parentheses is 3.

-------------------------------------------------
⚙️ Approach: Using Stack

1. Initialize an empty stack and a variable `maxDepth` = 0.
2. Traverse each character `c` in the string `s`:
   - If `c` is '(' → push it to the stack and update maxDepth = max(maxDepth, stack.size())
   - If `c` is ')' → pop from the stack (if not empty)
   - Ignore other characters (digits/operators)
3. Return `maxDepth` after processing the string.

-------------------------------------------------
⏱ Time Complexity: O(n) — traverse the string once
💾 Space Complexity: O(n) — stack may hold all open parentheses
*/


class Solution {
public:
    int maxDepth(string s) {
        stack<char> st;
        int max = 0;

        for (char c: s) {
            if (c == '(') {
                st.push(c);
                int curr = st.size();
                if (curr > max) 
                    max = curr;
            } else if (c == ')') {
                if (!st.empty()) 
                    st.pop();
            }
            // Ignore other characters
        }

        return max;
    }
};

// ------------------- MAIN FUNCTION -------------------
int main() {
    Solution solution;
    string s;

    cout << "Enter a valid parentheses string: ";
    getline(cin, s);

    int result = solution.maxDepth(s);
    cout << "Maximum nesting depth is: " << result << endl;

    return 0;
}

// Output =>
// Enter a valid parentheses string: (1+(2*3)+((8)/4))+1
// Maximum nesting depth is: 3

// Bottom-up Level Order Traversal: [[15,7],[9,20],[3]]


