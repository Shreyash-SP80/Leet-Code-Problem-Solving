#include <iostream>
#include <vector>
using namespace std;


/*
❖ LeetCode Problem: 1929. Concatenation of Array
-----------------------------------------------------
🔹 Question:
Given an integer array `nums` of length `n`, you want to create an array `ans` of length `2n` where:
  ➤ ans[i] = nums[i]
  ➤ ans[i + n] = nums[i] 
for 0 <= i < n (0-indexed).

Specifically, `ans` is the concatenation of two `nums` arrays.

🔹 Example 1:
Input: nums = [1, 2, 1]
Output: [1, 2, 1, 1, 2, 1]

🔹 Example 2:
Input: nums = [1, 3, 2, 1]
Output: [1, 3, 2, 1, 1, 3, 2, 1]

-----------------------------------------------------
❖ Approach:
-----------------------------------------------------
1. First, determine the size `n` of the original array.
2. Create a new vector `ans` of size `2 * n`.
3. Loop from `0` to `n - 1`:
   ➤ For each index `i`, assign:
       - ans[i] = nums[i]
       - ans[i + n] = nums[i]
4. Return the `ans` vector.
This avoids using high-level methods like `insert()` and gives a clear logic.

------------------------------------------------------------
🔗 Source: https://leetcode.com/problems/concatenation-of-array/
------------------------------------------------------------
*/


class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size();              // Step 1: Get original array size
        vector<int> ans(2 * n);           // Step 2: Create array of size 2n

        for (int i = 0; i < n; i++) {     // Step 3: Copy elements twice
            ans[i] = nums[i];            // First half
            ans[i + n] = nums[i];        // Second half
        }

        return ans;                       // Step 4: Return result
    }
};

// Example usage:
int main() {
    Solution sol;
    vector<int> nums = {1, 2, 1};
    vector<int> result = sol.getConcatenation(nums);

    // Print result
    for (int num : result) {
        cout << num << " ";
    }
    return 0;
}
