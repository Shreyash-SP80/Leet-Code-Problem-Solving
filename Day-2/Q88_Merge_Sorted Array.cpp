#include <iostream>
#include <vector>
using namespace std;


/*
===========================================================
📝 Problem: 88. Merge Sorted Array
🔗 Link: https://leetcode.com/problems/merge-sorted-array/
💡 Difficulty: Easy

📄 Description:
You are given two integer arrays `nums1` and `nums2`, both sorted in non-decreasing order, and two integers `m` and `n`, representing the number of elements in `nums1` and `nums2`, respectively.

Merge `nums2` into `nums1` as one sorted array in non-decreasing order.

Note:
- The final sorted array should not be returned by the function.
- It must be stored inside the array `nums1`.
- `nums1` has a length of `m + n`, where the first `m` elements denote the elements that should be merged, and the last `n` elements are set to 0 and should be ignored.
- `nums2` has a length of `n`.

🔍 Examples:

Example 1:
Input:  nums1 = [1,2,3,0,0,0], m = 3
        nums2 = [2,5,6], n = 3
Output: [1,2,2,3,5,6]

Example 2:
Input:  nums1 = [1], m = 1
        nums2 = [], n = 0
Output: [1]

Example 3:
Input:  nums1 = [0], m = 0
        nums2 = [1], n = 1
Output: [1]
*/


/**
 * Approach:
 * =========
 * - This is a two-pointer approach starting from the end of both arrays.
 * - We use three pointers:
 *     1. i: points to the last valid element in nums1 (i = m - 1)
 *     2. j: points to the last element in nums2 (j = n - 1)
 *     3. k: points to the end of nums1 (k = m + n - 1)
 * 
 * - We compare nums1[i] and nums2[j] from the end and place the larger
 *   one at nums1[k], then decrement the respective pointers.
 * 
 * - This continues until either i < 0 or j < 0.
 * 
 * - If any elements are left in nums2, we copy them to the front of nums1.
 * - No need to copy remaining nums1 elements as they are already in place.
 */


/**
 * Function to merge two sorted arrays nums1 and nums2.
 * @param nums1: First vector with m real elements followed by n zeros
 * @param m: Number of real elements in nums1
 * @param nums2: Second vector with n elements
 * @param n: Number of elements in nums2
 */
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    // Pointers starting from the end of real elements in nums1 and nums2
    int i = m - 1;        // pointer for nums1
    int j = n - 1;        // pointer for nums2
    int k = m + n - 1;    // pointer for final position in nums1

    // Merge in reverse to avoid overwriting data in nums1
    while (i >= 0 && j >= 0) {
        if (nums1[i] > nums2[j])
            nums1[k--] = nums1[i--];
        else
            nums1[k--] = nums2[j--];
    }

    // If any elements left in nums2, copy them
    while (j >= 0) {
        nums1[k--] = nums2[j--];
    }
}

int main() {
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    vector<int> nums2 = {2, 5, 6};
    int m = 3, n = 3;

    merge(nums1, m, nums2, n);

    cout << "Merged array: ";
    for (int num : nums1)
        cout << num << " ";
    return 0;
}
