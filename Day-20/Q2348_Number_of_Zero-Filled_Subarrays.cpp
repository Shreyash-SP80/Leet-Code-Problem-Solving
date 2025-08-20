#include <iostream>
#include <vector>
using namespace std;

/*
2348. Number of Zero-Filled Subarrays
-------------------------------------
Given an integer array nums, return the number of subarrays filled with 0.

A subarray is a contiguous non-empty sequence of elements within an array.

Example 1:
Input: nums = [1,3,0,0,2,0,0,4]
Output: 6
Explanation:
- 4 subarrays of [0]
- 2 subarrays of [0,0]
Total = 6

Example 2:
Input: nums = [0,0,0,2,0,0]
Output: 9
Explanation:
- 5 subarrays of [0]
- 3 subarrays of [0,0]
- 1 subarray of [0,0,0]
Total = 9

Example 3:
Input: nums = [2,10,2019]
Output: 0
Explanation:
No zero-filled subarrays exist.
*/

/*
# Intuition
Every time we encounter a zero, it can extend the existing streak of zeros.  
For example, if we have a streak of length `k`, the number of subarrays ending at this position is `k`.  

# Approach
- Initialize two counters:
  - `strike` → length of current consecutive zeros.
  - `cnt` → total number of zero-filled subarrays.
- Traverse the array:
  - If `num == 0`, increment `strike` and add it to `cnt`.
  - If `num != 0`, reset `strike` to 0.
- Return `cnt`.

This works because each new zero extends all previous zero subarrays and also starts a new one.

# Complexity
- Time Complexity: O(n), since we traverse the array once.
- Space Complexity: O(1), only a few variables are used.
*/



class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long cnt = 0, strike = 0;
        for (int num : nums) {
            if (num == 0) {
                strike++;
                cnt += strike;
            } else {
                strike = 0;
            }
        }
        return cnt;
    }
};

// Driver code for local testing
int main() {
    Solution sol;

    vector<int> nums1 = {1,3,0,0,2,0,0,4};
    cout << "Output 1: " << sol.zeroFilledSubarray(nums1) << endl; // Expected 6

    vector<int> nums2 = {0,0,0,2,0,0};
    cout << "Output 2: " << sol.zeroFilledSubarray(nums2) << endl; // Expected 9

    vector<int> nums3 = {2,10,2019};
    cout << "Output 3: " << sol.zeroFilledSubarray(nums3) << endl; // Expected 0

    return 0;
}
