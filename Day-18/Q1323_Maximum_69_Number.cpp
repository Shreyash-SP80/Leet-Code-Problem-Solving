#include <iostream>
#include <string>
using namespace std;

/*
1323. Maximum 69 Number
========================

You are given a positive integer `num` consisting only of digits 6 and 9.

Return the maximum number you can get by changing at most one digit 
(6 becomes 9, and 9 becomes 6).

------------------------------------------------
Example 1:
Input: num = 9669
Output: 9969
Explanation:
- Changing the first digit results in 6669.
- Changing the second digit results in 9969.
- Changing the third digit results in 9699.
- Changing the fourth digit results in 9666.
The maximum number is 9969.

Example 2:
Input: num = 9996
Output: 9999
Explanation: Changing the last digit 6 to 9 results in the maximum number.

Example 3:
Input: num = 9999
Output: 9999
Explanation: It is better not to apply any change.
------------------------------------------------

# Intuition
Since the number only consists of digits `6` and `9`, the optimal strategy 
to maximize it is to flip the **first occurrence of `6`** into `9`.  
This works because digits on the left have a higher place value.

# Approach
1. Convert the number into a string using `to_string(num)`.
2. Traverse each character from left to right.
3. If you encounter the first `'6'`, change it to `'9'` and stop.
4. Convert the string back to an integer using `stoi`.
5. Return the result.

# Complexity Analysis
- Time Complexity: O(n), where `n` is the number of digits in `num`.
- Space Complexity: O(n), because we store the string representation of the number.

------------------------------------------------
*/


class Solution {
public:
    int maximum69Number (int num) {
        string s = to_string(num);    // Convert int → string
        for (char &c : s) {           // Traverse each digit
            if (c == '6') {           // Flip first '6' → '9'
                c = '9';
                break;                // Only one change allowed
            }
        }
        return stoi(s);               // Convert string → int

         // OR

        // int result = num;
        // string data = to_string(num);
        
        // for (int i = 0; i < data.size(); i++) {
        //     string check = data;
        //     if (data[i] == '6') {
        //         check[i] = '9';
        //     }
        //     result = max(result, stoi(check));
        // }
        // return result;
    }
};

// Driver Code
int main() {
    Solution sol;
    
    // Test cases
    cout << sol.maximum69Number(9669) << endl; // Expected: 9969
    cout << sol.maximum69Number(9996) << endl; // Expected: 9999
    cout << sol.maximum69Number(9999) << endl; // Expected: 9999
    
    return 0;
}
