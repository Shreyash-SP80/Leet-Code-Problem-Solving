
#include <iostream>
#include <vector>
using namespace std;

/*
3314. Construct the Minimum Bitwise Array I
--------------------------------------------
We are given an array nums consisting of n prime integers.  
We need to construct ans such that:
    ans[i] OR (ans[i] + 1) == nums[i]

Additionally:
- ans[i] should be minimized.
- If not possible, set ans[i] = -1.
*/

/*
# Intuition
- For a number `num`, we want to find the smallest `x` such that:
      x | (x+1) == num
- Example: num = 7 → x=3 works (3|4=7).
- Observation:
  - `num` must have at least 2 set bits for a valid answer (except num=2, impossible).
  - The solution is `num - highestPowerOf2(num)`.
    - Because removing the highest set bit makes `(x | x+1)` equal to num.
- Special case:
  - If num = 2 → no solution → return -1.

# Approach
1. For each `num` in nums:
   - If num == 2 → push -1.
   - Else compute `num - leadingOne(num)`.
2. Return result array.

# Complexity
- Time: O(n * log(num)) due to bit shifting.
- Space: O(1) extra space, O(n) for answer.
*/


class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;
        ans.reserve(nums.size());

        for (int num : nums) {
            if (num == 2) {
                ans.push_back(-1); 
            } else {
                ans.push_back(num - getLeadingOne(num));
            }
        }
        return ans;
    }

private:
    int getLeadingOne(int num) {
        int leadingOne = 1;
        while (num & leadingOne) {
            leadingOne <<= 1;
        }
        return leadingOne >> 1; // highest set bit
    }
};

// Driver
int main() {
    Solution sol;

    vector<int> nums1 = {2,3,5,7};
    for (int x : sol.minBitwiseArray(nums1)) cout << x << " "; // -1 1 4 3
    cout << endl;

    vector<int> nums2 = {11,13,31};
    for (int x : sol.minBitwiseArray(nums2)) cout << x << " "; // 9 12 15
    cout << endl;

    return 0;
}

