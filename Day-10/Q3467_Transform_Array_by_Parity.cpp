#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
LeetCode 3467. Transform Array by Parity
https://leetcode.com/problems/transform-array-by-parity/

🟢 Difficulty: Easy

You are given an integer array nums. Transform nums by performing the following operations in the exact order specified:

1. Replace each even number with 0.
2. Replace each odd number with 1.
3. Sort the modified array in non-decreasing order.

Return the resulting array after performing these operations.

Example 1:
Input: nums = [4,3,2,1]
Output: [0,0,1,1]

Example 2:
Input: nums = [1,5,1,4,2]
Output: [0,0,1,1,1]

Approach:
1. Traverse the input array:
    - If the number is even (num % 2 == 0), convert it to 0.
    - If the number is odd, convert it to 1.
2. Store the transformed values in a new array.
3. Sort the transformed array.
4. Return the sorted result.

Time Complexity:
- O(n log n) due to sorting

Space Complexity:
- O(n) for the result array

*/

class Solution {
public:
    vector<int> transformArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, 0);

        // Step 1: Replace even with 0, odd with 1
        for (int i = 0; i < n; i++) {
            result[i] = (nums[i] % 2 != 0) ? 1 : 0;
        }

        // Step 2: Sort the result array
        sort(result.begin(), result.end());

        return result;
    }
};

int main() {
    Solution sol;

    // Test Case 1
    vector<int> nums1 = {4, 3, 2, 1};
    vector<int> res1 = sol.transformArray(nums1);
    cout << "Output for [4,3,2,1]: ";
    for (int num : res1) cout << num << " ";
    cout << endl;

    // Test Case 2
    vector<int> nums2 = {1, 5, 1, 4, 2};
    vector<int> res2 = sol.transformArray(nums2);
    cout << "Output for [1,5,1,4,2]: ";
    for (int num : res2) cout << num << " ";
    cout << endl;

    return 0;
}

// Output =>
// Output for [4,3,2,1]: 0 0 1 1 
// Output for [1,5,1,4,2]: 0 0 1 1 1 
