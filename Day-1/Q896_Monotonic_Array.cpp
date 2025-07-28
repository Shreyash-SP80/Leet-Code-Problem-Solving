#include <iostream>
#include <vector>
using namespace std;



/*
Leetcode 896. Monotonic Array
-----------------------------

📝 Problem Statement:
An array is monotonic if it is either monotone increasing or monotone decreasing.

- An array `nums` is monotone increasing if for all `i <= j`, `nums[i] <= nums[j]`.
- An array `nums` is monotone decreasing if for all `i <= j`, `nums[i] >= nums[j]`.

🔧 Task:
Given an integer array `nums`, return `true` if the array is monotonic, or `false` otherwise.

🧪 Examples:

Example 1:
Input:  nums = [1, 2, 2, 3]
Output: true

Example 2:
Input:  nums = [6, 5, 4, 4]
Output: true

Example 3:
Input:  nums = [1, 3, 2]
Output: false
*/



/*
Approach:
---------
1. Initialize two flags: `increasing` and `decreasing`, both set to true.

2. Loop through the array and compare adjacent elements:
   - If any pair breaks the increasing condition (nums[i] > nums[i+1]), set increasing = false.
   - If any pair breaks the decreasing condition (nums[i] < nums[i+1]), set decreasing = false.

3. If either `increasing` or `decreasing` remains true, then the array is monotonic.

4. Return true if array is monotonic, otherwise return false.
*/


class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        bool decreasing = true;
        bool increasing = true;

        // Loop through the array from index 0 to n-2
        for (int i = 0; i < nums.size() - 1; i++) {
            // If current element is greater than next, not increasing
            if (!(nums[i] <= nums[i + 1])) {
                increasing = false;
            }
            // If current element is less than next, not decreasing
            else if (!(nums[i] >= nums[i + 1])) {
                decreasing = false;
            }
        }

        // Array is monotonic if it is either all increasing or all decreasing
        return decreasing || increasing;
    }
};

int main() {
    Solution sol;

    // Test cases
    vector<int> nums1 = {1, 2, 2, 3};
    vector<int> nums2 = {6, 5, 4, 4};
    vector<int> nums3 = {1, 3, 2};

    cout << "Test 1: " << (sol.isMonotonic(nums1) ? "True" : "False") << endl; // True
    cout << "Test 2: " << (sol.isMonotonic(nums2) ? "True" : "False") << endl; // True
    cout << "Test 3: " << (sol.isMonotonic(nums3) ? "True" : "False") << endl; // False

    return 0;
}
