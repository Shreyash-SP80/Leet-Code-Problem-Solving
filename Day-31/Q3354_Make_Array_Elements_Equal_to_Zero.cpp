#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>
using namespace std;

/*
3354. Make Array Elements Equal to Zero
--------------------------------------------
We are given an integer array nums.

We start by selecting a starting position curr such that nums[curr] == 0,
and choose a direction (left or right). Then we repeatedly do:
    - If curr is out of range → stop.
    - If nums[curr] == 0 → keep moving in the same direction.
    - If nums[curr] > 0:
         * Decrement nums[curr]
         * Reverse direction
         * Take a step

A selection is valid if all elements become 0 by the end.
We must return the number of possible valid selections.
*/

/*
# Intuition
- Instead of simulating the entire process (which is complex),
  notice that the process is equivalent to balancing work
  between left and right sides of each zero position.
- Let totalSum = sum(nums).
- Maintain prefix sum (leftSum).
- At each index `i` where nums[i] == 0:
    * If 2 * leftSum == totalSum → both directions work → +2
    * If |2 * leftSum - totalSum| == 1 → only one direction works → +1
- Otherwise, no valid start from this zero.

# Approach
1. Compute total sum of nums.
2. Traverse nums with a prefix sum leftSum.
3. When encountering zero, check balance condition and update count.
4. Return the total count.

# Complexity
- Time: O(n), single pass.
- Space: O(1) extra.
*/


class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        long long totalSum = accumulate(nums.begin(), nums.end(), 0LL);
        long long leftSum = 0;
        int count = 0;

        for (int num : nums) {
            if (num != 0) {
                leftSum += num;
            } else {
                if (leftSum * 2 == totalSum) {
                    count += 2; // both directions valid
                } else if (abs(leftSum * 2 - totalSum) == 1) {
                    count += 1; // only one direction valid
                }
            }
        }
        return count;
    }
};

// Driver
int main() {
    Solution sol;

    vector<int> nums1 = {1,0,2,0,3};
    cout << sol.countValidSelections(nums1) << endl; // 2

    vector<int> nums2 = {0,1,0};
    cout << sol.countValidSelections(nums2) << endl; // 1

    return 0;
}

