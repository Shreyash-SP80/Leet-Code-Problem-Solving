#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

/*
Problem: 869. Reordered Power of 2
----------------------------------
You are given an integer n. We reorder the digits in any order (including the original order) 
such that the leading digit is not zero.

Return true if and only if we can do this so that the resulting number is a power of two.

Example 1:
Input: n = 1
Output: true

Example 2:
Input: n = 10
Output: false

------------------------------------------------
Approach:
------------------------------------------------
1. Convert `n` to a string and sort its digits.
2. Iterate over all powers of two that fit in the integer range (2^0 to 2^30 for n ≤ 10^9).
3. For each power of two:
   - Convert it to a string and sort its digits.
   - If it matches the sorted form of `n`, return true.
4. If no match is found after checking all powers of two, return false.

Key Observation:
Two numbers are permutations of each other if and only if their sorted digit strings are identical.

------------------------------------------------
Complexity:
------------------------------------------------
- Time Complexity: O(31 × k log k) where k ≤ 10 (number of digits) → practically O(1)
- Space Complexity: O(k) → constant space

*/


using namespace std;

bool reorderedPowerOf2(int n) {
    string s = to_string(n);
    sort(s.begin(), s.end());

    for (int i = 0; i < 32; i++) { // 2^0 to 2^31
        string power = to_string(1 << i);
        sort(power.begin(), power.end());
        if (power == s) {
            return true;
        }
    }
    return false;
}

int main() {
    int n;

    // Example 1
    n = 1;
    cout << "Input: " << n << endl;
    cout << "Output: " << (reorderedPowerOf2(n) ? "true" : "false") << endl;
    // Expected: true

    cout << "------------------------" << endl;

    // Example 2
    n = 10;
    cout << "Input: " << n << endl;
    cout << "Output: " << (reorderedPowerOf2(n) ? "true" : "false") << endl;
    // Expected: false

    cout << "------------------------" << endl;

    // Additional Example
    n = 128;
    cout << "Input: " << n << endl;
    cout << "Output: " << (reorderedPowerOf2(n) ? "true" : "false") << endl;
    // Expected: true

    return 0;
}

/*
Sample Output:
--------------
Input: 1
Output: true
------------------------
Input: 10
Output: false
------------------------
Input: 128
Output: true
*/
