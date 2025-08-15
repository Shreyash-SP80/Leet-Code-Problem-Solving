#include <iostream>
#include <unordered_set>
using namespace std;


/*
217. Contains Duplicate

Given an integer array nums, return true if any value appears at least twice in the array, 
and return false if every element is distinct.

Example 1:
Input: nums = [1, 2, 3, 1]
Output: true
Explanation: The element 1 occurs at the indices 0 and 3.

Example 2:
Input: nums = [1, 2, 3, 4]
Output: false
Explanation: All elements are distinct.

Example 3:
Input: nums = [1, 1, 1, 3, 3, 4, 3, 2, 4, 2]
Output: true

------------------------------------------------------------
Approach:
We can use an unordered_set to store elements as we iterate over the array.
- For each element, check if it already exists in the set.
- If it exists, return true immediately (duplicate found).
- If it does not exist, insert it into the set.
- If the loop completes without finding any duplicates, return false.

This works efficiently because unordered_set provides O(1) average time complexity 
for insertions and lookups.

Time Complexity: O(n) — We go through all n elements once.
Space Complexity: O(n) — In the worst case (all distinct elements), we store all n elements in the set.
------------------------------------------------------------
*/


class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> seen;
        for (int num : nums) {
            if (seen.count(num)) return true; // Duplicate found
            seen.insert(num);
        }
        return false; // No duplicates
    }
};

int main() {
    Solution sol;

    // Test case 1
    vector<int> nums1 = {1, 2, 3, 1};
    cout << "Input: [1, 2, 3, 1]\nOutput: " 
         << (sol.containsDuplicate(nums1) ? "true" : "false") << "\n\n";

    // Test case 2
    vector<int> nums2 = {1, 2, 3, 4};
    cout << "Input: [1, 2, 3, 4]\nOutput: " 
         << (sol.containsDuplicate(nums2) ? "true" : "false") << "\n\n";

    // Test case 3
    vector<int> nums3 = {1, 1, 1, 3, 3, 4, 3, 2, 4, 2};
    cout << "Input: [1, 1, 1, 3, 3, 4, 3, 2, 4, 2]\nOutput: " 
         << (sol.containsDuplicate(nums3) ? "true" : "false") << "\n";

    return 0;
}
