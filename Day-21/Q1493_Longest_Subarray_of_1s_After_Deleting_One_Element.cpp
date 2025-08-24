#include <iostream>
#include <vector>
using namespace std;

/*
1493. Longest Subarray of 1's After Deleting One Element
--------------------------------------------------------
Given a binary array nums, you should delete one element from it.

Return the size of the longest non-empty subarray containing only 1's in the resulting array. 
Return 0 if there is no such subarray.

Example 1:
Input: nums = [1,1,0,1]
Output: 3
Explanation: After deleting the number at index 2, we get [1,1,1].

Example 2:
Input: nums = [0,1,1,1,0,1,1,0,1]
Output: 5
Explanation: After deleting the number at index 4, we get [1,1,1,1,1].

Example 3:
Input: nums = [1,1,1]
Output: 2
Explanation: We must delete one element, so the longest subarray is [1,1].
*/

/*
# Intuition
We want the longest contiguous block of 1’s after deleting exactly one element.  
This means our subarray can contain at most **one zero** inside it.

# Approach (Sliding Window)
- Maintain a window `[left, right]` with at most **one zero** inside it.
- Use a counter `zero_cnt` to track how many zeros are in the current window.
- Expand `right` as we iterate.
- If `zero_cnt > 1`, shrink the window by moving `left` until only one zero remains.
- Track the maximum length as `right - left` (not `+1` because one deletion is mandatory).

# Complexity
- Time Complexity: O(n), since each element is processed at most twice (entering and leaving the window).
- Space Complexity: O(1), only a few variables are used.
*/


class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int left = 0, zero_cnt = 0, max_len = 0;

        for (int right = 0; right < nums.size(); right++) {
            if (nums[right] == 0) zero_cnt++;

            // shrink window if more than one zero
            while (zero_cnt > 1) {
                if (nums[left] == 0) zero_cnt--;
                left++;
            }
            // length is right-left because one deletion is required
            max_len = max(max_len, right - left);
        }
        return max_len;
    }
};

// Driver code for local testing
int main() {
    Solution sol;

    vector<int> nums1 = {1,1,0,1};
    cout << "Output 1: " << sol.longestSubarray(nums1) << endl; // Expected 3

    vector<int> nums2 = {0,1,1,1,0,1,1,0,1};
    cout << "Output 2: " << sol.longestSubarray(nums2) << endl; // Expected 5

    vector<int> nums3 = {1,1,1};
    cout << "Output 3: " << sol.longestSubarray(nums3) << endl; // Expected 2

    vector<int> nums4 = {0,0,0};
    cout << "Output 4: " << sol.longestSubarray(nums4) << endl; // Expected 0

    return 0;
}
