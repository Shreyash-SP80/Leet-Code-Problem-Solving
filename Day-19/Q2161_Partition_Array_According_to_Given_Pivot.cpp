#include <iostream>
#include <vector>
using namespace std;

/*
2161. Partition Array According to Given Pivot
----------------------------------------------
You are given a 0-indexed integer array nums and an integer pivot. 
Rearrange nums such that the following conditions are satisfied:

1. Every element less than pivot appears before every element greater than pivot.
2. Every element equal to pivot appears in between the elements less than and greater than pivot.
3. The relative order of the elements less than pivot and the elements greater than pivot is maintained.

Return nums after the rearrangement.

Example 1:
Input: nums = [9,12,5,10,14,3,10], pivot = 10
Output: [9,5,3,10,10,12,14]

Example 2:
Input: nums = [-3,4,3,2], pivot = 2
Output: [-3,2,4,3]
*/

/*
# Intuition
We need to partition the array into three groups:
- Elements less than pivot
- Elements equal to pivot
- Elements greater than pivot  
while maintaining the relative order of elements in each group.  
This is similar to the "Dutch National Flag" problem, but stability (order preservation) is required, so we cannot just swap in place.  
The simplest way is to collect elements in three passes and then merge.

# Approach
1. Create an empty result array of the same size.
2. Traverse nums three times:
   - First, add all elements less than pivot.
   - Second, add all elements equal to pivot.
   - Third, add all elements greater than pivot.
3. This ensures stability because we traverse left to right without disturbing original ordering.
4. Return the result.

# Complexity
- Time Complexity: O(n) (three linear passes over nums).
- Space Complexity: O(n) (result array to store rearranged elements).
*/


class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<int> result(n);
        int j = 0;

        // Add elements less than pivot
        for (int i = 0; i < n; i++) {
            if (nums[i] < pivot) {
                result[j++] = nums[i];
            }
        }

        // Add elements equal to pivot
        for (int i = 0; i < n; i++) {
            if (nums[i] == pivot) {
                result[j++] = nums[i];
            }
        }

        // Add elements greater than pivot
        for (int i = 0; i < n; i++) {
            if (nums[i] > pivot) {
                result[j++] = nums[i];
            }
        }

        return result;

        // OR
        // vector<int> left, equal, right;

        // for (int num : nums) {
        //     if (num < pivot) left.push_back(num);
        //     else if (num == pivot) equal.push_back(num);
        //     else right.push_back(num);
        // }

        // // merge results
        // left.insert(left.end(), equal.begin(), equal.end());
        // left.insert(left.end(), right.begin(), right.end());
        // return left;
    }
};

// Driver code for local testing
int main() {
    Solution sol;
    vector<int> nums = {9,12,5,10,14,3,10};
    int pivot = 10;

    vector<int> result = sol.pivotArray(nums, pivot);

    cout << "Rearranged array: ";
    for (int x : result) cout << x << " ";
    cout << endl;

    return 0;
}
