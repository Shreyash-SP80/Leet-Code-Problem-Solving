
#include <iostream>
#inlcude <vector>
using namespace std;

/*
316. Remove Duplicate Letters
-----------------------------

You are given a string s, remove duplicate letters so that every letter 
appears once and only once. You must make sure your result is the smallest 
in lexicographical order among all possible results.

Example 1:
Input: s = "bcabc"
Output: "abc"

Example 2:
Input: s = "cbacdcbc"
Output: "acdb"

Constraints:
1 <= s.length <= 10^4
s consists of lowercase English letters.

-------------------------------------------------
Approach:
1. Count the frequency of each character using an array.
2. Use a visited array to mark whether a character is already in the result.
3. Iterate through the string:
   - Decrease the frequency of the current character.
   - If the character is already visited, skip it.
   - Otherwise:
       * While the last character in the result is greater than the current 
         character and still appears later (freq > 0), remove it from the result 
         and mark it as unvisited.
       * Add the current character to the result and mark it visited.
4. Return the final result string.

This ensures each letter appears once and the result is the smallest 
lexicographically.
*/


class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> freq(26, 0);
        vector<bool> visited(26, false);

        // Count frequency of each character
        for (char c : s) freq[c - 'a']++;

        string result = "";
        for (char c : s) {
            freq[c - 'a']--;  // Decrease frequency since we are processing it

            if (visited[c - 'a']) continue; // Skip if already in result

            // Maintain lexicographical order
            while (!result.empty() && result.back() > c && freq[result.back() - 'a'] > 0) {
                visited[result.back() - 'a'] = false;
                result.pop_back();
            }
            result.push_back(c);
            visited[c - 'a'] = true;
        }
        return result;
    }
};

// Driver code
int main() {
    Solution sol;

    string s1 = "bcabc";
    cout << "Input: " << s1 << endl;
    cout << "Output: " << sol.removeDuplicateLetters(s1) << endl;

    string s2 = "cbacdcbc";
    cout << "Input: " << s2 << endl;
    cout << "Output: " << sol.removeDuplicateLetters(s2) << endl;

    return 0;
}


/*
Expected Output:
Input: bcabc
Output: abc
Input: cbacdcbc
Output: acdb
*/



















