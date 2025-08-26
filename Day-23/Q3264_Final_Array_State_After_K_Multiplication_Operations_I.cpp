#include <iostream>
#include <vector>
using namespace std;


/*
3264. Final Array State After K Multiplication Operations I
-------------------------------------------------------------
You are given an integer array `nums`, an integer `k`, and an integer `multiplier`.

Task:
Perform `k` operations on `nums`. In each operation:
1. Find the minimum value x in `nums` (first occurrence if multiple).
2. Replace x with x * multiplier.

Return the final state of `nums` after all operations.

Example 1:
Input: nums = [2,1,3,5,6], k = 5, multiplier = 2
Output: [8,4,6,5,6]

Example 2:
Input: nums = [1,2], k = 3, multiplier = 4
Output: [16,8]

--------------------------------------
# Intuition
- At each step, multiply the smallest element by `multiplier`.
- Keep repeating `k` times.
- Always select the **first occurrence** of the minimum.

# Approach
1. Loop `k` times:
   - Find index of first minimum in `nums`.
   - Multiply that element by `multiplier`.
2. Return `nums`.

# Complexity
- Time: O(k * n), n = size of nums (each step searches for min in array)
- Space: O(1) extra
*/


class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        int n = nums.size();

        for (int op = 0; op < k; op++) {
            int minIndex = 0;
            for (int i = 1; i < n; i++) {
                if (nums[i] < nums[minIndex])
                    minIndex = i;
            }
            nums[minIndex] *= multiplier;
        }
        return nums;
    }
};

// Driver code
int main() {
    Solution sol;

    vector<int> nums1 = {2,1,3,5,6};
    int k1 = 5, multiplier1 = 2;
    auto res1 = sol.getFinalState(nums1, k1, multiplier1);
    cout << "Output 1: ";
    for (int x : res1) cout << x << " ";
    cout << endl;

    vector<int> nums2 = {1,2};
    int k2 = 3, multiplier2 = 4;
    auto res2 = sol.getFinalState(nums2, k2, multiplier2);
    cout << "Output 2: ";
    for (int x : res2) cout << x << " ";
    cout << endl;

    return 0;
}
