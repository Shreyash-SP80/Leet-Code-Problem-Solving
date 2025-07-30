#include<iostream>
#include<vector>
using namespace std;


/*
===========================================
LeetCode 3379: Transformed Array
Difficulty: Easy
===========================================

📝 Problem Statement:

You are given an integer array `nums` that represents a circular array. Your task is to create a new array `result` of the same size, following these rules:

For each index `i` (where `0 <= i < nums.length`), perform the following independent actions:

1. If `nums[i] > 0`: 
   - Start at index `i` and move `nums[i]` steps to the right in the circular array.
   - Set `result[i]` to the value at the index where you land.

2. If `nums[i] < 0`: 
   - Start at index `i` and move `abs(nums[i])` steps to the left in the circular array.
   - Set `result[i]` to the value at the index where you land.

3. If `nums[i] == 0`: 
   - Set `result[i]` to `nums[i]`.

Note:
- Since `nums` is a circular array, moving past the last element wraps around to the beginning, and moving before the first element wraps around to the end.

---------------------------------------------------

🔍 Examples:

Example 1:
Input: nums = [3, -2, 1, 1]
Output: [1, 1, 1, 3]

Explanation:
- nums[0] = 3 → move 3 steps right → index 3 → nums[3] = 1
- nums[1] = -2 → move 2 steps left → index 3 → nums[3] = 1
- nums[2] = 1 → move 1 step right → index 3 → nums[3] = 1
- nums[3] = 1 → move 1 step right → index 0 → nums[0] = 3

Example 2:
Input: nums = [-1, 4, -1]
Output: [-1, -1, 4]

Explanation:
- nums[0] = -1 → move 1 step left → index 2 → nums[2] = -1
- nums[1] = 4 → move 4 steps right → index 2 → nums[2] = -1
- nums[2] = -1 → move 1 step left → index 1 → nums[1] = 4

---------------------------------------------------

💡 Constraints:
- 1 <= nums.length <= 100
- -100 <= nums[i] <= 100

*/


/*
Approach:

We are given a circular array `nums`. For each index `i`, we perform:
- If nums[i] > 0: move nums[i] steps to the right in circular fashion.
- If nums[i] < 0: move abs(nums[i]) steps to the left in circular fashion.
- If nums[i] == 0: set result[i] = 0.

To calculate the circular index:
- Use (i + nums[i]) % n.
- In C++, the modulo of a negative number is also negative, so if result < 0,
  we add n to wrap it back into the correct circular index.

Finally, we create a `result` array of the same size, and for each index `i`,
we store the value of the index we landed on after circular movement.
*/

class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {

        int n = nums.size();
        vector<int> result(n);  // Result array of the same size

        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                // Case 1: If value is 0, just copy it
                result[i] = 0;
            } else {
                // Case 2: Calculate new index based on circular steps
                int index = (i + nums[i]) % n;

                // In C++, negative modulo gives negative results. Fix it by adding n.
                if (index < 0) {
                    index += n;
                }

                // Set the result[i] as the value at the new circular index
                result[i] = nums[index];
            }
        }

        return result;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {3, -2, 1, 1};
    vector<int> result = sol.constructTransformedArray(nums);

    for (int val : result) {
        cout << val << " ";
    }
    // Output: 1 1 1 3
}
