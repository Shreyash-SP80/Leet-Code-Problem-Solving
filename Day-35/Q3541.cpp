
#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

/*
=======================================
   LeetCode 3541. Find Most Frequent Vowel and Consonant
=======================================

Problem:
---------
Given a string `s` (lowercase English letters), find:
1. The vowel ('a','e','i','o','u') with maximum frequency.
2. The consonant with maximum frequency.
Return the sum of these two frequencies.

- If multiple vowels/consonants have the same max frequency → pick any.
- If no vowel/consonant is present → take frequency as 0.

--------------------------------
Example 1:
Input:  "successes"
Output: 6
Explanation:
- Vowels → 'u'(1), 'e'(2) → max = 2
- Consonants → 's'(4), 'c'(2) → max = 4
Answer = 2 + 4 = 6

Example 2:
Input:  "aeiaeia"
Output: 3
Explanation:
- Vowels → 'a'(3), 'e'(2), 'i'(2) → max = 3
- Consonants → none → max = 0
Answer = 3 + 0 = 3
--------------------------------

Approach:
----------
1. Count frequency of each character using an unordered_map.
2. For each character:
   - If it is a vowel → update maxVowel.
   - Else (consonant) → update maxConsonant.
3. Return maxVowel + maxConsonant.

Time Complexity: O(n)   (iterate over string once + map traversal)
Space Complexity: O(26) ~ O(1)   (since only lowercase letters)
*/


class Solution {
public:
    int maxFreqSum(string s) {
        string vowels = "aeiou";
        unordered_map<char, int> freq;

        // Count frequencies
        for (char c : s) {
            freq[c]++;
        }

        int maxVowel = 0, maxConsonant = 0;

        // Find max frequency vowel & consonant
        for (auto &p : freq) {
            if (vowels.find(p.first) != string::npos) {
                maxVowel = max(maxVowel, p.second);
            } else {
                maxConsonant = max(maxConsonant, p.second);
            }
        }

        return maxVowel + maxConsonant;
    }
};

// Driver code
int main() {
    Solution sol;

    string s1 = "successes";
    cout << "Input: " << s1 << "\nOutput: " << sol.maxFreqSum(s1) << endl;
    // Expected: 6

    string s2 = "aeiaeia";
    cout << "Input: " << s2 << "\nOutput: " << sol.maxFreqSum(s2) << endl;
    // Expected: 3

    return 0;
}

// Output =>
// Input: successes
// Output: 6
// Input: aeiaeia
// Output: 3
