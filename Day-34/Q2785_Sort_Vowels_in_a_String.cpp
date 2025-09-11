#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

/*
===============================
   LeetCode 2785. Sort Vowels in a String
===============================

Problem:
---------
You are given a string `s`. Rearrange it so that:
1. Consonants remain in their original positions.
2. Vowels ('a','e','i','o','u' and their uppercase forms) 
   appear in sorted order by ASCII values.

Return the modified string.

-------------------------------
Example 1:
Input:  "lEetcOde"
Output: "lEOtcede"

Example 2:
Input:  "lYmpH"
Output: "lYmpH"
-------------------------------

Approach:
---------
1. Store all vowels from the string in a vector.
2. Sort this vector (ASCII order ensures correct sequence).
3. Traverse the string again:
   - If the character is a vowel, replace it with the next sorted vowel.
   - Otherwise, leave consonants unchanged.
4. Return the final string.

Time Complexity: O(n log n)   (sorting vowels)
Space Complexity: O(n)        (to store vowels)
*/

class Solution {
public:
    string sortVowels(string s) {
        string vowels = "aeiouAEIOU";
        vector<char> v;

        // Step 1: Extract vowels
        for (char c : s) {
            if (vowels.find(c) != string::npos) {   // string::npos -> not found
                v.push_back(c);
            }
        }

        // Step 2: Sort vowels
        sort(v.begin(), v.end());

        // Step 3: Replace vowels in order
        int j = 0;
        for (int i = 0; i < s.size(); i++) {
            if (vowels.find(s[i]) != string::npos) {
                s[i] = v[j++];
            }
        }
        return s;
    }
};

// Driver code
int main() {
    Solution sol;

    string s1 = "lEetcOde";
    cout << "Input: " << s1 << "\nOutput: " << sol.sortVowels(s1) << endl;
    // Expected: lEOtcede

    string s2 = "lYmpH";
    cout << "Input: " << s2 << "\nOutput: " << sol.sortVowels(s2) << endl;
    // Expected: lYmpH

    return 0;

}

// Output =>
// Input: lEetcOde
// Output: lEOtcede
// Input: lYmpH
// Output: lYmpH

