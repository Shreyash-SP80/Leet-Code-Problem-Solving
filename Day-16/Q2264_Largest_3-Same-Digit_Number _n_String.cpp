#include <iostream>
using namespace std;

/*
2264. Largest 3-Same-Digit Number in String

You are given a string num representing a large integer.
An integer is good if it meets the following conditions:
1. It is a substring of num with length 3.
2. It consists of only one unique digit.

Return the maximum good integer as a string or an empty string "" if no such integer exists.

Note:
- A substring is a contiguous sequence of characters within a string.
- There may be leading zeroes in num or a good integer.

Example 1:
Input: num = "6777133339"
Output: "777"
Explanation: There are two distinct good integers: "777" and "333".
"777" is the largest, so we return "777".

Example 2:
Input: num = "2300019"
Output: "000"
Explanation: "000" is the only good integer.

Example 3:
Input: num = "42352338"
Output: ""
Explanation: No substring of length 3 consists of only one unique digit.
Therefore, there are no good integers.

----------------------------------------------------------------
Approach:
1. We iterate through the string from index 0 to n-3.
2. For each index i, check if num[i], num[i+1], and num[i+2] are equal.
3. If they are equal, form a string of length 3 using string(3, num[i]).
4. Keep track of the lexicographically largest such string using `max()`.
5. After the loop, return the result string ("" if none found).

Time Complexity: O(n) — Single pass over the string.
Space Complexity: O(1) — Constant extra space.
----------------------------------------------------------------
*/



class Solution {
public:
    string largestGoodInteger(string num) {
        int n = num.length();
        string result = "";

        for (int i = 0; i < n - 2; i++) {
            if (num[i] == num[i+1] && num[i+1] == num[i+2]) {
                result = max(result, string(3, num[i]));
            }
        }
        return result;
    }
};

int main() {
    Solution sol;

    // Test case 1
    string num1 = "6777133339";
    cout << "Input: " << num1 << "\nOutput: " << sol.largestGoodInteger(num1) << "\n\n";

    // Test case 2
    string num2 = "2300019";
    cout << "Input: " << num2 << "\nOutput: " << sol.largestGoodInteger(num2) << "\n\n";

    // Test case 3
    string num3 = "42352338";
    cout << "Input: " << num3 << "\nOutput: " << sol.largestGoodInteger(num3) << "\n\n";

    // Test case 4 (edge case)
    string num4 = "222";
    cout << "Input: " << num4 << "\nOutput: " << sol.largestGoodInteger(num4) << "\n";

    return 0;
}


// Output =>

// Input: 6777133339
// Output: 777

// Input: 2300019
// Output: 000

// Input: 42352338
// Output: 

// Input: 222
// Output: 222