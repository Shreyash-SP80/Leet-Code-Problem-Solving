#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*
2206. Divide Array Into Equal Pairs
-----------------------------------
We are given an array `nums` of size 2 * n.
We need to divide it into n pairs such that:
1. Each element belongs to exactly one pair.
2. Elements in a pair must be equal.

If such division is possible → return true, else false.
*/

/*
# Intuition
- A valid pair requires both numbers to be equal.
- This means **every number in the array must appear an even number of times**.
- If any number occurs an odd number of times → pairing is impossible.

# Approach
1. Count frequency of each number using a hash map.
2. Check each frequency:
   - If any frequency is odd, return false.
3. If all are even, return true.

# Complexity
- Time: O(n) → single pass to count + check.
- Space: O(n) → hash map to store frequencies.
*/


class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int, int> freq;

        // Count frequency of each number
        for (int num : nums) {
            freq[num]++;
        }

        // Check if all frequencies are even
        for (auto &entry : freq) {
            if (entry.second % 2 != 0) {
                return false;
            }
        }
        return true;
    }
};

// Driver
int main() {
    Solution sol;
    
    vector<int> nums1 = {3,2,3,2,2,2};
    cout << boolalpha << sol.divideArray(nums1) << endl; // true

    vector<int> nums2 = {1,2,3,4};
    cout << boolalpha << sol.divideArray(nums2) << endl; // false

    return 0;
}
