#include <iostream>
#include <vector>
using namespace std;


/*
========================================================================================
✅ QUESTION: LeetCode 26 – Remove Duplicates from Sorted Array
🔗 Link: https://leetcode.com/problems/remove-duplicates-from-sorted-array/

📄 Description:
Given a sorted array `nums` in non-decreasing order, remove the duplicates **in-place**
such that each unique element appears only once. The relative order should be maintained.
        
Your task:
1. Modify the array in-place so the first `k` elements contain only the unique values.
2. Return `k` – the number of unique elements.
3. The remaining elements beyond `k` don’t matter.

📌 Example 1:
Input: nums = [1,1,2]
Output: 2, nums = [1,2,_]
Explanation: First two elements are unique: [1, 2]

📌 Example 2:
Input: nums = [0,0,1,1,1,2,2,3,3,4]
Output: 5, nums = [0,1,2,3,4,_,_,_,_,_]
Explanation: First five elements are unique: [0,1,2,3,4]

📋 Constraints:
• 1 <= nums.length <= 3 × 10^4
• -100 <= nums[i] <= 100
• nums is sorted in non-decreasing order

========================================================================================

🔍 APPROACH: Two-Pointer Technique

➤ Use two pointers:
  • `i`: scans the array.
  • `j`: tracks the position of the last unique element found.

➤ Traverse the array starting from index 1.
➤ If nums[i] != nums[j], it means a new unique element is found.
 ➤ Move `j` forward and set nums[j] = nums[i].

    ✅ Time Complexity: O(n)
    ✅ Space Complexity: O(1)

        ----------------------------------------------------------------------------------------
🔗 REFERENCES:
    • Problem link: https://leetcode.com/problems/remove-duplicates-from-sorted-array/
    • Big-O reference: https://www.bigocheatsheet.com/
========================================================================================
*/


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        // Handle edge case of empty input
        if (nums.empty()) return 0;

        int j = 0; // Pointer for position of unique elements

        // Traverse from 1 to end of array
        for (int i = 1; i < nums.size(); i++) {
            if (nums[j] != nums[i]) {
                j++; // Move to next position
                nums[j] = nums[i]; // Assign unique value to correct position
            }
        }

        return j + 1; // Number of unique elements
    }
};

// Example usage
int main() {
    Solution sol;

    vector<int> nums = {0,0,1,1,1,2,2,3,3,4};

    int k = sol.removeDuplicates(nums);

    cout << "Number of unique elements: " << k << endl;
    cout << "Modified array: ";
    for (int i = 0; i < k; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}
