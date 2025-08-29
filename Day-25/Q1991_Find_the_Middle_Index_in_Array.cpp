#include <iostream>
#include <vector>
#include <numeric>
using namespace std;


/*
1991. Find the Middle Index in Array
------------------------------------
A middleIndex is defined such that:
sum(nums[0 ... i-1]) == sum(nums[i+1 ... n-1]).

If no such index exists, return -1.
If multiple exist, return the leftmost one.
*/

/*
# Intuition
- We want the first index where **left sum = right sum**.
- Instead of recomputing sums repeatedly:
  - First, compute the total sum of the array.
  - As we iterate, we maintain a running left sum.
  - Right sum = totalSum - leftSum - nums[i].
- If leftSum == rightSum → we found the middle index.

# Approach
1. Compute total sum of `nums`.
2. Traverse `nums`:
   - At index `i`, compute right sum = totalSum - leftSum - nums[i].
   - If leftSum == rightSum, return `i`.
   - Otherwise, update leftSum += nums[i].
3. If no index is found, return -1.

# Complexity
- Time: O(n) (single pass after total sum).
- Space: O(1) (constant extra variables).
*/


class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        int leftSum = 0;

        for (int i = 0; i < nums.size(); i++) {
            int rightSum = totalSum - leftSum - nums[i];
            if (leftSum == rightSum) return i;
            leftSum += nums[i];
        }
        return -1;
    }
};

// Driver
int main() {
    Solution sol;
    vector<int> nums1 = {2,3,-1,8,4};
    cout << sol.findMiddleIndex(nums1) << endl; // 3

    vector<int> nums2 = {1,-1,4};
    cout << sol.findMiddleIndex(nums2) << endl; // 2

    vector<int> nums3 = {2,5};
    cout << sol.findMiddleIndex(nums3) << endl; // -1

    return 0;
}
