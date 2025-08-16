#include <iostream>
#include <vector>
using namespace std;

/*
344. Reverse String
========================

Write a function that reverses a string.  
The input string is given as an array of characters `s`.

You must do this by modifying the input array **in-place** 
with O(1) extra memory.

------------------------------------------------
Example 1:
Input: s = ["h","e","l","l","o"]
Output: ["o","l","l","e","h"]

Example 2:
Input: s = ["H","a","n","n","a","h"]
Output: ["h","a","n","n","a","H"]
------------------------------------------------

# Intuition
The simplest way to reverse a string in-place is to swap characters 
from both ends moving towards the center. This avoids using extra memory.

# Approach
1. Use two pointers: one starting from the left (`down`) and the other 
   from the right (`up`).
2. While `down < up`, swap the characters at these two positions.
3. Increment `down` and decrement `up` after each swap.
4. This process continues until the entire string is reversed in place.

# Complexity Analysis
- Time Complexity: O(n), where `n` is the length of the string.  
  Each character is swapped at most once.
- Space Complexity: O(1), since the reversal is done in-place 
  without extra storage.
------------------------------------------------
*/


class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = s.size();
        int down = 0;
        int up = n - 1;
        while (down < up) {
            // char temp = s[down];
            // s[down++] = s[up];
            // s[up--] = temp;
            swap(s[down++], s[up--]); // Swap and move both pointers
        }
    }
};

// Driver Code
int main() {
    Solution sol;

    // Test case 1
    vector<char> s1 = {'h','e','l','l','o'};
    sol.reverseString(s1);
    for (char c : s1) cout << c;  // Expected: "olleh"
    cout << endl;

    // Test case 2
    vector<char> s2 = {'H','a','n','n','a','h'};
    sol.reverseString(s2);
    for (char c : s2) cout << c;  // Expected: "hannah"
    cout << endl;

    return 0;
}
