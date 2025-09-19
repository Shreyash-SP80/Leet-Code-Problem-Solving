#include <iostream>
#include <stack>
using namespace std;

/*
1047. Remove All Adjacent Duplicates In String 
---------------------------------------------
You are given a string s consisting of lowercase English letters.
A duplicate removal consists of choosing two adjacent and equal letters and removing them.

We repeatedly make duplicate removals on s until we no longer can.

Return the final string after all such duplicate removals have been made. 
It can be proven that the answer is unique.

Example 1:
Input: s = "abbaca"
Output: "ca"
Explanation:
- "abbaca" → remove "bb" → "aaca"
- "aaca" → remove "aa" → "ca"
Final answer: "ca"

Example 2:
Input: s = "azxxzy"
Output: "ay"
Explanation:
- "azxxzy" → remove "xx" → "azzy"
- "azzy" → remove "zz" → "ay"
Final answer: "ay"
*/

/**
 * Approach:
 * ---------
 * ✅ Using Stack (or string as a stack):
 * 1. Iterate through each character in string `s`.
 * 2. If stack top == current character → pop (remove duplicates).
 * 3. Otherwise, push character.
 * 4. Finally, build the result from stack and reverse it.
 *
 * Time Complexity: O(n)  (each char pushed/popped once)
 * Space Complexity: O(n) (stack)
 */

class Solution {
public:
    string removeDuplicates(string s) {

        // By using string
        // string result = "";

        // for (char c: s) {
        //     if (!result.empty() && result.back() == c) {
        //         result.pop_back();
        //     } else {
        //         result.push_back(c);
        //     }
        // }
        // return result;


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


// Output => 
// Input: "abbaca"
// Output: "ca"

// Input: "azxxzy"
// Output: "ay"

// Input: "aabccba"
// Output: "a"





