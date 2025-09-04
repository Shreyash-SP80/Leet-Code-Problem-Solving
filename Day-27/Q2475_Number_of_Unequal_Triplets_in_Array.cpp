#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*
2475. Number of Unequal Triplets in Array
-----------------------------------------
We need to count the number of triplets (i, j, k) with:
- 0 <= i < j < k < n
- nums[i], nums[j], nums[k] are pairwise distinct.
*/

/*
# Intuition
- Brute force would check all O(n³) triplets, but that's too slow.
- Instead, notice:
  - We just need to count distinct groups, not enumerate them.
  - Suppose we process the array by frequency of unique numbers:
    - Let `f` = frequency of current number.
    - Triplets can be formed by choosing one element from the left group,
      one from the current group (`f`), and one from the right group.
- So for each group:
  - left = count of all previous numbers.
  - right = total size - left - f.
  - Contribution = left * f * right.

# Approach
1. Count frequencies of each number (unordered_map).
2. Iterate through frequency groups:
   - Compute `right = n - left - f`.
   - Add `left * f * right` to result.
   - Update `left += f`.
3. Return result.

# Complexity
- Time: O(n) to build frequency map + O(u) to iterate unique values (u ≤ n).
- Space: O(u) for frequency map.
*/


class Solution {
public:
    int unequalTriplets(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (int num : nums) freq[num]++;

        int n = nums.size();
        int ans = 0, left = 0;

        for (auto &[num, f] : freq) {
            int right = n - left - f;
            ans += left * f * right;
            left += f;
        }
        return ans;
    }
};

// Driver
int main() {
    Solution sol;

    vector<int> nums1 = {4,4,2,4,3};
    cout << sol.unequalTriplets(nums1) << endl; // 3

    vector<int> nums2 = {1,1,1,1,1};
    cout << sol.unequalTriplets(nums2) << endl; // 0

    return 0;
}
