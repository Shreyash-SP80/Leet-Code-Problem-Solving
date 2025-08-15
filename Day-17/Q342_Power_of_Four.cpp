#include <iostream>
using namespace std;


/*
342. Power of Four

Given an integer n, return true if it is a power of four. Otherwise, return false.

An integer n is a power of four if there exists an integer x such that n == 4^x.

Example 1:
Input: n = 16
Output: true

Example 2:
Input: n = 5
Output: false

Example 3:
Input: n = 1
Output: true

------------------------------------------------------------
Approach:
A number is a power of four if:
1. It is greater than 0.
2. It can be divided by 4 repeatedly until the result is 1.

We use a simple loop:
- If n <= 0 → return false.
- While n is divisible by 4, divide it by 4.
- If the result is 1 after the loop, return true; otherwise, return false.

This approach avoids bitwise operations and is easy to understand.

Time Complexity: O(log₄(n)) — We divide n by 4 each iteration.
Space Complexity: O(1) — We use no extra data structures.
------------------------------------------------------------
*/


class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n <= 0) return false; // Negative numbers & zero are not powers of 4
        while (n % 4 == 0) {      // Keep dividing by 4 while divisible
            n /= 4;
        }
        return n == 1;            // If reduced to 1 → it's a power of 4
    }
};

int main() {
    Solution sol;

    // Test case 1
    int n1 = 16;
    cout << "Input: 16\nOutput: " << (sol.isPowerOfFour(n1) ? "true" : "false") << "\n\n";

    // Test case 2
    int n2 = 5;
    cout << "Input: 5\nOutput: " << (sol.isPowerOfFour(n2) ? "true" : "false") << "\n\n";

    // Test case 3
    int n3 = 1;
    cout << "Input: 1\nOutput: " << (sol.isPowerOfFour(n3) ? "true" : "false") << "\n";

    return 0;
}
