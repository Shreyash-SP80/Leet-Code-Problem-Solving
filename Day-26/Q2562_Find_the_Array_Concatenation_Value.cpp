#include <iostream>
#include <vector>
#include <string>
using namespace std;


/*
2562. Find the Array Concatenation Value
----------------------------------------
We are given an integer array `nums`.

We repeatedly do the following until `nums` becomes empty:
1. If `nums` has more than 1 element:
   - Take the first element and the last element.
   - Concatenate them (e.g., 15 and 49 → 1549).
   - Add this concatenated number to the running total.
   - Remove both elements.
2. If only one element remains, add it directly to the total.

Return the total concatenation value.
*/

/*
# Intuition
- We simulate the process using two pointers (`i` at start, `j` at end).
- At each step:
  - If `i == j`, only one element remains → add directly.
  - Else, concatenate `nums[i]` and `nums[j]`, add to result.
- Move pointers inward until processed.

# Approach
1. Initialize `result = 0`, `i = 0`, `j = n-1`.
2. While `i <= j`:
   - If `i == j`, add `nums[i]`.
   - Otherwise, concatenate `nums[i]` and `nums[j]` using `to_string` and convert back to integer.
   - Update result.
   - Move `i++`, `j--`.
3. Return result.

# Complexity
- Time: O(n * k)  
  (where `k` = max number of digits in a number, due to string conversion).
- Space: O(1) extra (ignoring temporary strings).
*/


class Solution {
public:
    long long findTheArrayConcVal(vector<int>& nums) {
        long long result = 0;
        int i = 0, j = nums.size() - 1;

        while (i <= j) {
            if (i == j) {
                result += nums[i];
            } else {
                string concat = to_string(nums[i]) + to_string(nums[j]);
                result += stoll(concat);
            }
            i++;
            j--;
        }
        return result;
    }
};

// Driver
int main() {
    Solution sol;

    vector<int> nums1 = {7,52,2,4};
    cout << sol.findTheArrayConcVal(nums1) << endl; // 596

    vector<int> nums2 = {5,14,13,8,12};
    cout << sol.findTheArrayConcVal(nums2) << endl; // 673

    return 0;
}
