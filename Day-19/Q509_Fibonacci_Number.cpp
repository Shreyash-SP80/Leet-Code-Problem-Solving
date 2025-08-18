#include <iostream>
using namespace std;

/*
509. Fibonacci Number
---------------------
The Fibonacci numbers, commonly denoted F(n), form a sequence such that each number 
is the sum of the two preceding ones, starting from 0 and 1. That is:

    F(0) = 0
    F(1) = 1
    F(n) = F(n - 1) + F(n - 2), for n > 1.

Given an integer n, return F(n).

Example 1:
Input: n = 2
Output: 1
Explanation: F(2) = F(1) + F(0) = 1 + 0 = 1.

Example 2:
Input: n = 3
Output: 2
Explanation: F(3) = F(2) + F(1) = 1 + 1 = 2.

Example 3:
Input: n = 4
Output: 3
Explanation: F(4) = F(3) + F(2) = 2 + 1 = 3.
*/

/*
# Intuition
The Fibonacci sequence builds upon the sum of the two previous numbers.  
A naive recursive solution has exponential time complexity, which is inefficient.  
Instead, we can use an iterative approach that computes values in sequence, keeping track of the last two values.

# Approach
1. Handle the base cases: if n < 2, directly return n (F(0) = 0, F(1) = 1).
2. Initialize two variables `a = 0` and `b = 1` to represent F(0) and F(1).
3. Iterate from 2 up to n, updating the Fibonacci values step by step:
   - Compute the next Fibonacci number as `c = a + b`.
   - Shift values: set `a = b` and `b = c`.
4. Return `b` as the final answer.

# Complexity
- Time Complexity: O(n), since we loop from 2 to n.
- Space Complexity: O(1), as we only store two variables regardless of n.
*/


class Solution {
public:
    int fib(int n) {
        if (n < 2) return n; // handle base cases
        int a = 0, b = 1;

        for (int i = 2; i <= n; i++) {
            int c = a + b;
            a = b;
            b = c;
        }
        return b;
    }
};

// Driver code for local testing
int main() {
    Solution sol;
    int n;
    cout << "Enter n: ";
    cin >> n;
    cout << "Fibonacci(" << n << ") = " << sol.fib(n) << endl;
    return 0;
}
