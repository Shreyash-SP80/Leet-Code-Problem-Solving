#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


/*
2089. Find Target Indices After Sorting Array
----------------------------------------------
You are given a 0-indexed integer array nums and a target element target.

A target index is an index i such that nums[i] == target.

Return a list of the target indices of nums after sorting nums in non-decreasing order. 
If there are no target indices, return an empty list. 
The returned list must be sorted in increasing order.

Example 1:
Input: nums = [1,2,5,2,3], target = 2
Output: [1,2]
Explanation: After sorting, nums = [1,2,2,3,5].
The indices with value 2 are 1 and 2.

Example 2:
Input: nums = [1,2,5,2,3], target = 3
Output: [3]

Example 3:
Input: nums = [1,2,5,2,3], target = 5
Output: [4]
*/

/*
# Intuition
The problem requires us to sort the array first, then return all indices where nums[i] == target.

# Approach 1 (Sorting + Scanning)
1. Sort the array.
2. Traverse through it and collect all indices where nums[i] == target.
3. Since we traverse in sorted order, indices are naturally sorted.

# Approach 2 (Without Sorting - Optimized O(n))
- Instead of sorting, just count:
  - `less` = number of elements < target
  - `equal` = number of elements == target
- Then target indices will simply be [less, less+1, ..., less+equal-1].
This avoids sorting and runs in O(n).

# Complexity
- Sorting Approach: O(n log n) time, O(1) extra space.
- Counting Approach: O(n) time, O(1) space.
*/


class Solution {
public:
    // Approach 1: Sort + Collect
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<int> result;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == target) {
                result.push_back(i);
            }
        }
        return result;
    }

    // Approach 2: Optimized O(n) counting
    vector<int> targetIndicesOptimized(vector<int>& nums, int target) {
        int less = 0, equal = 0;
        for (int num : nums) {
            if (num < target) less++;
            else if (num == target) equal++;
        }
        vector<int> result;
        for (int i = 0; i < equal; i++) {
            result.push_back(less + i);
        }
        return result;
    }
};

// Driver code
int main() {
    Solution sol;

    vector<int> nums1 = {1,2,5,2,3};
    int target1 = 2;
    auto res1 = sol.targetIndices(nums1, target1);
    cout << "Output 1 (sorted): ";
    for (int x : res1) cout << x << " ";
    cout << endl;

    vector<int> nums2 = {1,2,5,2,3};
    int target2 = 3;
    auto res2 = sol.targetIndicesOptimized(nums2, target2);
    cout << "Output 2 (optimized): ";
    for (int x : res2) cout << x << " ";
    cout << endl;

    vector<int> nums3 = {1,2,5,2,3};
    int target3 = 5;
    auto res3 = sol.targetIndices(nums3, target3);
    cout << "Output 3 (sorted): ";
    for (int x : res3) cout << x << " ";
    cout << endl;

    return 0;
}
