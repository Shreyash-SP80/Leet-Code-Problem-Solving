#include <iostream>
#include <vector>
using namespace std;

/*
1822. Sign of the Product of an Array
-------------------------------------
We are given an integer array nums. We need to return the sign of the product of all elements.

The sign function:
- Returns 1 if product > 0
- Returns -1 if product < 0
- Returns 0 if product == 0
*/

/*
# Intuition
- Multiplying all numbers directly may cause overflow.
- Instead, only the *sign* matters:
  - If any number is 0 → product = 0.
  - Count how many negatives are in the array.
    - If negatives are even → product is positive → return 1.
    - If negatives are odd → product is negative → return -1.

# Approach
1. Initialize `negCount = 0`.
2. Traverse array:
   - If element == 0 → return 0.
   - If element < 0 → increment `negCount`.
3. After loop:
   - If negCount is even → return 1.
   - Else → return -1.

# Complexity
- Time: O(n), we check each element once.
- Space: O(1), only a counter is used.
*/



class Solution {
public:
    int arraySign(vector<int>& nums) {
        int negCount = 0;

        for (int num : nums) {
            if (num == 0) return 0;
            if (num < 0) negCount++;
        }
        return (negCount % 2 == 0) ? 1 : -1;
    }
};

// Driver
int main() {
    Solution sol;

    vector<int> nums1 = {-1,-2,-3,-4,3,2,1};
    cout << sol.arraySign(nums1) << endl; // 1

    vector<int> nums2 = {1,5,0,2,-3};
    cout << sol.arraySign(nums2) << endl; // 0

    vector<int> nums3 = {-1,1,-1,1,-1};
    cout << sol.arraySign(nums3) << endl; // -1

    return 0;
}
