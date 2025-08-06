#include <iostream>
#include <vector>
using namespace std;


/*
LeetCode 922. Sort Array By Parity II
https://leetcode.com/problems/sort-array-by-parity-ii/

🟢 Difficulty: Easy

Given an integer array nums of even length, where exactly half of the integers are even and half are odd:

- Place each even element at an even index (0‑based).
- Place each odd element at an odd index.

Return any array that satisfies these conditions.

Example 1:
Input: nums = [4,2,5,7]
Output: [4,5,2,7]
(Other valid answers include [4,7,2,5], [2,5,4,7], etc.)

Example 2:
Input: nums = [2,3]
Output: [2,3]

Approach:
1. Create an output array of same size, initialized arbitrarily.
2. Use two pointers:
    - evenIndex starting at 0 (for even positions),
    - oddIndex starting at 1 (for odd positions).
3. Traverse the original nums:
    - If the number is even, place it at output[evenIndex], then evenIndex += 2.
    - If the number is odd, place it at output[oddIndex], then oddIndex += 2.
4. Continue until all elements are placed.
5. Return the result.

Time Complexity:
- O(n) since we pass through the array once and assign elements.

Space Complexity:
- O(n) for the new output array.

*/

class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);
        int evenIndex = 0;
        int oddIndex = 1;

        for (int num : nums) {
            if (num % 2 == 0) {
                result[evenIndex] = num;
                evenIndex += 2;
            } else {
                result[oddIndex] = num;
                oddIndex += 2;
            }
        }

        return result;
    }
};

int main() {
    Solution sol;

    // Test Case 1
    vector<int> nums1 = {4, 2, 5, 7};
    vector<int> res1 = sol.sortArrayByParityII(nums1);
    cout << "Output for [4,2,5,7]: ";
    for (int x : res1) cout << x << " ";
    cout << endl;

    // Test Case 2
    vector<int> nums2 = {2, 3};
    vector<int> res2 = sol.sortArrayByParityII(nums2);
    cout << "Output for [2,3]: ";
    for (int x : res2) cout << x << " ";
    cout << endl;

    return 0;
}

// Output =>
// Output for [4,2,5,7]: 4 5 2 7 
// Output for [2,3]: 2 3 
