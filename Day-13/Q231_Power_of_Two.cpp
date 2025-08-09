#include <iostream>
using namespace std;

/*
Problem: 231. Power of Two
--------------------------
Given an integer n, return true if it is a power of two. Otherwise, return false.

Definition:
-----------
An integer n is a power of two if there exists an integer x such that:
    n == 2^x

Example 1:
----------
Input:  n = 1
Output: true
Explanation: 2^0 = 1

Example 2:
----------
Input:  n = 16
Output: true
Explanation: 2^4 = 16

Example 3:
----------
Input:  n = 3
Output: false

Constraints:
------------
- -2^31 <= n <= 2^31 - 1

-------------------------------------------------------------------
Approach:
---------
1. A number is a power of two if:
    - It is greater than 0.
    - It has exactly one bit set in its binary representation.
2. The trick: 
    - For powers of two, n & (n - 1) == 0.
      Example: 8 in binary: 1000
               7 in binary: 0111
               AND result: 0000
3. Steps:
    - Check if n > 0.
    - Use bitwise AND to verify the one-bit property.
4. Time Complexity: O(1)
5. Space Complexity: O(1)
-------------------------------------------------------------------
*/


class Solution {
public:
    bool isPowerOfTwo(int n) {
        // Check: Positive number & only one bit set
        return (n > 0) && ((n & (n - 1)) == 0);
    }
};

int main() {
    Solution obj;

    // Test cases
    int test1 = 1;
    int test2 = 16;
    int test3 = 3;

    cout << "Input: " << test1 << " -> Output: " << (obj.isPowerOfTwo(test1) ? "true" : "false") << endl;
    cout << "Input: " << test2 << " -> Output: " << (obj.isPowerOfTwo(test2) ? "true" : "false") << endl;
    cout << "Input: " << test3 << " -> Output: " << (obj.isPowerOfTwo(test3) ? "true" : "false") << endl;

    return 0;
}

// Output =>
// Input: 1 -> Output: true
// Input: 16 -> Output: true
// Input: 3 -> Output: false