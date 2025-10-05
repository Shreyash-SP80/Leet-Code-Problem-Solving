#include <iostream>
using namespace std;

/*
🧮 LeetCode 69 — Sqrt(x)
Difficulty: Easy
Topic: Binary Search
 
-------------------------------------------------
📝 Problem Statement:
Given a non-negative integer x, return the square root of x rounded down to the nearest integer.
The returned integer should be non-negative as well.

You must NOT use any built-in exponent function or operator.
For example, do NOT use pow(x, 0.5) in C++ or x ** 0.5 in Python.

-------------------------------------------------
📘 Examples:

Example 1:
Input: x = 4
Output: 2
Explanation: The square root of 4 is 2, so we return 2.

Example 2:
Input: x = 8
Output: 2
Explanation: The square root of 8 is 2.82842..., and since we round it down to the nearest integer, 2 is returned.

-------------------------------------------------
⚙️ Approach: Binary Search

1. If x is 0 or 1 → return x directly.
2. Use binary search between 0 and x:
   - Compute mid = (low + high) / 2
   - If mid * mid == x → return mid
   - If mid * mid < x → store mid as potential answer (ans) and move right (low = mid + 1)
   - Else → move left (high = mid - 1)
3. After the loop, ans will be the integer part of the square root.

-------------------------------------------------
⏱ Time Complexity: O(log x)
💾 Space Complexity: O(1)

-------------------------------------------------
📚 References:
- https://leetcode.com/problems/sqrtx/
- https://www.geeksforgeeks.org/binary-search/
*/


class Solution {
public:
    int mySqrt(int x) {
        if (x == 0 || x == 1) return x;  

        long long low = 0, high = x, ans = 0;

        while (low <= high) {
            long long mid = (low + high) / 2;
            long long sq = mid * mid;

            if (sq == x) {
                return mid;  
            } 
            else if (sq < x) {
                ans = mid;       
                low = mid + 1;  
            } 
            else {
                high = mid - 1;  
            }
        }
        return ans;  
    }
};

// ------------------- MAIN FUNCTION -------------------
int main() {
    Solution solution;
    int x;

    cout << "Enter a non-negative integer: ";
    cin >> x;

    int result = solution.mySqrt(x);
    cout << "The integer square root of " << x << " is: " << result << endl;

    return 0;
}

