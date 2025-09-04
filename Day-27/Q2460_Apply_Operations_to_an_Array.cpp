#include <iostream>
#include <vector>
using namespace std;


/*
2460. Apply Operations to an Array
-----------------------------------
We are given an array `nums` and must:
1. For each index `i` (0 <= i < n - 1):
   - If nums[i] == nums[i+1], then:
       nums[i] = 2 * nums[i]
       nums[i+1] = 0
   - Otherwise, skip.
2. After applying all operations sequentially, shift all 0’s to the end.
Return the resulting array.
*/

/*
# Intuition
- We need to process the array sequentially (not all at once).
- When two adjacent numbers are equal:
  - Double the left number.
  - Replace the right one with 0.
- After finishing all operations, the problem reduces to a "move all zeros to the end" task.

# Approach
1. Traverse the array from i = 0 to n-2:
   - If nums[i] == nums[i+1], apply the operation.
2. Create a new result array:
   - Push all non-zero values first.
   - Append enough zeros to match original length.
3. Return the result.

# Complexity
- Time: O(n) → one pass for operations, one pass for shifting zeros.
- Space: O(n) → result array.
*/


class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();
        vector<int> result;

        // Step 1: Apply operations sequentially
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] == nums[i+1]) {
                nums[i] *= 2;
                nums[i+1] = 0;
            }
        }

        // Step 2: Collect non-zero elements
        for (int i = 0; i < n; i++) {
            if (nums[i] != 0) result.push_back(nums[i]);
        }

        // Step 3: Append zeros to maintain size
        while ((int)result.size() < n) {
            result.push_back(0);
        }

        return result;
    }
};

// Driver
int main() {
    Solution sol;

    vector<int> nums1 = {1,2,2,1,1,0};
    vector<int> res1 = sol.applyOperations(nums1);
    for (int x : res1) cout << x << " "; // Output: 1 4 2 0 0 0
    cout << endl;

    vector<int> nums2 = {0,1};
    vector<int> res2 = sol.applyOperations(nums2);
    for (int x : res2) cout << x << " "; // Output: 1 0
    cout << endl;

    return 0;
}
