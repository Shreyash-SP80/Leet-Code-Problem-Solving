#include <iostream>
#include <vector>
using namespace std;

/*
2749. Minimum Operations to Make the Integer Zero
-------------------------------------------------
We are given two integers num1 and num2.  
In one operation, we can:
- Choose integer i in range [0, 60].
- Subtract (2^i + num2) from num1.

We must return:
- The minimum number of operations to make num1 = 0.
- Or -1 if it is impossible.
*/

/*
# Intuition
- After k operations:
    num1 - k*num2 = sum of chosen powers of 2.
- Let x = num1 - k*num2.
- x must be:
  1. Non-negative (since it's a sum of powers of 2).
  2. Representable as sum of k powers of two.
     - This means: popcount(x) <= k (we can split powers if needed).
     - Also: k <= x (since the minimum sum with k terms is 1+1+...+1 = k).
- The smallest k satisfying these conditions is our answer.

# Approach
1. Iterate k = 1 to 60 (safe bound since 2^60 is huge).
2. Compute x = num1 - k*num2.
3. If x >= 0 and popcount(x) <= k and k <= x → return k.
4. If no k satisfies, return -1.

# Complexity
- Time: O(60) = O(1), since k ranges only up to 60.
- Space: O(1), only variables are used.
*/


class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        for (long long k = 1; k <= 60; k++) {
            long long x = num1 - k * (long long) num2;

            if (x < 0) continue; // must be non-negative

            int bits = __builtin_popcountll(x); // count 1s in binary

            if (bits <= k && k <= x) return k;
        }
        return -1;
    }
};

// Driver
int main() {
    Solution sol;

    cout << sol.makeTheIntegerZero(3, -2) << endl; // 3
    cout << sol.makeTheIntegerZero(5, 7) << endl;  // -1
    cout << sol.makeTheIntegerZero(10, 2) << endl; // Example extra test

    return 0;
}
