#include <iostream>
using namespace std;


/*
Problem: 1486. XOR Operation in an Array
----------------------------------------
You are given an integer n and an integer start.

Define an array nums where nums[i] = start + 2 * i (0-indexed) 
and n == nums.length.

Return the bitwise XOR of all elements of nums.

Example 1:
Input: n = 5, start = 0
Output: 8
Explanation: nums = [0, 2, 4, 6, 8], 
(0 ^ 2 ^ 4 ^ 6 ^ 8) = 8

Example 2:
Input: n = 4, start = 3
Output: 8
Explanation: nums = [3, 5, 7, 9], 
(3 ^ 5 ^ 7 ^ 9) = 8

------------------------------------------------
Approach:
------------------------------------------------
1. Initialize result = 0.
2. Iterate i from 0 to n-1.
3. For each i, compute element = start + 2 * i.
4. Update result by XORing with the element: result ^= element.
5. Return result.

Note: We don't need to store the array, so space usage is O(1).

------------------------------------------------
Complexity:
------------------------------------------------
- Time Complexity: O(n) → We loop once through n elements.
- Space Complexity: O(1) → We only use a few variables.

*/


int xorOperation(int n, int start) {
    int result = 0;
    for (int i = 0; i < n; i++) {
        result ^= start + 2 * i; // XOR with each element
    }
    return result;
}

int main() {
    // Example 1
    int n1 = 5, start1 = 0;
    cout << "Input: n = " << n1 << ", start = " << start1 << endl;
    cout << "Output: " << xorOperation(n1, start1) << endl;
    // Expected: 8

    cout << "------------------------" << endl;

    // Example 2
    int n2 = 4, start2 = 3;
    cout << "Input: n = " << n2 << ", start = " << start2 << endl;
    cout << "Output: " << xorOperation(n2, start2) << endl;
    // Expected: 8

    cout << "------------------------" << endl;

    // Additional Test
    int n3 = 1, start3 = 7;
    cout << "Input: n = " << n3 << ", start = " << start3 << endl;
    cout << "Output: " << xorOperation(n3, start3) << endl;
    // Expected: 7

    return 0;
}

/*
Sample Output:
--------------
Input: n = 5, start = 0
Output: 8
------------------------
Input: n = 4, start = 3
Output: 8
------------------------
Input: n = 1, start = 7
Output: 7
*/
