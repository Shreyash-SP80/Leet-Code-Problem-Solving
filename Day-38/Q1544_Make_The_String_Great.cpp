#include<iostream>
using namespace std;

/**
 * 1544. Make The String Great
 * ---------------------------
 * Approach:
 * - We process the string one character at a time.
 * - Use a result string as a stack.
 * - For each character:
 *    - If the last character in result (result.back()) forms a "bad pair" 
 *      with the current character (i.e., their ASCII difference is 32 
 *      → same letter but opposite cases), then pop the last char.
 *    - Otherwise, push the current char into result.
 * - Finally, result will be a "good string".
 *
 * Key Trick:
 * - ASCII difference between uppercase and lowercase of the same letter is always 32.
 *   Example: 'a' (97) and 'A' (65) → 97 - 65 = 32.
 *
 * Time Complexity: O(n), where n = length of s.
 * Space Complexity: O(n), for the result string (stack-like behavior).
 */


class Solution {
public:
    string makeGood(string s) {
        string result;

        for (char c: s) {
            if (!result.empty() && abs(result.back() - c) == 32) {
                result.pop_back(); // remove bad pair
            } else {
                result.push_back(c); // keep valid char
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

    string s1 = "leEeetcode";
    cout << "Input: " << s1 << "\n";
    cout << "Output: " << sol.makeGood(s1) << "\n\n";

    string s2 = "abBAcC";
    cout << "Input: " << s2 << "\n";
    cout << "Output: " << sol.makeGood(s2) << "\n\n";

    string s3 = "s";
    cout << "Input: " << s3 << "\n";
    cout << "Output: " << sol.makeGood(s3) << "\n";

    return 0;
}

/*
Expected Output:

Input: leEeetcode
Output: leetcode

Input: abBAcC
Output: 

Input: s
Output: s
*/





