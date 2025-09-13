
#include <iostream>
#include <string>
using namespace std;


/*
=======================================
   LeetCode 3227. Vowels Game in a String
=======================================

Problem:
---------
Alice and Bob are playing a game on a string `s`.

Rules:
- Alice starts first.
- On Alice's turn → remove any non-empty substring containing an **odd** number of vowels.
- On Bob's turn → remove any non-empty substring containing an **even** number of vowels.
- The first player who cannot move loses.
- Both play optimally.

Return true if Alice wins, otherwise false.

Vowels are: a, e, i, o, u.

--------------------------------
Example 1:
Input:  "leetcoder"
Output: true

Explanation:
- Alice deletes substring with 3 vowels → s = "der"
- Bob deletes substring with 0 vowels → s = "er"
- Alice deletes "er" (1 vowel) → s = ""
- Bob cannot move → Alice wins.

Example 2:
Input:  "bbcd"
Output: false

Explanation:
- Alice has no valid move initially → Alice loses.

--------------------------------

Approach (based on this code):
-------------------------------
1. Alice can only make a move if the string has **at least one vowel** 
   (since she needs an odd count of vowels).
2. If the string contains a vowel → Alice always wins (because she plays first).
3. If there are no vowels → Alice cannot move and loses immediately.

Time Complexity: O(n)   (single scan of string)
Space Complexity: O(1)  (constant extra space)
*/


class Solution {
public:
    bool doesAliceWin(string s) {
        string vowels = "aeiou";

        for (char c : s) {
            if (vowels.find(c) != string::npos) {
                return true;   // Found a vowel → Alice wins
            }
        }
        return false;          // No vowel → Alice cannot move → loses
    }
};

// Driver code
int main() {
    Solution sol;

    string s1 = "leetcoder";
    cout << "Input: " << s1 << "\nOutput: "
         << (sol.doesAliceWin(s1) ? "true" : "false") << endl;
    // Expected: true

    string s2 = "bbcd";
    cout << "Input: " << s2 << "\nOutput: "
         << (sol.doesAliceWin(s2) ? "true" : "false") << endl;
    // Expected: false

    return 0;
}

// Output => 
// Input: leetcoder
// Output: true
// Input: bbcd
// Output: false
