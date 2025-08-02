
#include <iostream>
#include <vector>
#include <algorithm> // For reverse
using namespace std;

/*
========================================================================================
✅ QUESTION: LeetCode 189 – Rotate Array
🔗 Link: https://leetcode.com/problems/rotate-array/

📄 Description:
Given an integer array `nums`, rotate the array to the right by `k` steps, where `k` is 
non-negative. The array should be modified in-place or with minimal extra space.

📌 Examples:
➤ Input: nums = [1,2,3,4,5,6,7], k = 3
   Output: [5,6,7,1,2,3,4]

➤ Input: nums = [-1,-100,3,99], k = 2
   Output: [3,99,-1,-100]

📋 Constraints:
   • 1 <= nums.length <= 10^5
   • -2^31 <= nums[i] <= 2^31 - 1
   • 0 <= k <= 10^5
========================================================================================

🔍 APPROACHES:

✅ Approach 1: Brute Force (Time Limit Exceeded)
   - Rotate array one step to the right, k times.
   - Time Complexity: O(n * k)
   - Space Complexity: O(1)
   - Not efficient for large k.

✅ Approach 2: Reverse In-Place (Optimal)
   - Reverse the entire array.
   - Reverse the first k elements.
   - Reverse the remaining n-k elements.
   - Time Complexity: O(n)
   - Space Complexity: O(1)

✅ Approach 3: Extra Array (Simple)
   - Create a temporary array.
   - For each index i, place the element at position (i + k) % n.
   - Copy back to the original array.
   - Time Complexity: O(n)
   - Space Complexity: O(n)

========================================================================================
🔗 REFERENCES:
    • LeetCode Problem: https://leetcode.com/problems/rotate-array
    • C++ reverse(): https://en.cppreference.com/w/cpp/algorithm/reverse
    • Big-O Reference: https://www.bigocheatsheet.com/
========================================================================================
*/

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        /*/

        ✅ Code 1: Brute Force Approach (Time Limit Exceeded for Large Inputs)
        🔄 Shift elements to the right one step at a time, for k steps.
        */

        // int val;
        // while (k > 0) {
        //     val = nums[nums.size() - 1];
        //     for (int i = nums.size() - 1; i > 0; i--) {
        //         nums[i] = nums[i - 1];
        //     }
        //     nums[0] = val;
        //     k--;
        // }

        /*
        ----------------------------------------------------------------------------------------
        ✅ Code 2: In-Place Reversal Method (Efficient)
        🔄 Steps:
           1. Reverse the entire array
           2. Reverse the first k elements
           3. Reverse the remaining n-k elements

        Example:
            nums = [1,2,3,4,5,6,7], k = 3
            Step 1: reverse(nums)       → [7,6,5,4,3,2,1]
            Step 2: reverse(0, 3)       → [5,6,7,4,3,2,1]
            Step 3: reverse(3, end)     → [5,6,7,1,2,3,4]

        Time Complexity: O(n)
        Space Complexity: O(1)
        */

        // k %= nums.size();
        // reverse(nums.begin(), nums.end());
        // reverse(nums.begin(), nums.begin() + k);
        // reverse(nums.begin() + k, nums.end());

        /*
        ----------------------------------------------------------------------------------------
        ✅ Code 3: Using Extra Array (Simple and Clean)
        🔄 Steps:
           - Create a temporary array of same size
           - For each index i, place it at position (i + k) % n
           - Copy the temp array back to nums

        Example:
            nums = [1,2,3,4], k = 2
            temp[(0+2)%4] = temp[2] = 1
            temp[(1+2)%4] = temp[3] = 2
            temp[(2+2)%4] = temp[0] = 3
            temp[(3+2)%4] = temp[1] = 4
            → temp = [3,4,1,2]
            → nums = [3,4,1,2]

        Time Complexity: O(n)
        Space Complexity: O(n)
        ----------------------------------------------------------------------------------------
        */

        k = k % nums.size();  // Handle k > size
        vector<int> temp(nums.size());

        for (int i = 0; i < nums.size(); i++) {
            temp[(i + k) % nums.size()] = nums[i];
        }

        nums = temp;
    }
};

// Example usage
int main() {
    Solution sol;

    // Example 1
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;

    sol.rotate(nums, k);

    // Output: 5 6 7 1 2 3 4
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
