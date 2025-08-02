#include <iostream>
#include <vector>
using namespace std;

/*
====================================================================
🧾 Problem: 3151. Special Array I  
🔗 Source: https://leetcode.com/problems/special-array-i/  
💬 Difficulty: Easy  
====================================================================

📜 Description:
An array is considered **special** if the **parity** of every pair of adjacent elements is different.
In other words, one element in each adjacent pair must be **even**, and the other must be **odd**.

You are given an array of integers `nums`.  
Return `true` if `nums` is a special array, otherwise return `false`.

====================================================================

📌 Constraints:
- 1 <= nums.length <= 100
- 1 <= nums[i] <= 1000

====================================================================

🔍 Example 1:
Input: nums = [1]
Output: true
Explanation:
There is only one element. So the answer is true.

🔍 Example 2:
Input: nums = [2, 1, 4]
Output: true
Explanation:
There are two pairs: (2,1) and (1,4). In both, one is even and the other is odd.

🔍 Example 3:
Input: nums = [4, 3, 1, 6]
Output: false
Explanation:
nums[1] and nums[2] are both odd (3 and 1), so the array is not special.

====================================================================

💡 Approach:
To check whether the array is special, iterate through the array and:
- For every adjacent pair (nums[i], nums[i+1]), check if they have **different parity**.
- If both are odd or both are even → return false immediately.
- If all adjacent pairs pass this check → return true.

✅ A number `x` is:
   - Even if `x % 2 == 0`
   - Odd if `x % 2 == 1`

✅ We compare: `nums[i] % 2 == nums[i+1] % 2`  
   - If true → same parity → not special.

====================================================================

🧠 Time Complexity: O(n)
🧠 Space Complexity: O(1)

====================================================================
*/



class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        int n = nums.size();
        
        // Loop through adjacent pairs
        for (int i = 0; i < n - 1; i++) {
            // Check if both numbers are even or both are odd
            // If yes, they have same parity → not special
            if (nums[i] % 2 == nums[i + 1] % 2) {
                return false;
            }
        }

        // All adjacent pairs have different parity → special
        return true;
    }
};

// Example usage
int main() {
    Solution sol;
    vector<int> nums1 = {2, 1, 4};
    vector<int> nums2 = {4, 3, 1, 6};

    cout << boolalpha << sol.isArraySpecial(nums1) << endl; // true
    cout << boolalpha << sol.isArraySpecial(nums2) << endl; // false

    return 0;
}
