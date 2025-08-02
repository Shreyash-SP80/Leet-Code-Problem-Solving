#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*
====================================================================
🧾 Problem: 3046. Split the Array
🔗 Source: https://leetcode.com/problems/split-the-array/
💬 Difficulty: Easy
====================================================================

📜 Description:
You are given an integer array `nums` of even length.

You have to split the array into two parts `nums1` and `nums2` such that:
    - nums1.length == nums2.length == nums.length / 2
    - nums1 contains only distinct elements.
    - nums2 contains only distinct elements.

Return `true` if it is possible to split the array into such two parts, otherwise return `false`.

====================================================================

📌 Constraints:
- 2 <= nums.length <= 1000
- nums.length is even
- 1 <= nums[i] <= 1000

====================================================================

🔍 Example 1:
Input: nums = [1, 1, 2, 2, 3, 4]
Output: true
Explanation:
nums1 = [1, 2, 3], nums2 = [1, 2, 4] — both halves are distinct and of equal size.

🔍 Example 2:
Input: nums = [1, 1, 1, 1]
Output: false
Explanation:
nums1 = [1, 1], nums2 = [1, 1] — both contain duplicates.

====================================================================

💡 Approach:
To satisfy the condition that both halves contain only distinct elements, 
no number in the array should appear more than 2 times.

Reason:
- Each number can go at most once into nums1 and once into nums2.
- If a number appears 3 or more times, it must be duplicated in one half.

✅ So, count the frequency of each number.
   - If any number occurs more than 2 times → return false.
   - Otherwise → return true.

====================================================================

🧠 Time Complexity: O(n)
🧠 Space Complexity: O(n)

====================================================================
*/

class Solution {
public:
    bool isPossibleToSplit(vector<int>& nums) {
        unordered_map<int, int> freq;

        // Count frequency of each number
        for (int num : nums) {
            freq[num]++;
            // If any number appears more than 2 times, splitting is not possible
            if (freq[num] > 2) {
                return false;
            }
        }

        // All elements appear at most twice — valid split possible
        return true;
    }
};

// Example usage
int main() {
    Solution sol;
    vector<int> nums1 = {1, 1, 2, 2, 3, 4};
    vector<int> nums2 = {1, 1, 1, 1};

    cout << boolalpha << sol.isPossibleToSplit(nums1) << endl;  // Output: true
    cout << boolalpha << sol.isPossibleToSplit(nums2) << endl;  // Output: false

    return 0;
}
