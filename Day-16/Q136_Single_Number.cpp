#include <iostream>
#include <vector>
using namespace std;


/*
136. Single Number

Given a non-empty array of integers nums, every element appears twice except for one. 
Find that single one.

You must implement a solution with a linear runtime complexity and use only constant extra space.

Example 1:
Input: nums = [2,2,1]
Output: 1

Example 2:
Input: nums = [4,1,2,1,2]
Output: 4

Example 3:
Input: nums = [1]
Output: 1

------------------------------------------------------------
Approach:
We use the bitwise XOR operator to solve the problem in O(n) time and O(1) space.

Key XOR properties:
1. a ^ a = 0  (any number XOR itself becomes 0)
2. a ^ 0 = a  (any number XOR with 0 stays the same)
3. XOR is commutative and associative.

So if we XOR all numbers in the array, the duplicate numbers will cancel each other out, 
and only the unique number will remain.

Time Complexity: O(n) — We iterate over the array once.
Space Complexity: O(1) — We only use a single integer variable for the result.
------------------------------------------------------------
*/


class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for (int num : nums) {
            result ^= num; // XOR cancels duplicates
        }
        return result;
    }
};

int main() {
    Solution sol;

    // Test case 1
    vector<int> nums1 = {2, 2, 1};
    cout << "Input: [2, 2, 1]\nOutput: " << sol.singleNumber(nums1) << "\n\n";

    // Test case 2
    vector<int> nums2 = {4, 1, 2, 1, 2};
    cout << "Input: [4, 1, 2, 1, 2]\nOutput: " << sol.singleNumber(nums2) << "\n\n";

    // Test case 3
    vector<int> nums3 = {1};
    cout << "Input: [1]\nOutput: " << sol.singleNumber(nums3) << "\n";

    return 0;
}


// Output =>

// Input: [2, 2, 1]
// Output: 1

// Input: [4, 1, 2, 1, 2]
// Output: 4

// Input: [1]
// Output: 1
